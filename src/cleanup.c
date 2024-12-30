#include "so_long.h"

// Function to free the map structure
void free_map(t_map *map) {
    for (int i = 0; i < map->height; i++) {
        free(map->map[i]);
    }
    free(map->map);
}

// Function to free all sprite images
void free_sprites(t_mlx *mlx) {
    if (mlx->sprites.player.img) {
        mlx_destroy_image(mlx->mlx, mlx->sprites.player.img);
    }
    if (mlx->sprites.wall.img) {
        mlx_destroy_image(mlx->mlx, mlx->sprites.wall.img);
    }
    if (mlx->sprites.collectible.img) {
        mlx_destroy_image(mlx->mlx, mlx->sprites.collectible.img);
    }
    if (mlx->sprites.exit.img) {
        mlx_destroy_image(mlx->mlx, mlx->sprites.exit.img);
    }
    if (mlx->sprites.empty.img) {
        mlx_destroy_image(mlx->mlx, mlx->sprites.empty.img);
    }
    if (mlx->sprites.terrain.img) {
        mlx_destroy_image(mlx->mlx, mlx->sprites.terrain.img);
    }
}

// Function to destroy MiniLibX resources
void destroy_mlx(t_mlx *mlx) {
    free_sprites(mlx);
    if (mlx->img.img) {
        mlx_destroy_image(mlx->mlx, mlx->img.img);
    }
    if (mlx->win) {
        mlx_destroy_window(mlx->mlx, mlx->win);
    }
    if (mlx->mlx) {
        free(mlx->mlx);
    }
}

// Function to clean up all resources
void cleanup(t_map *map, t_mlx *mlx) {
    free_map(map);
    destroy_mlx(mlx);
}