/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:33:32 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/27 12:09:06 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

static char	*remove_first_char(char *content)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc(ft_strlen(content), sizeof(char));
	if (new == NULL)
		return (NULL);
	if ((content[0] == 'F' || content[0] == 'C') && content[1] == ' ')
	{
		j = 0;
		i = 1;
		while (content[i])
		{
			new[j] = content[i];
			i++;
			j++;
		}
	}
	else
		return (free(new), NULL);
	return (new);
}

static bool	detect_short_ident(char *content, int *count)
{
	char	*pick_c;

	if (ft_strlen(content) != 2)
		return (true);
	pick_c = ft_strdup(content);
	if (pick_c == NULL)
		return (error_msg("Memory allocation failed"), false);
	if (pick_c[0] == 'F' || pick_c[0] == 'C')
		(*count)++;
	free(pick_c);
	return (true);
}

static bool	try_parse_color_entry(char *content, t_color *color, int *count)
{
	char	**mat;
	char	*pick_c;

	pick_c = remove_first_char(content);
	if (pick_c == NULL)
		return (true);
	if (count_comma(pick_c) == false || check_chars(pick_c) == false)
		return (free(pick_c), false);
	mat = ft_split(pick_c, ',');
	if (*count > 2)
	{
		free_mat(mat);
		free(pick_c);
		return (error_msg("Duplicate colors"), false);
	}
	if (all_digit(mat) == false)
		return (free(pick_c), free_mat(mat),
			error_msg("Color should be just number [0 - 9]"), false);
	if (validate_range(mat) == false)
		return (free(pick_c), free_mat(mat),
			error_msg("Color's range should be between [0 - 255]"), false);
	init_color(color, content, mat);
	(*count)++;
	free(pick_c);
	return (free_mat(mat), true);
}

static bool	extract_ident(t_file *file, t_color *color)
{
	t_list	*head;
	int		count;

	count = 1;
	head = file->lines;
	while (head)
	{
		if (detect_short_ident((char *)head->content, &count) == false)
			return (false);
		if (try_parse_color_entry((char *)head->content, color,
				&count) == false)
			return (false);
		head = head->next;
	}
	if (--count < 2)
		return (error_msg("Miss color in the file [F or C]\n"), false);
	return (true);
}

bool	check_color(t_file *file, t_color *color)
{
	if (extract_ident(file, color) == false)
	{
		ft_lstclear(&file->lines, free);
		free_color(color);
		return (false);
	}
	return (true);
}
