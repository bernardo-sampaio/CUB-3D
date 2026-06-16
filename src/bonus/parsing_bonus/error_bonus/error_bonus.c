/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 09:53:33 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/16 10:10:22 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing_bonus.h"

void	error_msg(char *msg)
{
	ft_putendl_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
}
