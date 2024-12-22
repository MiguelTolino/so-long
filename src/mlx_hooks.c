#include "so_long.h"

int close_game(t_game *game) {
    cleanup(game->map, game->mlx);
    exit(0);
}

void display_moves(t_game *game)
{
    char *move_str;

    clear_image(game->mlx);
    move_str = ft_itoa(game->moves);
    mlx_string_put(game->mlx->mlx, game->mlx->win, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx->mlx, game->mlx->win, 70, 10, 0xFFFF00, move_str);
    free(move_str);
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
        game->moves++;
        display_moves(game);
    }
    else if (keycode == 0) // A key
    {
        printf("A key pressed\n");
        // Mueve el jugador hacia la izquierda
        game->moves++;
        display_moves(game);
    }
    else if (keycode == 1) // S key
    {
        printf("S key pressed\n");
        // Mueve el jugador hacia abajo
        game->moves++;
        display_moves(game);
    }
    else if (keycode == 2) // D key
    {
        printf("D key pressed\n");
        // Mueve el jugador hacia la derecha
        game->moves++;
        display_moves(game);
    }
    return 0;
}

