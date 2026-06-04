/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:33:32 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/04 15:34:44 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

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

static bool	try_parse_color_entry(char *content, t_color *color)
{
	char	**mat;
	char	*pick_c;

	pick_c = remove_first_char(content);
	if (pick_c == NULL)
		return (true);
	if (count_comma(pick_c) == false || check_chars(pick_c) == false)
		return (free(pick_c), false);
	mat = ft_split(pick_c, ',');
	if (all_digit(mat) == false)
		return (free(pick_c), free_mat(mat),
			error_msg("Color should be just number [0 - 9]"), false);
	if (validate_range(mat) == false)
		return (free(pick_c), free_mat(mat),
			error_msg("Color's range should be between [0 - 255]"), false);
	init_color(color, content, mat);
	free(pick_c);
	return (free_mat(mat), true);
}

static bool	detect_short_ident(char *content, char *chars)
{
	if ((content[0] == 'F' || content[0] == 'C') && content[1] == ' ')
	{
		if (ft_strchr(chars, content[0]))
		{
			error_msg("Duplicate colors");
			return (false);
		}
		chars[ft_strlen(chars)] = content[0];
	}
	return (true);
}

static bool	extract_ident(t_file *file, t_color *color)
{
	t_list	*head;
	char	*chars;

	chars = ft_calloc(3, sizeof(char));
	if (chars == NULL)
		return (error_msg("Memory allocation failed"), false);
	head = file->lines;
	while (head)
	{
		if (detect_short_ident((char *)head->content, chars) == false)
			return (free(chars), false);
		if (try_parse_color_entry((char *)head->content, color) == false)
			return (free(chars), false);
		head = head->next;
	}
	if (ft_strlen(chars) < 2)
	{
		free(chars);
		error_msg("Miss color in the file [F or C]\n");
		return (false);
	}
	free(chars);
	return (true);
}

bool	check_color(t_file *file, t_color *color)
{
	if (extract_ident(file, color) == false)
		return (false);
	return (true);
}
