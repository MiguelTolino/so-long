#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#include "../lib/libft/includes/libft.h"
#include "../lib/minilibx_opengl/mlx.h"

#define HEIGHT_SCREEN 600
#define WIDTH_SCREEN 800
#define MAX_SCREEN_WIDTH 1200
#define MAX_SCREEN_HEIGHT 600
#define WIN_TITLE "so_long"

//#define BASIC
//#define BONUS
//#define BONUS2

#define PLAYER_SPRITE "sprites/xpm/p.xpm"
#define WALL_SPRITE "sprites/xpm/1.xpm"
#define COLLECTIBLE_SPRITE "sprites/xpm/c.xpm"
#define EXIT_SPRITE "sprites/xpm/e.xpm"
#define EMPTY_SPRITE "sprites/xpm/0.xpm"
#define TERRAIN_SPRITE "sprites/xpm/y.xpm"

// Define sprite paths based on compilation type
#if defined(BASIC)
#define PLAYER_SPRITE "textures/basic/player.xpm"
#define WALL_SPRITE "textures/basic/end_bg.xpm"
#define COLLECTIBLE_SPRITE "textures/basic/coin.xpm"
#define EXIT_SPRITE "textures/basic/cursor.xpm"
#define EMPTY_SPRITE "textures/basic/map.xpm"
#define TERRAIN_SPRITE "textures/basic/bg.xpm"
#elif defined(BONUS)
#define PLAYER_SPRITE "textures/player_01.xpm"
#define WALL_SPRITE "textures/wall_01.xpm"
#define COLLECTIBLE_SPRITE "textures/plant_01.xpm"
#define EXIT_SPRITE "textures/door_01.xpm"
#define EMPTY_SPRITE "textures/wall_02.xpm"
#define TERRAIN_SPRITE "textures/wall_02.xpm"
#elif defined(BONUS2)
#define PLAYER_SPRITE "bonus2_textures/player_02.xpm"
#define WALL_SPRITE "bonus2_textures/wall_02.xpm"
#define COLLECTIBLE_SPRITE "bonus2_textures/plant_02.xpm"
#define EXIT_SPRITE "bonus2_textures/door_02.xpm"
#define EMPTY_SPRITE "bonus2_textures/wall_03.xpm"
#define TERRAIN_SPRITE "bonus2_textures/wall_03.xpm"
#endif

enum
{
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
};

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
    int width;
    int height;
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
    int win_width;
    int win_height;

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
int close_game(t_game *game);
int handle_key_press(int keycode, t_game *game);
void setup_hooks(t_game *game);
void clear_image(t_mlx *mlx);
void load_sprites(t_mlx *mlx);
int update_game(t_game *game);
void draw_map(t_game *game);
int game_loop(t_game *game);
void render_game(t_game *game);
int move_player(t_game *game, int x, int y);
void init_game(t_game *game, t_map *map, t_mlx *mlx);
void print_game_state(t_game *game);
void init_mlx(t_mlx *mlx);
void create_window_and_image(t_mlx *mlx);
void adjust_window_size(t_game *game);

#endif