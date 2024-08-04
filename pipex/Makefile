SRCS = \
pipex.c

BONUS_SRCS = \

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

NAME = pipex

BONUS_NAME = 

CC = gcc

CFLAGS =

LIB = libft.a

LIBDIR = libft

#COLORS!
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "${GREEN}compiling pipex...${NC}"
	@$(CC) $(OBJ) -lft -L. -o $(NAME) libft.a
	@echo "${GREEN}compile pipex success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) :
	@echo "${GREEN}compiling libft...${NC}"
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .
	@echo "${GREEN}compile libft success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

$(BONUS_NAME) : $(BONUS_OBJ) $(LIB)
	@echo "${GREEN}compiling checker...${NC}"
	@$(CC) $(BONUS_OBJ) -lft -L. -o $(BONUS_NAME) libft.a
	@echo "${GREEN}compile checker success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

bonus : $(BONUS_NAME)

clean :
	@echo "${GREEN}cleaning...${NC}"
	@rm -f ${OBJ}
	@rm -f $(LIB)
	@$(MAKE) -C $(LIBDIR) clean
	@echo "${GREEN}clean success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

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