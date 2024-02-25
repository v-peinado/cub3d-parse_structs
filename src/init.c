/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:56:30 by vpeinado          #+#    #+#             */
/*   Updated: 2024/02/25 15:35:09 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fill_map_struct(t_map *map, int fd)
{
    //usar gnl para leer el archivo
    // linea a linea comprobar cual contiene el mapa
    // rellenar el char **matrix con el mapa
    // rellenar el resto de la estructura, posicion de jugador, orientacion, color del suelo y techo
}

t_map map(char *path)
{
    t_map map;
    int fd;
    fd = open(path, O_RDONLY);
    if(fd < 0)
    {
        printf("Error: open map\n");
        return ;
    }
    fill_matrix_struct(&map, fd);
    close(fd);
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