/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:34:33 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/15 14:21:41 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include"minilibx-linux/mlx.h"
#include "src/bonus/parsing/includes/core/cub3d_parsing.h"
# include<fcntl.h>
# include<math.h> 

# define SCALE_PX 8
# define OFFSET_X 10
# define OFFSET_Y 10
# define WIDTH 1920
# define HEIGHT 1080

typedef struct  s_text
{
    void    *img;
    void    *addr;
    int w;
    int h;
    int size_line;
    int endian;
    int bpp;
} t_text;


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
    int hit_door;
    int door_frame;
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
    int is_moving;
    double  weapon_timer;
} t_player;

typedef struct s_cub_bonus
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *addr;
    int     bpp;
    int     size_line;
    int     endian;
    int     key_close;
    int     x;
    int     y;
    int		w;
	int		h;
    t_player *player;
    t_texture *texture;
    t_color *color;
    t_text  *weap;
    t_text  *north;
    t_text  *south;
    t_text  *west;
    t_text  *east;
    t_text  *door[5];
    t_cub3d *cub3d;
} t_cub_bonus;

// Player
void    initialize_player(t_player *player);
void    rotate_player(t_player *player, double angle);
void    rotate_right(t_player *player);
void    rotate_left(t_player *player);
int     in_bounds(t_player *player, int x, int y);
void    move_player(t_cub_bonus *cub);

// Raycasting
void    ft_dda(t_player *player);
void    setup_dda(t_player *player);
void    calculate_raydir(t_player *player, int x, int widthscreen);
void    calculate_walldist(t_player *player);


// Rendering
int     render_frame(t_cub_bonus *cub);
void    init_textures(t_cub_bonus *cub, t_texture *texture);
int    put_pixel_image(t_cub_bonus *cub, int x, int y, int color);
void    draw_minimap(t_cub_bonus *cub);
void    open_close_door(t_cub_bonus *cub);
void    draw_weapon(t_cub_bonus *cub);

// Game
int     close_game(t_cub_bonus *cub);
void    update_door(t_cub_bonus *cub);

// Hooks
int     mouse_move(int x, int y, t_cub_bonus *cub);
int     key_press(int key, t_cub_bonus *cub);
int     key_release(int key, t_cub_bonus *cub);

#endif
