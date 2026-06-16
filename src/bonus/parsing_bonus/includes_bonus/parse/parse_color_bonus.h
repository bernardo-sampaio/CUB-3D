/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:32:09 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:03:09 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_COLOR_BONUS_H
# define PARSE_COLOR_BONUS_H

typedef struct s_color
{
	int	*floor_rgb;
	int	*ceiling_rgb;
}		t_color;

bool	check_color(t_file *file, t_color *color);
void	init_color(t_color *color, char *ident, char **content);
bool	validate_range(char **mat);
bool	after_space(char **mat, int i, int j);
bool	all_digit(char **mat);
bool	check_chars(char *color);

#endif
