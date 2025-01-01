SRCS = \
main.cpp RPN.cpp

OBJS = $(SRCS:.c=.o)

NAME = RPN

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

${NAME}: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all : ${NAME}

clean :
	rm -rf ${NAME}

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean flcean re bonus