/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:01:04 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/05 13:10:27 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void load_textures(t_cub *cub, t_text *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(cub->mlx, path, &tex->w, &tex->h);
    if (!tex->img)
        exit(1);
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
}
void    init_textures(t_cub *cub)
{
    int  i;
    char *path_tex[5] = {
        "sprites/xpm/door_00.xpm",
        "sprites/xpm/door_04.xpm",
        "sprites/xpm/door_06.xpm",
        "sprites/xpm/door_08.xpm",
        "sprites/xpm/door_10.xpm"
    };
    
    load_textures(cub, cub->north, "sprites/xpm/north.xpm");
    load_textures(cub, cub->south, "sprites/xpm/south.xpm");
    load_textures(cub, cub->east, "sprites/xpm/parede.xpm");
    load_textures(cub, cub->weast, "sprites/xpm/parede1.xpm");
    i = 0;
    while(i < 5)
    {
         cub->door[i] = malloc(sizeof(t_text));
         if (!cub->door[i])
            close_game(cub);
         load_textures(cub, cub->door[i], path_tex[i]);
         i++;
    }
}

t_text *get_texture(t_cub *cub)
{
    if (cub->player->hit_door == 1)
    {
        if (cub->player->door_frame < 0 || cub->player->door_frame > 4 || !cub->door[cub->player->door_frame])
            return(cub->north);
        return (cub->door[cub->player->door_frame]);
    }
    if (cub->player->side == 0)
    {
        if (cub->player->raydir_x > 0)
            return (cub->weast);
        else
            return (cub->east);
    }
    else
    {
        if (cub->player->raydir_y > 0)
            return (cub->south);
        else
            return (cub->north);
    }
}

int    put_pixel_image(t_cub *cub, int x, int y, int color)
{
    int res;
    
    if (x < 0 || x >= WIDTH)
        return (0);
    if (y < 0 || y >= HEIGHT)
        return (0);
    res = (y * cub->size_line) + (x * (cub->bpp / 8));
    *(int *)(cub->addr + res) = color;
    return (1);
}

int    render_frame(t_cub *cub)
{
    t_text *text;
    double wall_x;
    double step;
    double tex_pos;
    int tex_x;
    int color;
    int tex_y;
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        calculate_raydir(cub->player, x, WIDTH);
        setup_dda(cub->player);
        cub->player->hit = 0;
        cub->player->hit_door = 0;
        ft_dda(cub->player);
        calculate_walldist(cub->player);
        if (cub->player->line_height <= 0)
            cub->player->line_height = 1;
        text = get_texture(cub);
        if (cub->player->side == 0)
            wall_x = cub->player->pos_y + cub->player->walldist * cub->player->raydir_y;
        else
            wall_x = cub->player->pos_x + cub->player->walldist * cub->player->raydir_x;
        wall_x -= floor(wall_x);
        tex_x = (int)(wall_x * text->w);
        if (cub->player->side == 0 && cub->player->raydir_x < 0)
            tex_x = text->w - tex_x - 1;
        if (cub->player->side == 1 && cub->player->raydir_y > 0)
            tex_x = text->w - tex_x - 1;
        step = (double)text->h / cub->player->line_height;
        tex_pos = (cub->player->drawstart - HEIGHT / 2 + cub->player->line_height / 2) * step;
        y = 0;
        while (y < cub->player->drawstart)
        {
                put_pixel_image(cub, x, y, SKY_BULE_COLOR);
                y++;
        }
        while (y <= cub->player->drawend)
        {
            tex_y = (int)tex_pos;
            if (tex_y < 0)
                tex_y = 0;
            if (tex_y >= text->h)
                tex_y = text->h - 1;
            tex_pos += step;
            color = *(int *)(text->addr + tex_y * text->size_line + tex_x * (text->bpp / 8));
            put_pixel_image(cub, x, y, color);
            y++;
        }
        while (y < HEIGHT)
        {
            put_pixel_image(cub, x, y, BROWN_C0LOR);
            y++;
        }
        x++;
    }
    draw_minimap(cub);
    return (0);
}
