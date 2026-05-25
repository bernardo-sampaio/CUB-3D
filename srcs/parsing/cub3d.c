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
	t_file		file;
	t_texture	texture_dir;
	t_color		color;
	t_map		map;

	if (ac != 2)
		return (error_msg("Usage: ./cub3d map.ber\n"), 1);
	if (validate_extension((av[1]), ".cub") == false)
		return (error_msg("Invalid file extension. Expected .cub\n"), 1);
	ft_memset(&file, 0, sizeof(t_file));
	if (check_file(av[1], &file) == false)
		return (ft_lstclear(&file.lines, free), 1);
	ft_memset(&texture_dir, 0, sizeof(t_texture));
	if (check_texture(&file, &texture_dir) == false)
		return (1);
	ft_memset(&color, 0, sizeof(t_color));
	if (check_color(&file, &color) == false)
	{
		free_texture(&texture_dir);
		return (1);
	}
	ft_memset(&map, 0, sizeof(t_map));
	if (check_map(&file, &map) == false)
	{
		ft_lstclear(&file.lines, free);
		free_texture(&texture_dir);
		free_color(&color);
		return (1);
	}
	if (final_check(file) == false)
	{
		ft_lstclear(&file.lines, free);
		free_texture(&texture_dir);
		free_color(&color);
		free_mat(map.grid);
		return (1);
	}
	ft_lstclear(&file.lines, free);
	free_texture(&texture_dir);
	free_color(&color);
	free_mat(map.grid);
	return (0);
}
