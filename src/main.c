/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:00:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/05 19:17:40 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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