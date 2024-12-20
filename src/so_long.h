#ifndef SO_LONG_H
# define SO_LONG_H



# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../lib/libft/includes/libft.h"

typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;


t_map parse_map(const char *filename);

#endif