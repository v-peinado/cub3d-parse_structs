/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:18 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/12 19:38:41 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void print_error(char *err_msg)
{
    //perror(err_msg);
    printf("Error: %s", err_msg);
    exit(EXIT_FAILURE);
}