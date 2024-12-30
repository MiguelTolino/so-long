#include "so_long.h"

void adjust_window_size(t_game *game)
{
    int max_sprite_width = 0;
    int max_sprite_height = 0;

    // Calcular el tamaño máximo de los sprites
    max_sprite_width = fmax(max_sprite_width, game->mlx->sprites.player.width);
    max_sprite_width = fmax(max_sprite_width, game->mlx->sprites.wall.width);
    max_sprite_width = fmax(max_sprite_width, game->mlx->sprites.collectible.width);
    max_sprite_width = fmax(max_sprite_width, game->mlx->sprites.exit.width);
    max_sprite_width = fmax(max_sprite_width, game->mlx->sprites.empty.width);
    max_sprite_width = fmax(max_sprite_width, game->mlx->sprites.terrain.width);

    max_sprite_height = fmax(max_sprite_height, game->mlx->sprites.player.height);
    max_sprite_height = fmax(max_sprite_height, game->mlx->sprites.wall.height);
    max_sprite_height = fmax(max_sprite_height, game->mlx->sprites.collectible.height);
    max_sprite_height = fmax(max_sprite_height, game->mlx->sprites.exit.height);
    max_sprite_height = fmax(max_sprite_height, game->mlx->sprites.empty.height);
    max_sprite_height = fmax(max_sprite_height, game->mlx->sprites.terrain.height);

    // Ajustar el tamaño de la ventana en función del tamaño máximo de los sprites
    int new_window_width = max_sprite_width * game->map->width;
    int new_window_height = max_sprite_height * game->map->height;

    printf("Current window width: %d, Current window height: %d\n", game->mlx->win_width, game->mlx->win_height);
    printf("New window width: %d, New window height: %d\n", new_window_width, new_window_height);

    // Usar las constantes para la resolución máxima de la pantalla
    if (new_window_width > MAX_SCREEN_WIDTH) {
        new_window_width = MAX_SCREEN_WIDTH;
    }
    if (new_window_height > MAX_SCREEN_HEIGHT) {
        new_window_height = MAX_SCREEN_HEIGHT;
    }

    printf("New window width: %d, New window height: %d\n", new_window_width, new_window_height);
    printf("Max sprite width: %d, Max sprite height: %d\n", max_sprite_width, max_sprite_height);

    game->mlx->win_width = new_window_width;
    game->mlx->win_height = new_window_height;
}

void load_sprite(t_mlx *mlx, t_img *img, const char *path)
{
    int width;
    int height;

    img->img = mlx_xpm_file_to_image(mlx->mlx, (char *)path, &width, &height);
    if (img->img == NULL)
    {
        fprintf(stderr, "Error: Could not load sprite from %s\n", path);
        exit(1);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->width = width;
    img->height = height;
    printf("Loaded sprite from %s (width: %d, height: %d)\n", path, width, height);
}

void load_sprites(t_mlx *mlx, t_game *game)
{
    load_sprite(mlx, &mlx->sprites.player, PLAYER_SPRITE);
    load_sprite(mlx, &mlx->sprites.wall, WALL_SPRITE);
    load_sprite(mlx, &mlx->sprites.collectible, COLLECTIBLE_SPRITE);
    load_sprite(mlx, &mlx->sprites.exit, EXIT_SPRITE);
    load_sprite(mlx, &mlx->sprites.empty, EMPTY_SPRITE);
    load_sprite(mlx, &mlx->sprites.terrain, TERRAIN_SPRITE);
    
    adjust_window_size(game);
}