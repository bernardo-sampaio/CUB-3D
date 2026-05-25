/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:15:37 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 18:34:59 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int key_press(int key, t_player *player)
{
    if (key == 119)
        player->move_up = 1;
    if (key == 115)
        player->move_down = 1;
    if (key == 100)
        player->move_right = 1;
    if (key == 97)
        player->move_left = 1;
    if (key == 65361)
      player->rot_left = 1;
    if (key == 65363)
        player->rot_right = 1;
    return (0);
}
int key_release(int key, t_player *player)
{
    if (key == 119)
        player->move_up = 0;
    if (key == 115)
        player->move_down = 0;
    if (key == 100)
        player->move_right = 0;
    if (key == 97)
        player->move_left = 0;
    if (key == 65361)
        player->rot_left = 0;
    if (key == 65363)
        player->rot_right = 0;
    return (0);
}