#include "so_long.h"

// Function to put a pixel on the screen
void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

// Function to clear the image
void clear_image(t_mlx *mlx)
{
    mlx_clear_window(mlx->mlx, mlx->win);
    mlx_destroy_image(mlx->mlx, mlx->img.img);
    mlx->img.img = mlx_new_image(mlx->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}