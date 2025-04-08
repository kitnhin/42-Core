SRCS = \
AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp

OBJS = $(SRCS:.c=.o)

NAME = Materia

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

r: $(NAME)
	./Materia