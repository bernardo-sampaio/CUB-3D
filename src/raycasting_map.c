/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:20:59 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 18:05:45 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int map_width(char **map)
{
    int i = 0;
    int max = 0;

    while (map[i])
    {
        int len = 0;
        while (map[i][len] && map[i][len] != '\n')
            len++;
        if (len > max)
            max = len;
        i++;
    }
    return max;
}

void    get_map_size(t_player *player)
{
    player->map_height = 0;
    while (player->map[player->map_height])
        player->map_height++;
    player->map_width = map_width(player->map);
}

char    **ft_get_map(t_player *player, char *file)
{
    int i = 0;
    int fd;
    char *line;
    int in_map = 0;

    player->map = NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    player->map = malloc(sizeof(char *) * 1000); 
    line = get_next_line(fd);
    while (line)
    {
        if (line[0] && (line[0] == '1' || line[0] == ' '))
            in_map = 1;
        if (in_map)
        {
            int j = 0;
            while (line[j] && line[j] != '\n')
                j++;
            if (line[j] == '\n')
                line[j] = '\0';
            ft_putendl_fd(line, 1);
            player->map[i++] = ft_strdup(line);
        }
        in_map = 0;
        free(line);
        line = get_next_line(fd);
    }
    player->map[i] = NULL;
    get_map_size(player);
    close(fd);
    return (player->map);
}