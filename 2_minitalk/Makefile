# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 16:06:08 by jiwchoi           #+#    #+#              #
#    Updated: 2021/06/23 17:17:14 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server
CLIENT		= client

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

OBJS_DIR	= ./objs/

SERVER_SRCS	= server.c utils.c
CLIENT_SRCS	= client.c utils.c

SERVER_OBJS	= $(addprefix $(OBJS_DIR), $(SERVER_SRCS:.c=.o))
CLIENT_OBJS	= $(addprefix $(OBJS_DIR), $(CLIENT_SRCS:.c=.o))

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	$(CC) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) -o $(CLIENT) $(CLIENT_OBJS)

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I. -c $? -o $@

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : clean all

bonus :

.PHONY : all clean fclean re bonus
