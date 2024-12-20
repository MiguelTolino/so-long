#ifndef SO_LONG_H
# define SO_LONG_H



# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../lib/libft/includes/libft.h"

typedef enum e_tile
{
    EMPTY,
    WALL,
    PLAYER,
    COLLECTIBLE,
    EXIT
} t_tile;

typedef struct s_pos
{
    int x;
    int y;
} t_pos;

typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;


t_map parse_map(const char *filename);
int is_valid_path_with_collectibles(t_map *map);

#endif