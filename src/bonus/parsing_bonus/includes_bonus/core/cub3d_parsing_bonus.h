/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:55:27 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:09:04 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_BONUS_H
# define CUB3D_PARSING_BONUS_H

# include "error/error_bonus.h"
# include "get_next_line/get_next_line.h"
# include "libft.h"
# include "parse/parse_file_bonus.h"
# include "parse/parse_color_bonus.h"
# include "parse/parse_map_bonus.h"
# include "parse/parse_texture_bonus.h"
# include "utils/utils_bonus.h"
# include <errno.h>
# include <stdio.h>

typedef struct s_cub3d
{
	t_file		file;
	t_texture	texture;
	t_color		color;
	t_map		map;
}				t_cub3d;

#endif
