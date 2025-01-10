# include <iostream>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fstream>
# include <stdexcept>
# include <iomanip>
# include <sstream>

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

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    (void)envp;
	string input;
	string total_body;
	while(getline(cin, input))
		total_body += input;

    // Output HTTP headers
    std::cout << "HTTP/1.1 200 OK\r\n";                   // HTTP version and status code
    std::cout << "Content-Type: text/plain\r\n";          // Content type of the response
    std::cout << "Connection: keep-alive\r\n";                // Close connection after response
    std::cout << "Content-Length: " << total_body.length() << "\r\n";               // Length of the response body (update as needed)
    std::cout << "\r\n";                                 // End of headers

    // Output content
    // std::cout << "Hello, this is a simple CGI response!\n";
	cout << total_body << endl;
	
}

