SRCS = \
Config.cpp CustomException.cpp main.cpp HTTP.cpp Server.cpp Socket.cpp \
Request.cpp Location.cpp Response.cpp Cgi.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = webserv

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

${NAME}: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all: ${NAME} run_cgi_makefile

run_cgi_makefile:
	cd cgi && $(MAKE) -C cgi

clean:
	rm -rf ${NAME}

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re run_cgi_makefile
