#include "so_long.h"

int move_player(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->map->width || y >= game->map->height)
        return 0;
    if (game->map->map[y][x] == '1')
        return 0;
    if (game->map->map[y][x] == 'E')
    {
        if (game->collectibles == 0)
        {
            cleanup(game->map, game->mlx);
            exit(0);
        }
        return 0;
    }
    if (game->map->map[y][x] == 'C')
    {
        game->collectibles--;
        game->map->map[y][x] = '0';
    }
    game->map->map[game->player.y][game->player.x] = '0';
    game->map->map[y][x] = 'P';
    game->player.x = x;
    game->player.y = y;
    game->moves++;
    return 1;
}