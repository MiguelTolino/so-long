#include "so_long.h"

void init_game(t_game *game, t_map *map, t_mlx *mlx)
{
    game->map = map;
    game->mlx = mlx;
    game->player.x = 0;
    game->player.y = 0;
    game->collectibles = 0;
    game->moves = 0;

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

// Function to validate the map file extension
int validate_map_file(const char *filename)
{
    const char *extension = ft_strrchr(filename, '.');
    if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
    {
        perror("Error: Invalid map file");
        return 1;
    }
    return 0;
}

void game_loop(t_game *game)
{
    draw_map(game);
    mlx_hook(game->mlx->win, ON_KEYDOWN, 0, handle_key_press, game);
    mlx_hook(game->mlx->win, ON_DESTROY, 0, close_game, game);
    //mlx_loop_hook(game->mlx->mlx, update_game, &game);
    mlx_loop(game->mlx->mlx);
}

int main(int argc, char *argv[])
{
    t_map map;
    t_mlx mlx;
    t_game game;

    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    if (validate_map_file(argv[1]) != 0)
    {
        return 1;
    }

    map = parse_map(argv[1]);
    if (map.map == NULL)
    {
        return 1;
    }

    run_mlx(&mlx);
    load_sprites(&mlx);
    init_game(&game, &map, &mlx);
    while (1)
    {
        game_loop(&game);
    }

    cleanup(&map, &mlx);
    return 0;
}