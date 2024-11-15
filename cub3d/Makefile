SRCS = \
main.c parsing1.c parsing_utils.c utils.c checkmap.c background.c \
player1.c print.c raycast.c movement.c draw.c handle.c player2.c handle_fts.c \
utils2.c

TESTIMG = testimg.c

OBJ = $(SRCS:.c=.o)

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = libft.a

LIBDIR = libft

all : $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(OBJ) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L/usr/X11/lib -lX11 -lXext libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) : 
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .

clean :
	@rm -f ${OBJ}
	@rm -f $(LIB)
	$(MAKE) -C $(LIBDIR) clean

fclean : clean
	@rm -f $(NAME)

testimg: $(OBJ) $(LIB)
	@$(CC) $(TESTIMG) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L/usr/X11/lib -lX11 -lXext libft.a

test: $(OBJ) $(LIB)
	@$(CC) test.c -lft -L. -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext libft.a

re : fclean all



.PHONY: all clean fclean re leak