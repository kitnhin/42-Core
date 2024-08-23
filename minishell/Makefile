SRCS = \
main.c rl_redisplay_line.c lexer.c expansion.c \
execve.c cd.c echo.c env.c lexer2.c pwd.c

BONUS_SRCS = \
pipex_bonus.c utils_bonus.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

NAME = minishell

BONUS_NAME = pipex_bonus

CC = gcc

CFLAGS =

READ = -lreadline 

LIB = libft.a

LIBDIR = libft

#COLORS!
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "${GREEN}compiling minishell...${NC}"
	@$(CC) $(OBJ) -lft -L. -o $(NAME) libft.a ${READ} 
	@echo "${GREEN}compile minishell success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) :
	@echo "${GREEN}compiling libft...${NC}"
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .
	@echo "${GREEN}compile libft success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

clean :
	@echo "${GREEN}cleaning...${NC}"
	@rm -f ${OBJ}
	@rm -f ${BONUS_OBJ}
	@rm -f $(LIB)
	@$(MAKE) -C $(LIBDIR) clean
	@echo "${GREEN}clean success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

$(BONUS_NAME) : $(BONUS_OBJ) $(LIB)
	@echo "${GREEN}compiling bonus...${NC}"
	@$(CC) $(BONUS_OBJ) -lft -L. -o pipex libft.a
	@echo "${GREEN}compile bonus success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

bonus : fclean $(BONUS_NAME)

testlex:
	gcc expansion.c lexer.c libft.a

.PHONY: all clean fclean re leak bonus