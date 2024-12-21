#include "so_long.h"

t_game init_game(t_game *game, t_map *map, t_mlx *mlx)
{
    game->map = map;
    game->mlx = mlx;
    game->player.x = 0;
    game->player.y = 0;
    game->collectibles = 0;
    game->moves = 0;
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
    init_game(&game, &map, &mlx);

    while (1)
    {
        my_mlx_pixel_put(&mlx.img, WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2, 0x00FF0000);
        mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
        mlx_loop(mlx.mlx);
    }
    cleanup(&map, &mlx);
    return 0;
}