#include "so_long.h"

int close_game(t_game *game) {
    cleanup(game->map, game->mlx);
    exit(0);
}

int handle_key_press(int keycode, t_game *game)
{
    if (keycode == 53) // Escape key
    {
        close_game(game);
    }
    else if (keycode == 13) // W key
    {
        move_player(game, game->player.x, game->player.y - 1);
    }
    else if (keycode == 0) // A key
    {
        move_player(game, game->player.x - 1, game->player.y);
    }
    else if (keycode == 1) // S key
    {
        move_player(game, game->player.x, game->player.y + 1);
    }
    else if (keycode == 2) // D key
    {
        move_player(game, game->player.x + 1, game->player.y);
    }
    return 0;
}

