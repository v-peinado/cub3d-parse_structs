/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:31 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 20:15:51 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void validate_chars(t_map *map)
{
    int i;
    int j;
    int len;
    
    i = 0;
    j = 0;

    while (i < map->height)
    {    
        len = ft_strlen(map->matrix[i]);
        j = 0;
        while (j < len)
        {
            if (map->matrix[i][j] == ' ')
                map->matrix[i][j] = '1';
            if (map->matrix[i][j] != '1' && map->matrix[i][j] != '0'
                && map->matrix[i][j] != 'N'
                && map->matrix[i][j] != 'S' && map->matrix[i][j] != 'E'
                && map->matrix[i][j] != 'W')
                print_error("El mapa contiene caracteres invalidos");
            j++;
        }
        i++;
    }
}

void fill_map_append(t_map *map, char *line, int i)
{
       if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W'))
			fill_texture(map, line);
		else if ((line[i] == 'C' || line[i] == 'F'))
			fill_color(map, line);
        else if (solo_falta_matrix(map))
        {
            map->matrix = ft_arraypush(map->matrix, ft_strdup(line));
            if (!map->matrix)
                print_error("No se ha podido crear la matriz");
            if ((int)ft_strlen(line) > map->width)
                map->width = (int)ft_strlen(line);
            map->height++;
        }
        else
        {
            if (map->ceiling < 0)
                printf("Error: No se ha definido el color del techo\n");
            if (map->floor < 0)
                printf("Error: No se ha definido el color del suelo\n");
            if (ft_arraylen(map->textures) < 4)
                printf("Error: No se han definido todas las texturas\n");
            print_error("El mapa debe ser el ultimo elemento del archivo .cub\n");
        }    
}

void fill_map(t_map *map, char *path)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        print_error("No se puedo abrir el archivo");
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if(solo_falta_matrix(map))
            line = ft_strtrim(line, "\t\n");
        else
            line = ft_strtrim(line, " \t\n");
        while(line[i] == ' ')
            i++;
        if (line[i] == '\0')
            continue;
        fill_map_append(map, line, i);
        free(line);
    }
    close(fd);
}

t_map *map(char *path)
{
    t_map *map;

    map = ft_calloc(1, sizeof(t_map));
    map->player_dir = '0';
    map->ceiling = -1;
    map->floor = -1;
    map->textures = ft_calloc(4, sizeof(char *));
    if (map->textures == NULL)
        print_error("No se ha podido crear el array de texturasr");
    map->matrix = ft_calloc(1, sizeof(char *));
    if (map->matrix == NULL) 
        print_error("No se ha podido crear la matriz");
    fill_map(map, path);
    fill_player_vars(map);
    validate_text(map->textures);
    validate_chars(map);
    validate_player(map);
    validate_size(map);
    map_closed(map);
    return (map);
}
