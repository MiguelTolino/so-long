#include "so_long.h"

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
    while (1)
    {
        mlx_loop(mlx.mlx);
    }
    
    cleanup(&map, &mlx);
    return 0;
}