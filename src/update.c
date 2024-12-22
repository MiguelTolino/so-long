#include "so_long.h"

int update_game(t_game *game)
{
    int x = game->player.x;
    int y = game->player.y;

    if (game->map->map[y][x] == 'E' && game->collectibles == 0)
    {
        printf("You win!\n");
        exit(0);
    }
    return 0;
}