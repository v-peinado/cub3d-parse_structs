/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:29:05 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/05 19:20:02 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_args(int argc, char **argv)
{
    int fd;
    
    if (argc != 2)
        print_error("Los argumentos deben ser 2");
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
    {
        print_error("el mapa debe ser un archivo .cub");
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
        print_error("No se pudo abrir el archivo");
    close(fd);
    return (1);
}