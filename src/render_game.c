#include "so_long.h"

void handle_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void initialize_image(t_game *game, void **img, char **img_data, int *bpp, int *size_line, int *endian)
{
    *img = mlx_new_image(game->mlx->mlx, game->mlx->win_width, game->mlx->win_height);
    if (!*img)
        handle_error("Failed to create image");
    *img_data = mlx_get_data_addr(*img, bpp, size_line, endian);
}

t_img *select_current_img(t_game *game, char tile)
{
    switch (tile)
    {
        case 'P':
            return &game->mlx->sprites.player;
        case 'C':
            return &game->mlx->sprites.collectible;
        case '1':
            return &game->mlx->sprites.wall;
        case 'E':
            return &game->mlx->sprites.exit;
        case '0':
        default:
            return &game->mlx->sprites.empty;
    }
}

void draw_pixel(char *img_data, int pixel, unsigned int color)
{
    img_data[pixel] = color & 0xFF; // Blue
    img_data[pixel + 1] = (color >> 8) & 0xFF; // Green
    img_data[pixel + 2] = (color >> 16) & 0xFF; // Red
    img_data[pixel + 3] = (color >> 24) & 0xFF; // Alpha
}

void draw_tile(t_game *game, t_img *current_img, int x, int y, int scaled_width, int scaled_height, char *img_data, int size_line, int bpp)
{
    for (int i = 0; i < current_img->height; i++)
    {
        for (int j = 0; j < current_img->width; j++)
        {
            int win_x = x * scaled_width + j;
            int win_y = y * scaled_height + i;

            if (win_x >= game->mlx->win_width || win_y >= game->mlx->win_height)
                continue;

            unsigned int color = ((unsigned int*)current_img->addr)[i * current_img->width + j];
            int pixel = (win_y * size_line) + (win_x * (bpp / 8));
            draw_pixel(img_data, pixel, color);
        }
    }
}

void draw_all_tiles(t_game *game)
{
    int scaled_width = game->mlx->win_width / game->map->width;
    int scaled_height = game->mlx->win_height / game->map->height;
    char *img_data;
    int bpp, size_line, endian;
    void *img;

    initialize_image(game, &img, &img_data, &bpp, &size_line, &endian);

    for (int y = 0; y < game->map->height; y++)
    {
        for (int x = 0; x < game->map->width; x++)
        {
            t_img *current_img = select_current_img(game, game->map->map[y][x]);
            draw_tile(game, current_img, x, y, scaled_width, scaled_height, img_data, size_line, bpp);
        }
    }

    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, img, 0, 0);
    mlx_destroy_image(game->mlx->mlx, img);
}

void display_moves(t_game *game)
{
    char *move_str = ft_itoa(game->moves);
    if (!move_str)
        handle_error("Failed to allocate memory for move string");

    mlx_string_put(game->mlx->mlx, game->mlx->win, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx->mlx, game->mlx->win, 70, 10, 0xFFFF00, move_str);
    free(move_str);
}

void render_game(t_game *game)
{
    clear_image(game->mlx);
    draw_all_tiles(game);
    display_moves(game);
}