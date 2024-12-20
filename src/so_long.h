#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

#define HEIGHT 600
#define WIDTH 800

typedef enum e_tile
{
    EMPTY,
    WALL,
    PLAYER,
    COLLECTIBLE,
    EXIT
} t_tile;

typedef struct s_pos
{
    int x;
    int y;
} t_pos;

typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;

typedef struct s_mlx
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_mlx;


t_map parse_map(const char *filename);
int is_valid_path_with_collectibles(t_map *map);

#endif