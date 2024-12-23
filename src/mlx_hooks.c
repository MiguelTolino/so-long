#include "so_long.h"

int close_game(t_game *game) {
    cleanup(game->map, game->mlx);
    exit(0);
}

int handle_key_press(int keycode, t_game *game)
{
    if (keycode == 53) // Escape key
    {
        printf("Game closed\n");
        close_game(game);
    }
    else if (keycode == 13) // W key
    {
        printf("W key pressed\n");
        // Mueve el jugador hacia arriba
    }
    else if (keycode == 0) // A key
    {
        printf("A key pressed\n");
        // Mueve el jugador hacia la izquierda
    }
    else if (keycode == 1) // S key
    {
        printf("S key pressed\n");
        // Mueve el jugador hacia abajo
    }
    else if (keycode == 2) // D key
    {
        printf("D key pressed\n");
        // Mueve el jugador hacia la derecha
    }
    return 0;
}

