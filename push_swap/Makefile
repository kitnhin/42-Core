SRCS = \
rotate.c main.c rev_rotate.c swap.c utils.c \
sort.c push.c utils2.c inits.c \
utils3.c s_index.c sort_100_utils.c \
sort_500_utils.c costs.c validate_input.c \
print.c

BONUS_SRCS = \
rotate.c checker.c rev_rotate.c swap.c utils.c \
sort.c push.c utils2.c inits.c \
utils3.c s_index.c sort_100_utils.c \
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

#COLORS!
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "${GREEN}compiling push_swap...${NC}"
	@$(CC) $(OBJ) -lft -L. -o $(NAME) libft.a
	@echo "${GREEN}compile push_swap success!!${NC}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) :
	@echo "${GREEN}compiling libft...${NC}"
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .
	@echo "${GREEN}compile libft success!!${NC}"

$(BONUS_NAME) : $(BONUS_OBJ) $(LIB)
	@echo "${GREEN}compiling checker...${NC}"
	@$(CC) $(BONUS_OBJ) -lft -L. -o $(BONUS_NAME) libft.a
	@echo "${GREEN}compile checker success!!${NC}"

bonus : $(BONUS_NAME)

clean :
	@echo "${GREEN}cleaning...${NC}"
	@rm -f ${OBJ}
	@rm -f $(LIB)
	@$(MAKE) -C $(LIBDIR) clean
	@echo "${GREEN}clean success!!${NC}"

fclean : clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

test: re
	@cp push_swap Push-Swap-Tester
	@cd Push-Swap-Tester && bash push_swap_test.sh
	
testb: fclean bonus
	@cp checker Push-Swap-Tester
	@cd Push-Swap-Tester && bash push_swap_test.sh -b

.PHONY: all clean fclean re leak