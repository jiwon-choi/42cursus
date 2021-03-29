# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:58:00 by jiwchoi           #+#    #+#              #
#    Updated: 2021/03/29 16:07:01 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME		= miniRT

DIR_HEADERS	= ./includes/
DIR_SRCS	= ./srcs/

LIB_FILE	= libft.a \
			  libmlx.dylib \
			  libmlx.a

SRC			= main.c \
			  get_next_line.c

SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	make -C ./libft
	make -C ./minilibx_mms
	make -C ./minilibx_opengl
	cp ./libft/libft.a libft.a
	cp ./minilibx_mms/libmlx.dylib libmlx.dylib
	cp ./minilibx_opengl/libmlx.a libmlx.a
	$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBMLX) $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	make fclean -C ./libft
	make clean -C ./minilibx_mms
	make clean -C ./minilibx_opengl
	$(RM) libft.a libmlx.dylib libmlx.a
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
