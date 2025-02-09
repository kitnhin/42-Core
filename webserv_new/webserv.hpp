#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <map>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h> // for last modified file date in autoindex
#include <cctype>
#include <cstdlib>
#include <sys/wait.h>
#include <algorithm>
#include <sstream>

//for socket structs and functions
#include <netdb.h> 
#include <sys/socket.h>
#include <poll.h>

//class headers
#include "Request.hpp"
#include "Config.hpp"
#include "Server.hpp"
#include "HTTP.hpp"
#include "Socket.hpp"
#include "Location.hpp"
#include "Response.hpp"
#include "Cgi.hpp"
#include "Autoindex.hpp"

using std::string;
using std::cout;
using std::endl;

//macros
#define LISTEN_BACKLOG 1000

#endif