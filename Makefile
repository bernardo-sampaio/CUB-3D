# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 22:25:20 by ealbino           #+#    #+#              #
#    Updated: 2026/06/17 19:41:36 by bsampaio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D

NAME_BONUS = cub3D_bonus

MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx_Linux.a



#**************************************************************************#
#*																		  *#
#*                          MANDATORY                                     *#
#*																		  *#
#**************************************************************************#

LIBFT_DIR   = src/mandatory/parsing/libft

LIBFT       = $(LIBFT_DIR)/libft.a

CFLAGS      = -Wall -Wextra -Werror -g -Isrc/mandatory/parsing/includes -Isrc/mandatory/parsing/libft -I./

HEADER       = cub3d.h src/mandatory/parsing/includes/core/cub3d_parsing.h

OBJS = \
	src/mandatory/main.o \
	src/mandatory/game.o \
	src/mandatory/player_position.o \
	src/mandatory/render.o\
	src/mandatory/render_utils.o\
	src/mandatory/dda.o \
	src/mandatory/move_player.o \
	src/mandatory/hooks.o \
	src/mandatory/rotate_player.o \
	src/mandatory/raycast.o \
	src/mandatory/parsing/get_next_line.o \
	src/mandatory/parsing/parse_file.o \
	src/mandatory/parsing/parse_color.o \
	src/mandatory/parsing/parse_color_utils.o \
	src/mandatory/parsing/parse_texture.o \
	src/mandatory/parsing/parse_texture_utils.o \
	src/mandatory/parsing/parse_map.o \
	src/mandatory/parsing/parse_map_utils.o \
	src/mandatory/parsing/error/error.o \
	src/mandatory/parsing/utils/utils.o \
	src/mandatory/parsing/utils/cleanup.o

#**************************************************************************#
#*																		  *#
#*                          BONUS                                         *#
#*																		  *#
#**************************************************************************#

LIBFT_DIR_BONUS   = src/bonus/parsing_bonus/libft

LIBFT_BONUS       = $(LIBFT_DIR_BONUS)/libft.a

CFLAGS_BONUS = $(CFLAGS) -Isrc/bonus/parsing_bonus/includes_bonus

HEADER_BONUS = $(HEADER)  cub3d_bonus.h src/bonus/parsing_bonus/includes_bonus/core/cub3d_parsing_bonus.h 

OBJS_BONUS = \
	src/bonus/main_bonus.o \
	src/bonus/render_bonus.o \
	src/bonus/hooks_bonus.o \
	src/bonus/move_player_bonus.o \
	src/bonus/minimap_bonus.o \
	src/bonus/door_bonus.o \
	src/bonus/weapon_bonus.o \
	src/bonus/dda_bonus.o \
	src/bonus/raycast_bonus.o \
	src/bonus/player_position_bonus.o \
	src/bonus/rotate_player_bonus.o \
	src/mandatory/parsing/get_next_line.o \
	src/mandatory/parsing/parse_file.o \
	src/mandatory/parsing/parse_color.o \
	src/mandatory/parsing/parse_color_utils.o \
	src/mandatory/parsing/parse_texture.o \
	src/mandatory/parsing/parse_texture_utils.o \
	src/mandatory/parsing/parse_map.o \
	src/mandatory/parsing/parse_map_utils.o \
	src/mandatory/parsing/error/error.o \
	src/mandatory/parsing/utils/utils.o \
	src/mandatory/parsing/utils/cleanup.o \
	src/bonus/parsing_bonus/parse_map_utils_bonus.o \
	src/bonus/parsing_bonus/parse_map_bonus.o 


#**************************************************************************#
#*																		  *#
#*                          REGRAS	                                      *#
#*																		  *#
#**************************************************************************#



all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(OBJS): $(HEADER)

$(OBJS_BONUS): $(HEADER_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)

run: all clean
	@clear
	@if [ -f $(NAME) ]; then \
		echo "Successfully compiled"; \
	fi

run_bonus: bonus clean
	@clear
	@if [ -f $(NAME_BONUS) ]; then \
		echo "Successfully compiled bonus"; \
	fi
	
re: fclean all

.PHONY: all bonus clean fclean re
