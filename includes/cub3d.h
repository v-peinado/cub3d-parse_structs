#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define SOUTH		0
# define NORTH		1
# define WEST		2
# define EAST		3

typedef struct s_map 
{
	int					width;
	int					height;
	int					player_x;
	int					player_y;
	char				player_dir;
	unsigned int		floor;
	unsigned int		ceiling;
	char				**textures;
	char				**matrix;
}				t_map;

typedef struct s_cub3d
{
	t_map				*map;
}			t_cub3d;

t_cub3d *init_cub3d(char *path);
int parse_args(int argc, char **argv);
void print_error(char *err_msg);

#endif