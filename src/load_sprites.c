#include "so_long.h"

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
    printf("Loaded sprite from %s\n", path);
    printf("Width: %d, Height: %d\n", width, height);
}

void load_sprites(t_mlx *mlx)
{
    load_sprite(mlx, &mlx->sprites.player, PLAYER_SPRITE);
    load_sprite(mlx, &mlx->sprites.wall, WALL_SPRITE);
    load_sprite(mlx, &mlx->sprites.collectible, COLLECTIBLE_SPRITE);
    load_sprite(mlx, &mlx->sprites.exit, EXIT_SPRITE);
    load_sprite(mlx, &mlx->sprites.empty, EMPTY_SPRITE);
    load_sprite(mlx, &mlx->sprites.terrain, TERRAIN_SPRITE);
}