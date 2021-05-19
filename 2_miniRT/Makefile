# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 12:29:09 by jiwchoi           #+#    #+#              #
#    Updated: 2021/05/19 00:08:30 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= miniRT

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

LIBFT_DIR	= ./libft/
LIBFT_FILE	= libft.a

MLX_DIR		= ./mlx/

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/

SRC			= convert.c \
			  error.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  hit.c \
			  hit_cylinder.c \
			  hit_plane.c \
			  hit_sphere.c \
			  hit_square.c \
			  hit_triangle.c \
			  init.c \
			  main.c \
			  make.c \
			  parse.c \
			  parse_figures.c \
			  phong_lighting.c \
			  phong_lighting2.c \
			  ray.c \
			  save_image.c \
			  utils.c \
			  vec_operation.c \
			  vec_scalar.c \
			  vec_utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(TARGET) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(TARGET) $(OBJS) -I $(INCS_DIR) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all : $(TARGET)

clean : 
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(TARGET)

re : clean all

bonus : all

.PHONY : all clean fclean re bonus
