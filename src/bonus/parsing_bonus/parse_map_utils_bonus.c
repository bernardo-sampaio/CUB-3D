/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:31:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:12:26 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "src/bonus/parsing_bonus/includes_bonus/core/cub3d_parsing_bonus.h"

bool	is_map_line_bonus(char *line)
{
	int	i;

	i = 0;
	while ((line[i] && line[i] == ' ') || (line[i] >= '\t' && line[i] <= '\r'))
		i++;
	if (!line[i])
		return (false);
	while (line[i] && ft_strchr("01NSEWD ", line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (true);
	return (false);
}

int	count_map_lines_bonus(t_file *file)
{
	t_list	*head;
	int		count;

	head = file->lines;
	count = 0;
	while (head)
	{
		if (is_map_line_bonus((char *)head->content))
			count++;
		head = head->next;
	}
	return (count);
}

bool	after_map_bonus(t_list *map)
{
	t_list	*grasp;

	grasp = map;
	while (grasp)
	{
		if (is_only_whitespace((char *)grasp->content) == false)
		{
			error_msg("Invalid map format: non-map line found after map lines");
			return (false);
		}
		grasp = grasp->next;
	}
	return (true);
}
