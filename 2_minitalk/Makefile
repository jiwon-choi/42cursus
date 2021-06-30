# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 16:06:08 by jiwchoi           #+#    #+#              #
#    Updated: 2021/06/30 15:17:09 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server
CLIENT		= client
SERVER_B	= server_bonus
CLIENT_B	= client_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

OBJS_DIR	= ./objs/

SERVER_SRCS	= server.c utils.c
CLIENT_SRCS	= client.c utils.c
SERVER_OBJS	= $(addprefix $(OBJS_DIR), $(SERVER_SRCS:.c=.o))
CLIENT_OBJS	= $(addprefix $(OBJS_DIR), $(CLIENT_SRCS:.c=.o))

SERVER_BSRCS	= server_bonus.c utils.c
CLIENT_BSRCS	= client_bonus.c utils.c
SERVER_BOBJS	= $(addprefix $(OBJS_DIR), $(SERVER_BSRCS:.c=.o))
CLIENT_BOBJS	= $(addprefix $(OBJS_DIR), $(CLIENT_BSRCS:.c=.o))

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	$(CC) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) -o $(CLIENT) $(CLIENT_OBJS)

$(SERVER_B) : $(SERVER_BOBJS)
	$(CC) -o $(SERVER_B) $(SERVER_BOBJS)

$(CLIENT_B) : $(CLIENT_BOBJS)
	$(CC) -o $(CLIENT_B) $(CLIENT_BOBJS)

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I. -c $? -o $@

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re : clean all

bonus : $(SERVER_B) $(CLIENT_B)

.PHONY : all clean fclean re bonus
