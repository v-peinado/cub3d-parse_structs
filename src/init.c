/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:56:30 by vpeinado          #+#    #+#             */
/*   Updated: 2024/02/29 20:10:03 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int *take_rgb(char *line, char c)
{
    int *rgb;
    char **strs;
    int i;
    
    i = 0;
    rgb = malloc(sizeof(int) * 3);
    if (!rgb)
        return (NULL);
    //while(line[i] == ' ' || line[i] == '\t' || line[i] == c)
        //i++;
    line = ft_strtrim(line, "CF \t");
    strs = ft_split(line + i, ',');
    if (!strs)
        return (NULL);
    if (ft_arraylen(strs) != 3 || !ft_isdigit_string(strs[0])
        || !ft_isdigit_string(strs[1]) || !ft_isdigit_string(strs[2]))
    {
        printf("Error: bad rgb\n");
        return (NULL);
    }
    rgb[0] = ft_atoi(strs[0]);
    rgb[1] = ft_atoi(strs[1]);
    rgb[2] = ft_atoi(strs[2]);
    ft_free_strs(strs);
    return (rgb);
}

int rgb_to_hex(int *rgb)
{
    int hex;
    
    hex = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
    return (hex);
}

void fill_color(t_map *map, char *line, char c)
{
    int *rgb;
    
    if (c == 'C')
    {
        rgb = take_rgb(line, c);
        map->ceiling = rgb_to_hex(rgb);
    }
    if (c == 'F')
    {
        rgb = take_rgb(line, c);
        map->floor = rgb_to_hex(rgb);
    }
}

void fill_texture(t_map *map, char *line, char c)
{
    if (line[0] == 'N' || (line[0] == 'N' && line[1] == 'O'))
        map->textures[NORTH] = ft_strtrim(line, "NO \t");
    else if (line[0] == 'S' || (line[0] == 'S' && line[1] == 'O'))
        map->textures[SOUTH] = ft_strtrim(line, "SO \t");
    else if (line[0] == 'W' || (line[0] == 'W' && line[1] == 'E'))
        map->textures[WEST] = ft_strtrim(line, "WE \t");
    else if (line[0] == 'E' || (line[0] == 'E' && line[1] == 'A'))
        map->textures[EAST] = ft_strtrim(line, "EA \t");
    else
        printf("Error: bad texture\n");
}

void fill_text_and_colors(t_map *map, char *path)
{
    int fd;
    char *line;
    
    fd = open(path, O_RDONLY);
    if (fd < 0)
        printf("Error: open\n");
    map->textures = malloc(4 * sizeof(char *));
    if (!map->textures)
    {
        printf("Error: malloc\n");
        return ;
    }
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        line = ft_strtrim(line, " \t\n");
        if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E'
			|| line[0] == 'W')
			fill_texture(map, line, line[0]);
		if (line[0] == 'C' || line[0] == 'F')
			fill_color(map, line, line[0]);
        free(line);
    }
    printf("ceiling: %x\n", map->ceiling);
    printf("floor: %x\n", map->floor);
    printf("texture: %s\n", map->textures[NORTH]);
    printf("texture: %s\n", map->textures[SOUTH]);
    printf("texture: %s\n", map->textures[WEST]);
    printf("texture: %s\n", map->textures[EAST]);
    close(fd);
}

void fill_matrix(t_map *map, char *path)
{
    map->matrix = ft_calloc(1, sizeof(char *));
    if (!map->matrix)
    {
        printf("Error: malloc\n");
        return ;
    }
    
}

t_map map(char *path)
{
    t_map map;
    
    fill_text_and_colors(&map, path);
    //fill_matrix(&map, path);
    //fill_player_vars(&map, path);
    //validate_map(&map);
    return (map);
}

t_cub3d init_cub3d(char *path)
{
    t_cub3d *cub3d;
    cub3d = ft_calloc(1, sizeof(t_cub3d));
    if (!cub3d)
    {
        printf("Error: malloc\n");
        return ;
    }
    cub3d->map = map(path);
}