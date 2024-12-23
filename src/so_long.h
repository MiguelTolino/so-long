#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

#define HEIGHT_SCREEN 600
#define WIDTH_SCREEN 800
#define WIN_TITLE "so_long"
#define TILE_SIZE 32

#define PLAYER_SPRITE "sprites/xpm/p.xpm"
#define WALL_SPRITE "sprites/xpm/1.xpm"
#define COLLECTIBLE_SPRITE "sprites/xpm/c.xpm"
#define EXIT_SPRITE "sprites/xpm/e.xpm"
#define EMPTY_SPRITE "sprites/xpm/0.xpm"
#define TERRAIN_SPRITE "sprites/xpm/y.xpm"


enum {
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
};

typedef enum e_direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} t_direction;

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

typedef struct s_sprites
{
    t_img player;
    t_img wall;
    t_img collectible;
    t_img exit;
    t_img empty;
    t_img terrain;
} t_sprites;

typedef struct s_mlx
{
    void *mlx;
    void *win;
    t_img img;
    t_sprites sprites;
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
int  close_game(t_game *game);
void game_loop(t_game *game);
int handle_key_press(int keycode, t_game *game);
void setup_hooks(t_game *game);
void clear_image(t_mlx *mlx);
void load_sprites(t_mlx *mlx);
int update_game(t_game *game);
void draw_map(t_game *game);
void game_loop(t_game *game);

#endif