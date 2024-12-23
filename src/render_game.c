#include "so_long.h"

void draw_tile(t_game *game, t_img *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, img->img, x * TILE_SIZE, y * TILE_SIZE);
}

void display_moves(t_game *game)
{
    char *move_str;

    move_str = ft_itoa(game->moves);
    mlx_string_put(game->mlx->mlx, game->mlx->win, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx->mlx, game->mlx->win, 70, 10, 0xFFFF00, move_str);
    free(move_str);
    game->moves++;
}

void draw_map(t_game *game)
{
    char tile;

    for (int y = 0; y < game->map->height; y++)
    {
        for (int x = 0; x < game->map->width; x++)
        {
            tile  = game->map->map[y][x];
            switch (tile)
            {
            case '1':
                draw_tile(game, &game->mlx->sprites.wall, x, y);
                break;
            case 'P':
                draw_tile(game, &game->mlx->sprites.player, x, y);
                break;
            case 'C':
                draw_tile(game, &game->mlx->sprites.collectible, x, y);
                break;
            case 'E':
                draw_tile(game, &game->mlx->sprites.exit, x, y);
                break;
            case '0':
                draw_tile(game, &game->mlx->sprites.empty, x, y);
                break;
            default:
                break;
            }
        }
    }
}

void render_game(t_game *game)
{
    clear_image(game->mlx);
    draw_map(game);
    display_moves(game);
}