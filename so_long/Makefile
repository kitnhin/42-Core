SRCS = make_map.c player.c check_map.c main.c keys.c animation.c enemy.c inits.c

OBJ = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

SAN = -g -fsanitize=address

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L/usr/X11/lib -lX11 -lXext libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

leak: $(SRCS)
	@$(CC) $(CFLAGS) $(SAN) $(SRCS) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)_leak_check -L/usr/X11/lib -lX11 -lXext libft.a

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

pics:
	gcc display_pics.c -L. -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext libft.a

.PHONY: all clean fclean re leak