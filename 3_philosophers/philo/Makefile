# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 19:02:09 by jiwchoi           #+#    #+#              #
#    Updated: 2021/09/29 19:17:04 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= philo

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra # -fsanitize=address
RM			= rm -rf

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

SRC			= init.c \
			  main.c \
			  monitor.c \
			  routine.c \
			  run.c \
			  utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -I $(INCS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

all : $(TARGET)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(TARGET)

re : clean all

bonus : 

.PHONY : all clean fclean re bonus
