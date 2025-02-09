#include "Autoindex.hpp"
#include "webserv.hpp"

static std::string my_itoa(size_t i)
{
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	return s;
}

string	autoindex::get_file_size(size_t filesize)
{
	string	res;
	size_t	num;
	string	unit;
	if(filesize > 1e9)
	{
		num = filesize / 1e9;
		unit = "GB";
	}
	else if (filesize > 1e6)
	{
		num = filesize / 1e6;
		unit = "MB";
	}
	else if(filesize > 1e3)
	{
		num = filesize / 1e3;
		unit = "KB";
	}
	else
	{
		num = filesize;
		unit = "B";
	}
	res = my_itoa(num) + unit;
	return res;
}

void	autoindex::generate_autoindex_page_first_part(string &response_body, string dir_name)
{
	response_body += "<!DOCTYPE html>";
	response_body += "<html>";
	response_body += "<head>";
	response_body += "<title> Index of " + dir_name + "</title>";
	response_body += "<style>"; // shall use chatgpt styling for now fk i havent done css in so long, can change later
	response_body += "body {font-family: Arial, sans-serif; background-color: #f4f4f4; padding: 20px; }";
	response_body += "h1 {text-align: center;}";
	response_body += ".dls {margin-top: 20px; padding: 10px; background-color: white; border-radius: 5px; border: 1px solid #ccc; }";
	response_body += ".row {display: flex; justify-content: space-between; padding: 8px;}"; //display flex is the box-ish layout
	response_body += ".fn {font-weight: bold;}";
	response_body += ".lm  {color: #777;}";
	response_body += ".size {color: #777;}";
	response_body += "</style>";
	response_body += "</head>";
	response_body += "<body>";	
	response_body += "<h1>Index of " + dir_name + "</h1>";
	response_body += "<div class = 'dls'>";
	response_body += "<div class = 'row'>";
	response_body += "<div class = 'fn'> Filename </div>";
	response_body += "<div class = 'lm'> Last Modified </div>";
	response_body += "<div class = 'size'> File size </div>";
	response_body += "</div><hr />"; //hr / inserts a horizontal line
}

void	autoindex::put_file_name(string &response_body, string filename, DIR *checkdir)
{
	response_body += "<div class = 'fn'>";
	if(checkdir)
		response_body += "<a href = '" + filename + "/'>" + filename + "/</a>"; // do not put full path + name (chatgpt scammed), cuz a
	else	
		response_body += "<a href = '" + filename + "'>" + filename + "</a>";
	response_body += "</div>";
}

void	autoindex::put_last_modified_time(string &response_body, struct stat &file_info)
{
	char		buffer[100];
	struct tm	*tm_info;	

	memset(buffer, 0, sizeof(buffer));
	tm_info = localtime(&file_info.st_mtime); // converts the time stat to a time struct (the original value is time in seconds, need to conver that into struct wif like year-month-day or smth)
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info); //converts the time struct into a string
	response_body += "<div class = 'lm'>";
	response_body += buffer;
	response_body += "</div>";
}

void	autoindex::put_size(string &response_body, struct stat &file_info, DIR *checkdir)
{
	response_body += "<div class = 'size'>";
	if(checkdir)
		response_body += "-"; //ignore dir size since its not actual size (acc to chatgpt its the "space in metadata", gonna research more if i have time)
	else
		response_body += get_file_size(file_info.st_size);
	response_body += "</div>";
}


void	autoindex::get_file_info(struct stat &file_info, string path_and_name)
{
	if(stat(path_and_name.c_str(), &file_info) != 0) //gets file stats
		throw std::runtime_error("Error : (autoindex) cant get file stat");
}

void	autoindex::generate_autoindex_page_second_part(string &response_body, DIR *dir, string path)
{
	struct dirent	*entry;
	struct stat		file_info;

	while((entry = readdir(dir)) != NULL)
	{
		string filename = entry->d_name;
		if(filename != "." && filename != "..")
		{
			string path_and_name = path + filename; //for example: ./test/example.html   <- ./test/ is the path, example.html is the file (ms substringed out the '.' i had no idea how it worked for him mine failed bad)
			DIR *checkdir = opendir(path_and_name.c_str()); //checks if the thing we just read is a dir ornot
			
			//get the size and the last modified date
			get_file_info(file_info, path_and_name);

			//start putting in stuff
			response_body += "<div class = 'row'>";
		
			//put file
			put_file_name(response_body, filename, checkdir);

			//put last modified data (rip just realised ppl use tm aiya i used lm ealier dy i lazy change la)
			put_last_modified_time(response_body, file_info);

			//put the size
			put_size(response_body, file_info, checkdir);
			
			//finally, cleanup and close everything
			if(checkdir)
				closedir(checkdir);
			response_body += "</div>"; // close row div
		}
	}
	//closing html codes
	response_body += "</div>";
	response_body += "</body>";
	response_body += "</html>";
}
