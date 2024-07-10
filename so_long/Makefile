SRCS = make_map.c player.c check_map.c

OBJ = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

SAN = -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L/usr/X11/lib -lX11 -lXext libft.a

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

clean :
		@rm -f ${OBJ}

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re