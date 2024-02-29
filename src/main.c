/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:00:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/02/28 23:10:31 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int main(int argc, char **argv)
{
    t_cub3d *cub3d;
    
    if (!parse_args(&cub3d, argc, argv))
        printf("Error: wrong arguments\n");
    cub3d = init_cub3d(argv[1]);
    return (0);
}