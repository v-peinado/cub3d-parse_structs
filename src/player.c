/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:08:29 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 20:08:30 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void validate_player(t_map *map)
{
    if (map->player_dir == '0')
        print_error("No se ha definido la posicion del jugador");
    if (map->player_x == -1 || map->player_y == -1)
        print_error("No se ha definido la posicion del jugador");
}

void fill_player_vars(t_map *map)
{
    size_t  i;
    int     j;
    size_t  len;
    
    j = 0;
    while (j < map->height)
    {
        i = 0;
        len = ft_strlen(map->matrix[j]);
        while (i < len)
        {
            if (map->matrix[j][i] == 'N' || map->matrix[j][i] == 'S'
                || map->matrix[j][i] == 'E' || map->matrix[j][i] == 'W')
            {
                map->player_y = j;
                map->player_x = i;
                if (map->player_dir == '0')
                    map->player_dir = map->matrix[j][i];
                else
                    print_error("Solo se puede tener una posicion de jugador");
            }
            i++;
        }
        j++;
    }
}