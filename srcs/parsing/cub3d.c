/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:04:55 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/14 16:07:53 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"


int	main(int ac, char **av)
{
	(void)av;
	t_file	file;
	t_texture	texture_dir;
	t_color	color;
	t_map	map;

	if (ac != 2)
		return (error_msg("Usage: ./cub3d map.ber\n"), 1);
	if (validate_extension((av[1]), ".cub") == false)
		return (error_msg("Invalid file extension. Expected .cub\n"), 1);
	ft_memset(&file, 0, sizeof(t_file));
	if (check_file(av[1], &file) == false)
		return (ft_lstclear(&file.lines, free), 1);
	ft_memset(&texture_dir, 0, sizeof(t_texture));
	if (check_texture(&file, &texture_dir) == false)
	{
		ft_lstclear(&file.lines, free);
		free_texture(&texture_dir);
		return (1);
	}
	ft_memset(&color, 0, sizeof(t_color));
	if (check_color(&file, &color) == false)
	{
		ft_lstclear(&file.lines, free);
		free_texture(&texture_dir);
		free_color(&color);
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
	ft_lstclear(&file.lines, free);
	free_texture(&texture_dir);
	free_color(&color);
	free_mat(map.grid);
	return (0);
}
