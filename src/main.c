/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:00:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 19:34:15 by vpeinado         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_cub3d *cub3d;
    
    if (!parse_args(argc, argv))
        print_error("Los argumentos no son validos");
    cub3d = init_cub3d(argv[1]);
    if (!cub3d)
        print_error("No se pudo crear la estructura cub3d");
    exit(EXIT_SUCCESS);
}