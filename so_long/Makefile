SRCS = make_map.c player.c check_map.c main.c keys.c animation.c enemy.c

OBJ = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

SAN = -g -fsanitize=address

CFLAGS = 

all : $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L/usr/X11/lib -lX11 -lXext libft.a

%.o: %.c
		@gcc $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
		@rm -f ${OBJ}

fclean : clean
		@rm -f $(NAME)

re : fclean all

mapp : 
	gcc make_map.c -lft -L. -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext libft.a

testkey:
	gcc test_key.c -L. -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext

key:
	gcc keys.c -L. -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext libft.a

.PHONY: all clean fclean re