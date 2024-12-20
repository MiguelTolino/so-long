#include "so_long.h"

// Function to validate the map file extension
int validate_map_file(const char *filename) {
    const char *extension = ft_strrchr(filename, '.');
    if (!extension || ft_strncmp(extension, ".ber", 4) != 0) {
        printf("Error: %s is not a valid map file\n", filename);
        return 1;
    }
    return 0;
}

void free_map(t_map *map) {
    int i;

    i = 0;
    while (i < map->height) {
        free(map->map[i]);
        i++;
    }
    free(map->map);
}

void run_mlx(t_mlx *mlx) {
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
    mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}

int main(int argc, char *argv[]) {

    t_map map;
    t_mlx mlx;
    if (argc != 2) {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    if (validate_map_file(argv[1]) != 0) {
        return 1;
    }

    map = parse_map(argv[1]);
    if (map.map == NULL) {
        return 1;
    }

    run_mlx(&mlx);
    mlx_loop(mlx.mlx);
    free_map(&map);
    return 0;
}