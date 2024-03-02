/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:29:05 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/02 12:10:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_args(int argc, char **argv)
{
    int fd;
    
    if (argc < 2 || argc > 3)
        print_error();
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
    {
        print_error();
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
        print_error();
    close(fd);
    return (1);
}