SRCS = \
rotate.c main.c rev_rotate.c swap.c utils.c \
sort.c split.c push.c utils2.c inits.c \
utils3.c int_array.c sort_100_utils.c \
sort_500_utils.c costs.c

OBJ = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

SAN = -g -fsanitize=address

CFLAGS = 

LIB = libft.a

LIBDIR = libft

all : $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(OBJ) -lft -L. -o $(NAME) libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) : 
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .


leak: $(SRCS)
	@$(CC) $(CFLAGS) $(SAN) $(SRCS) -lft -L. -o $(NAME)_leak_check libft.a

clean :
	@rm -f ${OBJ}
	@rm -f $(LIB)
	$(MAKE) -C $(LIBDIR) clean

fclean : clean
	@rm -f $(NAME)

re : fclean all

test:
	make re
	cp push_swap Push-Swap-Tester/
	
.PHONY: all clean fclean re leak