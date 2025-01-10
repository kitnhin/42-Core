#include "Cgi.hpp"

Cgi::Cgi() {}

Cgi::~Cgi() {}

char	**Cgi::config_env(Request &request)
{
	char **env = (char **)malloc(sizeof(char *) * request.get_header_fields().size() * 5);

	env[0] = strdup((string("REQUEST_METHOD=") + request.get_method()).c_str());
	env[1] = strdup((string("ROUTE=") + request.get_target()).c_str());
	env[2] = strdup((string("SERVER_PROTOCOL=") + request.get_http_ver()).c_str());
	size_t j = 3;

	for(std::map<string, string>::iterator it = request.get_header_fields().begin(); it != request.get_header_fields().end(); it++)
	{
		string field = it->first;
		std::replace(field.begin(), field.end(), '-', '_');
		for(size_t i = 0; i < field.size(); i++)
			field[i] = std::toupper(field[i]);
		env[j++] = strdup((field + "=" + it->second).c_str());
		setenv(field.c_str(), it->second.c_str(), 1); //1 means overwrite existing ones
	}
	env[j] = NULL;
	return env;
}

string	Cgi::get_cgi_output(int pipefd)
{
	char buffer[1000];
	string res;
	int bytesread;

	while((bytesread = read(pipefd, buffer, 1000) > 0))
		res += buffer;

	return res;
}

void	Cgi::Cgi_main(Request &request, Response &response, Location &location, Server &server)
{
	string cgi_path = "." + location.get_cgi_pass();
	pid_t pid;
	int pipefd_input[2];
	int pipefd_output[2];
	int exit_status;
	char *argv[] = {(char *)cgi_path.c_str(), NULL};
	if(pipe(pipefd_input) == -1 || pipe(pipefd_output) == -1)
		response.handle_error(request, "500", server);
	else
	{
		pid = fork();
		if(pid == 0) //child process
		{
			close(pipefd_input[0]);
			close(pipefd_output[0]);
			close(pipefd_output[1]);
			write(pipefd_input[1], request.get_body().c_str(), request.get_body().size());
			close(pipefd_input[1]);
			exit(0);
		}
		waitpid(pid, &exit_status,0);

		pid = fork();
		if(pid == 0)
		{
			dup2(pipefd_input[0], STDIN_FILENO);
			dup2(pipefd_output[1], STDOUT_FILENO);
			close(pipefd_input[0]);
			close(pipefd_input[1]);
			close(pipefd_output[0]);
			close(pipefd_output[1]);
			char **env = this->config_env(request);
			if(execve(cgi_path.c_str(), argv, env) == -1)
			{
				perror("execve");
				exit(-1);
			}
			exit(0);
		}
		close(pipefd_input[0]);
		close(pipefd_input[1]);
		close(pipefd_output[1]);
		if(exit_status != 0)
		{
			cout << "cgi_path: " << cgi_path << endl;
			response.handle_error(request, "500", server);
		}
		else
		{
			response.set_response(get_cgi_output(pipefd_output[0]));
		}
		close(pipefd_output[0]);
	}
}