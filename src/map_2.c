/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:07:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 20:07:56 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void validate_size(t_map *map)
{
    if (map->width < 3 || map->height < 3)
        print_error("El mapa debe tener al menos 3x3");
}

void floodfill(t_map *map, int **visited, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        print_error("El mapa no esta cerrado");
    if (map->matrix[y][x] == '1' || visited[y][x])
        return ;
    visited[y][x] = 1;
    floodfill(map, visited, x + 1, y);
    floodfill(map, visited, x - 1, y);
    floodfill(map, visited, x, y + 1);
    floodfill(map, visited, x, y - 1);
}

void map_closed(t_map *map)
{
    int **visited;
    int i;
    
    visited = ft_calloc(map->height, sizeof(int *));
    if (!visited)
        print_error("No se ha podido crear la matriz de visitados");
    i = 0;
    while (i < map->height)
    {
        visited[i] = ft_calloc(map->width, sizeof(int));
        if (!visited[i])
            print_error("No se ha podido crear la matriz de visitados");
        i++;
    }
    floodfill(map, visited, map->player_x, map->player_y);
}