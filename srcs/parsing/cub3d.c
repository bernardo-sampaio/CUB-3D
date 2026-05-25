/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:04:55 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 18:05:49 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

static bool	final_check(t_file file)
{
	t_list	*head;
	char	**mat;
	char	*line;

	head = file.lines;
	while (head)
	{
		line = (char *)head->content;
		mat = ft_split(line, 32);
		if (line[0] != 'F' && line[0] != 'C'
			&& identify_direction(mat[0]) == false && !is_map_line(line)
			&& !is_only_whitespace(line))
		{
			free_mat(mat);
			return (error_msg("Invalid line in the file"), false);
		}
		free_mat(mat);
		head = head->next;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_cub3d		cub3d;

	if (ac != 2)
		return (error_msg("Usage: ./cub3d map.ber\n"), 1);
	if (validate_extension((av[1]), ".cub") == false)
		return (error_msg("Invalid file extension. Expected .cub\n"), 1);
	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	if (check_file(av[1], &cub3d.file) == false)
		return (ft_lstclear(&cub3d.file.lines, free), 1);
	if (check_texture(&cub3d.file, &cub3d.texture) == false)
		return (1);
	if (check_color(&cub3d.file, &cub3d.color) == false)
	{
		free_texture(&cub3d.texture);
		return (1);
	}
	if (check_map(&cub3d.file, &cub3d.map) == false)
	{
		ft_lstclear(&cub3d.file.lines, free);
		free_texture(&cub3d.texture);
		free_color(&cub3d.color);
		return (1);
	}
	if (final_check(cub3d.file) == false)
	{
		free_structs(&cub3d);
		return (1);
	}
	free_structs(&cub3d);
	return (0);
}
