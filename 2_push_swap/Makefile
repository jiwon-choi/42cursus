# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 19:02:09 by jiwchoi           #+#    #+#              #
#    Updated: 2021/06/21 15:35:29 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

SRC			= check.c \
			  ft_atoi.c \
			  main.c \
			  math.c \
			  op_push.c \
			  op_reverse_rotate.c \
			  op_rotate.c \
			  op_swap.c \
			  pivot.c \
			  sort_a_to_b.c \
			  sort_b_to_a.c \
			  stack_utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -I $(INCS_DIR)

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
