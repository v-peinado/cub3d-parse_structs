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
	int		floor;
	int		ceiling;
	char				**textures;
	char				**matrix;
}				t_map;

typedef struct s_cub3d
{
	t_map				*map;
}			t_cub3d;

t_cub3d *init_cub3d(char *path);
t_map *map(char *path);
int parse_args(int argc, char **argv);
void print_error(char *err_msg);
void fill_map(t_map *map, char *path);
void fill_map_append(t_map *map, char *line, int i);
void validate_chars(t_map *map);
void map_closed(t_map *map);
void floodfill(t_map *map, int **visited, int x, int y);
void validate_size(t_map *map);
void fill_player_vars(t_map *map);
void validate_player(t_map *map);
void fill_color(t_map *map, char *line);
int rgb_to_hex(int *rgb);
int *take_rgb(char *line);
int rgb_range(int rgb);
int solo_falta_matrix(t_map *map);
void fill_texture(t_map *map, char *line);
void validate_text(char **textures_arr);

#endif