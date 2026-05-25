/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:17:16 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 14:00:58 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
    t_cub   cub;
    t_player player;

    if (ac != 2)
        return (1);
    
    player.map = ft_get_map(&player, av[1]);
    initialize_player(&player);
    calculate_raydir(&player, 0, WIDTH);
    printf("%f", player.walldist);
    cub.mlx = mlx_init();
    cub.win = mlx_new_window(cub.mlx,  WIDTH, HEIGHT, "cub3d");
    cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
    cub.addr = mlx_get_data_addr(cub.img, &cub.bbp, &cub.size_line, &cub.endian);
    render_frame(&cub, &player);
    //mlx_loop_hook(cub.mlx, render_frame, &player);
    mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
    mlx_loop(cub.mlx);
    return (0);
}