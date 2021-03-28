# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:58:00 by jiwchoi           #+#    #+#              #
#    Updated: 2021/03/28 19:09:34 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS		=  

OBJS		= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

.PHONY : bonus all clean fclean re
