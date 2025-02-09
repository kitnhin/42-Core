# include <iostream>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fstream>
# include <stdexcept>
# include <map>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string parse_resources(string path)
{
	string res;
	string buffer;
	std::ifstream infile(path);
	if(!infile.is_open())
		return "";
	while(getline(infile, buffer))
		res += buffer;
	return res;
}

string	get_file_type(string path)
{
	size_t dotpos = path.find_first_of(".", 1);
	if(dotpos == std::string::npos)
		return("plain/text");
	string type = path.substr(dotpos + 1, path.length() - dotpos - 1);

	if(type == "html")
		return "text/html"; //cannot reverse the order if not will have some weird behaviour
	else if (type == "css")
		return "text/css";
	else if (type == "js")
        return "text/javascript";
    else if (type == "jpeg" || type == "jpg")
        return "image/jpeg";
    else if (type == "png")
        return "image/png";
    else if (type == "gif")
        return "image/gif";
    else if (type == "txt")
        return "text/plain";
	else
		return "text/plain";
}

void	print(string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		string print = std::to_string(static_cast<int>(str[i])) + "\n";
		write(2, print.c_str(), print.length());
	}
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    (void)envp;
	string input;
	string total_body;

	// //temp for testing

	// total_body = "------WebKitFormBoundary0aMijw4giNtlL1DE\r\n"
    //          "Content-Disposition: form-data; name=\"file\"; filename=\"test.txt\"\r\n"
    //          "Content-Type: text/plain\r\n\r\n"
    //          "123\r\n"
    //          "------WebKitFormBoundary0aMijw4giNtlL1DE--\r\n";

	while(getline(cin, input))
		total_body += input + "\n";

	// total_body += "\n";

	// write(2, total_body.c_str(), total_body.length());


    // Output content
    // std::cout << "Hello, this is a simple CGI response!\n";

	//boundary
	size_t pos = 0;
	size_t boundary_delim = total_body.find_first_of("\r\n", pos);
	string boundary = total_body.substr(pos, boundary_delim - pos);
	pos = boundary_delim + 2;
	//cout << "boundary: " << boundary << endl;

	//header fields
	std::map<string,string> header_fields;
	while(pos < total_body.length() && total_body[pos] != '\r')
	{
		size_t colon_pos = total_body.find_first_of(":" , pos);
		string field = total_body.substr(pos, colon_pos - pos);
		string len = std::to_string(field.length());
		pos = colon_pos + 2;
		size_t slash_r_pos = total_body.find_first_of("\r", pos);
		string value = total_body.substr(pos, slash_r_pos - pos);
		pos = slash_r_pos + 2;
		header_fields[field] = value;
	}

	string field_stuff;
	for (std::map<std::string, std::string>::iterator it = header_fields.begin(); it != header_fields.end(); ++it)
       field_stuff += it->first + ":" + it->second + "\n";

	//get filename
	std::map<string, string>::iterator it = header_fields.find("Content-Disposition");
	string value = it->second;
	string print2 = "value: " + value;
	size_t filename_pos = value.find("filename");
	size_t open_quote_pos = value.find_first_of("\"", filename_pos);
	size_t close_quote_pos = value.find_first_of("\"", open_quote_pos + 1);
	string filename = value.substr(open_quote_pos + 1, close_quote_pos - open_quote_pos - 1);
	//write(2, filename.c_str(), filename.length());

	//get the actual contents
	pos += 2;
	size_t contents_delim = total_body.find_first_of("\r", pos);
	string contents = total_body.substr(pos, contents_delim - pos);

	//insert stuff inside file
	string file_name_and_path = "./public_files/" + filename; 
	std::ofstream newfile(file_name_and_path);
	if(!newfile.is_open())
		return 1;
	newfile << contents;
	newfile.close();

	//send status message
	string msg;
	// msg = "fields: " + field_stuff + "\n\nfilename: " + filename;

	msg += "<!DOCTYPE html>";
	msg += "<html>";
	msg += "<head>";
	msg += "</head>";
	msg += "<body>";
	msg += "<center><h1> Successfully uploaded file! </h1></center>";
	msg += "</body>";
	msg += "</html>";


	// Output HTTP headers
    std::cout << "HTTP/1.1 200 OK\r\n";                   // HTTP version and status code
    std::cout << "Content-Type: text/html\r\n";          // Content type of the response
    std::cout << "Connection: keep-alive\r\n";                // Close connection after response
    std::cout << "Content-Length: " << msg.length() << "\r\n"; // Length of the response body (update as needed)
    std::cout << "\r\n";                            // End of headers
	std::cout << msg << endl;

	return 0;
}

