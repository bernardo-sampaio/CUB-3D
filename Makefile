# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 22:25:20 by ealbino           #+#    #+#              #
#    Updated: 2026/06/11 14:39:18 by bsampaio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS      = -Wall -Wextra -Werror -Isrc/parsing/includes -Isrc/parsing/libft -I./

NAME        = cub3D

MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR   = src/parsing/libft

LIBFT       = $(LIBFT_DIR)/libft.a

HEADER       = cub3d.h src/parsing/includes/core/cub3d_parsing.h
OBJS = \
	src/main.o \
	src/player_position.o \
	src/render.o\
	src/dda.o src/raycast.o \
	src/move_player.o \
	src/hooks.o \
	src/door.o \
	src/rotate_player.o \
	src/minimap.o \
	src/weapon.o \
	src/parsing/get_next_line.o \
	src/parsing/parse_file.o \
	src/parsing/parse_color.o \
	src/parsing/parse_color_utils.o \
	src/parsing/parse_texture.o \
	src/parsing/parse_texture_utils.o \
	src/parsing/parse_map.o \
	src/parsing/parse_map_utils.o \
	src/parsing/error/error.o \
	src/parsing/utils/utils.o \
	src/parsing/utils/cleanup.o

all: $(LIBFT) $(MLX) $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(OBJS): $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

run: all clean
	@clear
	@if [ -f cub3d ]; then \
		echo "Successfully compiled"; \
	fi

re: fclean all

.PHONY: all clean fclean re
