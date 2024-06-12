# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 17:53:46 by cheelim           #+#    #+#              #
#    Updated: 2024/06/12 15:41:52 by ethanlim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
ft_printchar.c ft_printf.c ft_printint.c ft_printstr.c \
ft_printui.c

OBJS = $(SRCS:.c=.o)


NAME = libftprintf.a

CC = gcc

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

.PHONY : all clean flcean re bonus