# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:38:36 by jiwchoi           #+#    #+#              #
#    Updated: 2021/07/07 19:46:05 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= minishell

CC			= gcc
#CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

LIBFT_DIR	= ./libft
LIBFT_FILE	= libft.a

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

SRC			= shell.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

#INC_READLINE = -lreadline -L /Users/jiwchoi/.brew/opt/readline/lib -I/Users/jiwchoi/.brew/opt/readline/include

$(TARGET) : $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) -o $(TARGET) $(OBJS) -I $(INCS_DIR) -L $(LIBFT_DIR) -lft -lreadline -L /Users/jiwchoi/.brew/opt/readline/lib -I/Users/jiwchoi/.brew/opt/readline/include

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@ -I/Users/jiwchoi/.brew/opt/readline/include

all : $(TARGET)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_DIR)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(TARGET)

re : clean all

bonus :

.PHONY : all clean fclean re bonus
