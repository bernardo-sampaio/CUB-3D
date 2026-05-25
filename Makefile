# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 15:42:14 by bsampaio          #+#    #+#              #
#    Updated: 2026/05/25 14:00:22 by bsampaio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
GNL_DIR = get_next_line
LIBFT_DIR = $(GNL_DIR)/Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		src/raycasting_map.c src/init_player_position.c src/render.c src/main.c \
		src/dda.c src/raycast.c
	  
OBJS = $(SRCS:.c=.o)

HEADER = cub3d.h

all: $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): $(LIBFT) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -L$(MLX_DIR) -lmlx -lXext -lX11 -o $(NAME)

$(OBJ): $(HEADER)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re