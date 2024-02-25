#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map 
{
	int					width;
	int					height;
	int					player_x;
	int					player_y;
	char				player_dir;
	unsigned int		floor;
	unsigned int		ceiling;
	char			**matrix;
}				t_map;

typedef struct s_cub3d
{
	t_map				map;
}			t_cub3d;

#endif