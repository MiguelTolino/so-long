#include "so_long.h"

// Function to initialize MiniLibX and create a window
void run_mlx(t_mlx *mlx) {
    mlx->mlx = mlx_init();
    if (mlx->mlx == NULL) {
        perror("Error: Could not initialize mlx");
        exit(1);
    }

    mlx->win = mlx_new_window(mlx->mlx, WIDTH_SCREEN, HEIGHT_SCREEN, WIN_TITLE);
    if (mlx->win == NULL) {
        perror("Error: Could not create window");
        free(mlx->mlx);
        exit(1);
    }

    mlx->img.img = mlx_new_image(mlx->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
    if (mlx->img.img == NULL) {
        perror("Error: Could not create image");
        mlx_destroy_window(mlx->mlx, mlx->win);
        free(mlx->mlx);
        exit(1);
    }

    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
    if (mlx->img.addr == NULL) {
        perror("Error: Could not get image data address");
        mlx_destroy_image(mlx->mlx, mlx->img.img);
        mlx_destroy_window(mlx->mlx, mlx->win);
        free(mlx->mlx);
        exit(1);
    }
}