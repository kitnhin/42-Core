SRCS = \
rotate.c main.c rev_rotate.c swap.c utils.c \
sort.c split.c push.c utils2.c inits.c \
utils3.c int_array.c sort_100_utils.c \
sort_500_utils.c costs.c validate_input.c \
print.c

BONUS_SRCS = \
rotate.c checker.c rev_rotate.c swap.c utils.c \
sort.c split.c push.c utils2.c inits.c \
utils3.c int_array.c sort_100_utils.c \
sort_500_utils.c costs.c validate_input.c \
print.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

NAME = push_swap

BONUS_NAME = checker

CC = gcc

SAN = -g -fsanitize=address

CFLAGS = -Wall -Werror -Wextra

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

$(BONUS_NAME) : $(BONUS_OBJ) $(LIB)
	@$(CC) $(BONUS_OBJ) -lft -L. -o $(BONUS_NAME) libft.a

bonus : $(BONUS_NAME)

clean :
	@rm -f ${OBJ}
	@rm -f $(LIB)
	$(MAKE) -C $(LIBDIR) clean

fclean : clean
	@rm -f $(NAME) $(BONUS_NAME)

re : fclean all

test: re
	@cp push_swap Push-Swap-Tester
	@cd Push-Swap-Tester && bash push_swap_test.sh
	
testb: fclean bonus
	@cp checker Push-Swap-Tester
	
.PHONY: all clean fclean re leak