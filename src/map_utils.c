/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 20:08:55 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int solo_falta_matrix(t_map *map)
{
    if(ft_arraylen(map->textures) < 4 || map->ceiling < 0 || map->floor < 0)
    {
        return (0);
    }   
    return (1);
}
