/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:27:01 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/20 14:26:45 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

void	error_msg(char *msg)
{
	ft_putendl_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
}

void	for_gossip(char c, int line, int col)
{
	ft_putstr_fd("Error\nThe character [", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("] is next to a space", 2);
	ft_putstr_fd("check position: [", 2);
	ft_putnbr_fd(line, 2);
	ft_putchar_fd(']', 2);
	ft_putchar_fd('[', 2);
	ft_putnbr_fd(col, 2);
	ft_putendl_fd("]", 2);
}

void	for_walls(int line, int col)
{
	error_msg("Map not closed by walls");
	ft_putstr_fd("check position [", 2);
	ft_putnbr_fd(line, 2);
	ft_putchar_fd(']', 2);
	ft_putchar_fd('[', 2);
	ft_putnbr_fd(col, 2);
	ft_putendl_fd("]", 2);
	ft_putendl_fd("\nNote: this suggestion can unprecise", 2);
	ft_putendl_fd("if the value encountered is different from [0]", 2);
}
