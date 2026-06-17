/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:19:22 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/17 17:29:11 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void load_textures(t_cub_bonus *cub, t_text *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(cub->mlx, path, &tex->w, &tex->h);
    if (!tex->img)
        close_game(cub);
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
}
void    init_textures(t_cub_bonus *cub, t_texture *texture)
{
    int i;
    char	*door[5];
    char	*weap;

    door[0] = ft_strdup("./sprites/door_00.xpm");
    door[1] = ft_strdup("./sprites/door_02.xpm");
    door[2] = ft_strdup("./sprites/door_04.xpm");
    door[3] = ft_strdup("./sprites/door_06.xpm");
    door[4] = ft_strdup("./sprites/door_10.xpm");
    weap = ft_strdup("./sprites/weapon1.xpm");
    
    load_textures(cub, cub->north, texture->north_text);
    load_textures(cub, cub->south, texture->south_text);
    load_textures(cub, cub->east, texture->east_text);
    load_textures(cub, cub->west, texture->west_text);
    load_textures(cub, cub->weap, weap);
    i = 0;
    while(i < 5)
    {
        cub->door[i] = malloc(sizeof(t_text));
        if (!cub->door[i])
        {
            while (i < 5)
                free(door[i++]);
            free(weap);
            close_game(cub);
        }
        load_textures(cub, cub->door[i], door[i]);
        free(door[i]);
        i++;  
    }
    free(weap);
}

t_text *get_texture(t_cub_bonus *cub)
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
            return (cub->west);
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

int    put_pixel_image(t_cub_bonus *cub, int x, int y, int color)
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

int    render_frame(t_cub_bonus *cub)
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
                put_pixel_image(cub, x, y, rgb_to_hex(cub->color->c_rgb[0], cub->color->c_rgb[1], cub->color->c_rgb[2]));
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
            put_pixel_image(cub, x, y, rgb_to_hex(cub->color->f_rgb[0], cub->color->f_rgb[1], cub->color->f_rgb[2]));
            y++;
        }
        x++;
    }
    draw_weapon(cub);
    draw_minimap(cub);
    return (0);
}

