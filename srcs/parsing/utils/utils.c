/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:48:57 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/16 10:34:05 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

bool	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (-1);
	if (s1 && !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

bool	is_only_whitespace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r'
			&& str[i] != '\v' && str[i] != '\f')
			return (false);
		i++;
	}
	return (true);
}

bool	count_comma(char *color)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (color && color[i])
	{
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (true);
	error_msg("Invalid color");
	return (false);
}
