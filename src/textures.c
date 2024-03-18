/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:08:48 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/18 21:24:46 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fill_texture(t_map *map, char *line)
{
    while(*line == ' ')
        line++;
    if (((line[0] == 'N' && line[1] == ' ') || (line[0] == 'N' && line[1] == 'O'))
        && map->textures[NORTH] == NULL)
        map->textures[NORTH] = ft_strtrim(line, "NO \t");
    else if (((line[0] == 'S' && line[0] == ' ') || (line[0] == 'S' && line[1] == 'O'))
        && map->textures[SOUTH] == NULL)
        map->textures[SOUTH] = ft_strtrim(line, "SO \t");
    else if (((line[0] == 'W' && line[1] == ' ') || (line[0] == 'W' && line[1] == 'E'))
        && map->textures[WEST] == NULL)
        map->textures[WEST] = ft_strtrim(line, "WE \t");
    else if (((line[0] == 'E' && line[1] == ' ') || (line[0] == 'E' && line[1] == 'A'))
        && map->textures[EAST] == NULL)
        map->textures[EAST] = ft_strtrim(line, "EA \t");
    else
        print_error("La textura solo se puede definir una vez por cada tipo de textura");
}

void validate_text(char **textures_arr)
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        if (ft_strncmp(textures_arr[i] + ft_strlen(textures_arr[i]) - 4, ".xpm", 4))
        {
            print_error("Las texturas deben ser archivos .xpm");
        }
        if(open(textures_arr[i], O_RDONLY) < 0)
        {
            close(open(textures_arr[i], O_RDONLY));
            print_error("No se ha podido abrir el archivo de textura");
        }
        i++;
    }      
}