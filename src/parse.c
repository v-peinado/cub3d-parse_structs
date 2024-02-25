/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:29:05 by vpeinado          #+#    #+#             */
/*   Updated: 2024/02/25 14:32:22 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_args(t_cub3d *cub3d, int argc, char **argv)
{
    int fd;
    
    if (argc < 2 || argc > 3)
    {
        printf("Error\n");
        return (0);
    }
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
    {
        printf("Error: not a cub file\n");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        printf("Error: open map\n");
        return (0);
    }
    close(fd);
    return (1);
}