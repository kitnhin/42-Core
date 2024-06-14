# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 17:53:46 by cheelim           #+#    #+#              #
#    Updated: 2024/06/13 21:05:56 by cheelim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
ft_printchar.c ft_printf.c ft_printhex.c ft_printint.c \
ft_printptr.c ft_printstr.c ft_printui.c

OBJS = $(SRCS:.c=.o)


NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

compile: all
	cc $(FLAGS) main.c -l $(NAME)

.PHONY : all clean flcean re bonus