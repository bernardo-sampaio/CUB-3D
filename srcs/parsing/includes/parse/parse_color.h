/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:32:09 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 18:00:35 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_COLOR_H
# define PARSE_COLOR_H

typedef struct s_color
{
	int	*floor_rgb;
	int	*ceiling_rgb;
}	t_color;

bool	check_color(t_file *file, t_color *color);

#endif
