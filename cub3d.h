/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:38:44 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/28 12:39:23 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include"minilibx-linux/mlx.h"
# include"get_next_line/get_next_line.h"
# include<stdio.h>
# include<fcntl.h>
# include<math.h> 

# define WIDTH 1920
# define HEIGHT 1080
# define SKY_BULE_COLOR 0x0033A1FD
# define BROWN_C0LOR 0x00E4A853
# define WALL_COLOR 0xBAE0D2F4

typedef struct s_player
{
    char **map;
    double pos_x;   
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
    double raydir_x;
    double raydir_y;
    double side_x;
    double side_y;
    double delta_x; 
    double delta_y;
    double walldist;
    int map_x;
    int map_y;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int drawend;
    int drawstart;
    int map_width;
    int map_height;
    int move_up;
    int move_down;
    int move_left;
    int move_right;
    int rot_left;
    int rot_right;
} t_player;

typedef struct s_cub
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *addr;
    int     bbp;
    int     size_line;
    int     endian;
    int     x;
    int     y;
    int		w;
	int		h;
    t_player *player;
} t_cub;

char    **ft_get_map(t_player *player, char *file);
void    initialize_player(t_player *player);
int     render_frame(t_cub *cub);
void    calculate_raydir(t_player *player, int x, int widthscreen);
void    setup_dda(t_player *player);
void    ft_dda(t_player *player);
void    calculate_walldist(t_player *player);
void    move_player(t_player *player);
int     key_press(int key, t_player *player);
int     key_release(int key, t_player *player);

#endif