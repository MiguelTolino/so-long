#include "so_long.h"

void draw_all_tiles(t_game *game)
{
    int scaled_width = game->mlx->win_width / game->map->width;
    int scaled_height = game->mlx->win_height / game->map->height;
    char *img_data;
    int bpp, size_line, endian;

    // Initialize a single image
    void *img = mlx_new_image(game->mlx->mlx, game->mlx->win_width, game->mlx->win_height);
    img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    for (int y = 0; y < game->map->height; y++)
    {
        for (int x = 0; x < game->map->width; x++)
        {
            t_img *current_img;
            switch (game->map->map[y][x])
            {
                case 'P':
                    current_img = &game->mlx->sprites.player;
                    break;
                case 'C':
                    current_img = &game->mlx->sprites.collectible;
                    break;
                case '1':
                    current_img = &game->mlx->sprites.wall;
                    break;
                case 'E':
                    current_img = &game->mlx->sprites.exit;
                    break;
                case '0':
                default:
                    current_img = &game->mlx->sprites.empty;
                    break;
            }

            // Iterate over each pixel of the sprite
            for (int i = 0; i < current_img->height; i++)
            {
                for (int j = 0; j < current_img->width; j++)
                {
                    // Calculate the position in the window
                    int win_x = x * scaled_width + j;
                    int win_y = y * scaled_height + i;
                    
                    if (win_x >= game->mlx->win_width || win_y >= game->mlx->win_height)
                        continue;

                    // Get the color from the sprite
                    unsigned int color = ((unsigned int*)current_img->addr)[i * current_img->width + j];

                    // Calculate the position in the image data
                    int pixel = (win_y * size_line) + (win_x * (bpp / 8));
                    img_data[pixel] = color & 0xFF; // Blue
                    img_data[pixel + 1] = (color >> 8) & 0xFF; // Green
                    img_data[pixel + 2] = (color >> 16) & 0xFF; // Red
                    img_data[pixel + 3] = (color >> 24) & 0xFF; // Alpha
                }
            }
        }
    }

    // Put the single image to the window
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, img, 0, 0);
    mlx_destroy_image(game->mlx->mlx, img);
}

void display_moves(t_game *game)
{
    char *move_str;

    move_str = ft_itoa(game->moves);
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