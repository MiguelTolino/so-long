#include "so_long.h"

int close_game(t_game *game) {
    cleanup(game->map, game->mlx);
    exit(0);
}