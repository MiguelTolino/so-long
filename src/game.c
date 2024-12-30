#include "so_long.h"

void init_game(t_game *game, t_map *map, t_mlx *mlx)
{
    game->map = map;
    game->mlx = mlx;
    mlx->win_height = HEIGHT_SCREEN;
    mlx->win_width = WIDTH_SCREEN;
    game->player.x = 0;
    game->player.y = 0;
    game->collectibles = 0;
    game->moves = 0;
    init_mlx(mlx);

    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == 'P')
            {
                game->player.x = x;
                game->player.y = y;
            }
            else if (map->map[y][x] == 'C')
            {
                game->collectibles++;
            }
        }
    }
}

int game_loop(t_game *game)
{
    render_game(game);
    mlx_hook(game->mlx->win, ON_KEYDOWN, 0, handle_key_press, game);
    mlx_hook(game->mlx->win, ON_DESTROY, 0, close_game, game);
    return 0;
}
