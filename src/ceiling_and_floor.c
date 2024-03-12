/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:08:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 20:08:43 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rgb_range(int rgb)
{
    if (rgb < 0 || rgb > 255)
        return (1);
    return (0);
}

int *take_rgb(char *line)
{
    int *rgb;
    char **strs;
    
    rgb = malloc(sizeof(int) * 3);
    if (!rgb)
        return (NULL);
    line = ft_strtrim(line, "CF \t");
    strs = ft_split(line, ',');
    if (!strs)
        return (NULL);
    if (ft_arraylen(strs) != 3
        || !ft_isdigit_string(ft_strtrim(strs[0], " \t"))
        || !ft_isdigit_string(ft_strtrim(strs[1], " \t"))
        || !ft_isdigit_string(ft_strtrim(strs[2], " \t")))
            print_error("El color debe tener 3 componentes, compuestas de numeros");
    rgb[0] = ft_atoi(strs[0]);
    rgb[1] = ft_atoi(strs[1]);
    rgb[2] = ft_atoi(strs[2]);
    if (rgb_range(rgb[0]) || rgb_range(rgb[1]) || rgb_range(rgb[2]))
        print_error("Debe ser rgb valido, 255 < 0");
    ft_free_strs(strs);
    return (rgb);
}

int rgb_to_hex(int *rgb)
{
    int hex;
    
    hex = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
    return (hex);
}

void fill_color(t_map *map, char *line)
{
    int *rgb;
    
    if (line[0] == 'C')
    {
        rgb = take_rgb(line);
        map->ceiling = rgb_to_hex(rgb);
    }
    if (line[0] == 'F')
    {
        rgb = take_rgb(line);
        map->floor = rgb_to_hex(rgb);
    }
}