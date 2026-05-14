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

	if (ac != 2)
		return (error_msg("Usage: ./cub3d map.ber\n"), 1);
	if (is_dotcub(av[1]) == false)
		return (error_msg("Invalid file extension. Expected .cub\n"), 1);
	
	return (0);
}
