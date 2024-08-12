SRCS = \
main.c init.c philo_routine.c

BONUS_SRCS = \


OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

NAME = philo

BONUS_NAME =

CC = gcc

CFLAGS = -pthread

#COLORS!
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@echo "${GREEN}compiling philo...${NC}"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "${GREEN}compile philo success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	@echo "${GREEN}cleaning...${NC}"
	@rm -f ${OBJ}
	@rm -f ${BONUS_OBJ}
	@echo "${GREEN}clean success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

$(BONUS_NAME) : $(BONUS_OBJ) $(LIB)
	@echo "${GREEN}compiling bonus...${NC}"
	@$(CC) $(BONUS_OBJ) -lft -L. -o bonus libft.a
	@echo "${GREEN}compile bonus success!!${NC}"
	@echo "${GREEN}------------------------------${NC}"

bonus : fclean $(BONUS_NAME)

test: re
	cd LazyPhilosophersTester && ./test.sh ../philo

.PHONY: all clean fclean re leak bonus