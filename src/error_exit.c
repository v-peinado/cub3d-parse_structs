/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:18 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/17 20:53:22 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void print_error(char *err_msg)
{
    //perror(err_msg);
    printf("Error: %s", err_msg);
    exit(EXIT_FAILURE);
}

void free_cub3d(t_cub3d *cub3d)
{
    int	i;

	i = -1;
    printf("------------free cub3d----------------\n");
    printf("height: %d\n", cub3d->map->height);
	while (++i < cub3d->map->height)
		free(cub3d->map->matrix[i]);
	free(cub3d->map->matrix);
    i = -1;
    while (++i < 4)
        free(cub3d->map->textures[i]);
    free(cub3d->map->textures);
    free(cub3d->map);
    free(cub3d);
}