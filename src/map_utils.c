/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/18 21:23:50 by vpeinado         ###   ########.fr       */
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

char	*ft_strtrim2(char *s1, char *set) 
{
	char	*tmp;
	
	tmp = ft_strtrim(s1, set);
	free(s1);
	return (tmp);
}

int is_empty_line_and_free(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t')
            return (0);
        i++;
    }
    free(line);
    return (1);
}

int    ft_isdigit_string2(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}