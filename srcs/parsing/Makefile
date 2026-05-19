# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 22:25:20 by ealbino           #+#    #+#              #
#    Updated: 2026/05/15 19:48:25 by ealbino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS      = -Wall -Wextra -Werror -Iincludes -Ilibft

NAME        = cub3d

LIBFT_DIR   = libft

LIBFT       = $(LIBFT_DIR)/libft.a

HEADER       = includes/core/cub3d.h
OBJS = \
	cub3d.o \
	get_next_line.o \
	parse_file.o \
	parse_color.o \
	parse_texture.o \
	parse_map.o \
	error/error.o \
	utils/utils.o \
	utils/cleanup.o

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(OBJS): $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

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

