/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:13:13 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/19 10:42:01 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_weapon(t_cub_bonus *cub)
{
	t_bonus	weapon;

	if (cub->player->is_moving == 1)
		cub->player->weapon_timer += 0.17;
	weapon.offset_y = sin(cub->player->weapon_timer) * 20;
	weapon.start_x = (WIDTH / 2) - (cub->weap->w / 2);
	weapon.start_y = (HEIGHT - cub->weap->h) + weapon.offset_y;
	weapon.x = 0;
	while (weapon.x < cub->weap->w)
	{
		weapon.y = 0;
		while (weapon.y < cub->weap->h)
		{
			weapon.color = *(int *)(cub->weap->addr + weapon.y
					* cub->weap->size_line + weapon.x * (cub->weap->bpp / 8));
			if (weapon.color > 0)
				put_pixel_image(cub, weapon.start_x + weapon.x, weapon.start_y
					+ weapon.y, weapon.color);
			weapon.y++;
		}
		weapon.x++;
	}
}
