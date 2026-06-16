/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:34:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:01:51 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>

typedef struct s_cub3d	t_cub3d;

void					free_structs(t_cub3d *cub3d);
void					free_mat(char **mat);
void					free_texture(t_texture *texture_dir);
void					free_color(t_color *color);
int						ft_strcmp(const char *s1, const char *s2);
int						rgb_to_hex(int r, int g, int b);
bool					is_only_whitespace(char *str);
bool					count_comma(char *color);

#endif
