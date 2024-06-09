# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 20:06:11 by cheelim           #+#    #+#              #
#    Updated: 2024/06/09 21:22:03 by cheelim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_strchr.c ft_memchr.c ft_strrchr.c ft_itoa.c ft_substr.c \
ft_toupper.c ft_tolower.c ft_strncmp.c ft_atoi.c \
ft_strdup.c ft_calloc.c ft_strnstr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_memcmp.c

OBJS = $(SRCS:.c=.o)

BONUS = \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
ft_lstmap.c

BONUSOBJS = $(BONUS:.c=.o)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS) $(BONUSOBJS) 
	ar rcs $(NAME) $(BONUSOBJS) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(BONUSOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean flcean re bonus