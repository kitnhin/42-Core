SRCS = \
Animal.cpp Cat.cpp Dog.cpp main.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp

OBJS = $(SRCS:.c=.o)

NAME = Animal

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

${NAME}: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all : ${NAME}

clean :
	rm -rf ${NAME}

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean flcean re bonus