#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

#define HEIGHT_SCREEN 600
#define WIDTH_SCREEN 800
#define WIN_TITLE "so_long"

typedef enum e_direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} t_direction;

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

typedef struct s_img
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_mlx
{
    void *mlx;
    void *win;
    t_img img;
} t_mlx;

typedef struct s_game
{
    t_map *map;
    t_mlx *mlx;
    t_pos player;
    int collectibles;
    int moves;
} t_game;


t_map parse_map(const char *filename);
int is_valid_path_with_collectibles(t_map *map);
void free_map(t_map *map);
void destroy_mlx(t_mlx *mlx);
void cleanup(t_map *map, t_mlx *mlx);
void run_mlx(t_mlx *mlx);
void my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif