/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:55:27 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/14 15:55:28 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error/error.h"
# include "get_next_line/get_next_line.h"
# include "libft.h"
# include "parse/parse_file.h"
# include "parse/parse_color.h"
# include "parse/parse_map.h"
# include "parse/parse_texture.h"
# include "utils/utils.h"
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
