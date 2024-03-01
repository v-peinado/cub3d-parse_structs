/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:56:30 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/01 11:13:35 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rgb_range(int rgb)
{
    if (rgb < 0 || rgb > 255)
        return (1);
    return (0);
}

int *take_rgb(char *line, char c)
{
    int *rgb;
    char **strs;
    int i;
    
    i = 0;
    rgb = malloc(sizeof(int) * 3);
    if (!rgb)
        return (NULL);
    line = ft_strtrim(line, "CF \t");
    strs = ft_split(line + i, ',');
    if (!strs)
        return (NULL);
    if (ft_arraylen(strs) != 3 || !ft_isdigit_string(strs[0])
        || !ft_isdigit_string(strs[1]) || !ft_isdigit_string(strs[2]))
    {
        printf("Error: bad rgb, the args not 3 or not digit\n");
        return (NULL);
    }
    rgb[0] = ft_atoi(strs[0]);
    rgb[1] = ft_atoi(strs[1]);
    rgb[2] = ft_atoi(strs[2]);
    if (rgb_range(rgb[0]) || rgb_range(rgb[1]) || rgb_range(rgb[2]))
    {
        printf("Error: bad rgb,not <255 && >0\n");
        return (NULL);
    }
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
    close(fd);
}

void fill_matrix(t_map *map, char *path)
{
    int fd;
    char *line;
    
    fd = open(path, O_RDONLY);
    if (fd < 0)
        printf("Error: open\n");
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        line = ft_strtrim(line, "\t\n");
        if (line[0] == '1')
        {
            map->matrix = ft_arraypush(map->matrix, ft_strdup(line));
            if (!map->matrix)
            {
                printf("Error: matrix malloc\n");
                return ;
            }
            map->height++;   
        }
        free(line);
    }
    close(fd);
}

t_map map(char *path)
{
    t_map map;
    
    map.textures = malloc(sizeof(char *) * 4);
    if (map.textures == NULL)
    {
        printf("Error: malloc\n");
        return ;
    }
    map.matrix = malloc(sizeof(char *) * 1);
    if (map.matrix == NULL) 
    {
        printf("Error: matrix malloc\n");
        return ;
    }
    fill_text_and_colors(&map, path);
    fill_matrix(&map, path);
    //fill_player_vars(&map, path);
    //validate_map(&map);
    printf("ceiling: %x\n", map.ceiling);
    printf("floor: %x\n", map.floor);
    printf("texture: %s\n", map.textures[NORTH]);
    printf("texture: %s\n", map.textures[SOUTH]);
    printf("texture: %s\n", map.textures[WEST]);
    printf("texture: %s\n", map.textures[EAST]);
    printf("matrix: %s\n", map.matrix[0]);
    printf("matrix: %s\n", map.matrix[1]);
    printf("matrix: %s\n", map.matrix[2]);
    printf("matrix: %s\n", map.matrix[3]);
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