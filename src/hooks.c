/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:15:37 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/28 16:05:18 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int key_press(int key, t_cub *cub)
{
    if (key == 119)
        cub->player->move_up = 1;
    if (key == 115)
        cub->player->move_down = 1;
    if (key == 100)
        cub->player->move_right = 1;
    if (key == 97)
        cub->player->move_left = 1;
    if (key == 65361)
        cub->player->rot_left = 1;
    if (key == 65363)
        cub->player->rot_right = 1;
    return (0);
}
int key_release(int key, t_cub *cub)
{
    if (key == 119)
        cub->player->move_up = 0;
    if (key == 115)
        cub->player->move_down = 0;
    if (key == 100)
        cub->player->move_right = 0;
    if (key == 97)
        cub->player->move_left = 0;
    if (key == 65361)
        cub->player->rot_left = 0;
    if (key == 65363)
        cub->player->rot_right = 0;
    if (key == 65307)
        close_game(cub);
    return (0);
}