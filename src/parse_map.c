#include "so_long.h"
#include <errno.h>
#include <string.h>

// Function to open the map file
int open_map_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error: Could not open file");
        exit(1);
    }
    return fd;
}

// Function to initialize the map structure
void init_map(t_map *map)
{
    map->width = 0;
    map->height = 0;
    map->map = NULL;
}

// Function to read and parse the map file
void read_map_file(int fd, t_map *map)
{
    char *line;
    int ret;

    while (1)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
        {
            perror("Error: Could not read file");
            exit(1);
        }
        if (ft_strncmp(line, "", 1) == 0)
        {
            break;
        }
        if (map->width == 0)
        {
            map->width = ft_strlen(line);
        }
        else if (map->width != (int)ft_strlen(line))
        {
            perror("Error: Map is not rectangular");
            exit(1);
        }
        map->map = realloc(map->map, (map->height + 1) * sizeof(char *));
        map->map[map->height] = line;
        map->height++;
        if (ret == 0)
        {
            break;
        }
    }
}

// Function to check if the map is closed
int is_map_closed(t_map *map)
{
    // Check top and bottom borders
    for (int i = 0; i < map->width; i++)
    {
        if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
        {
            return 0;
        }
    }

    // Check left and right borders
    for (int i = 0; i < map->height; i++)
    {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
        {
            return 0;
        }
    }

    return 1;
}

// Function to validate map elements
int validate_map_elements(t_map *map)
{
    int exit_count = 0;
    int player_count = 0;
    int collectible_count = 0;

    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            char c = map->map[i][j];
            if (c == 'E')
                exit_count++;
            else if (c == 'P')
                player_count++;
            else if (c == 'C')
                collectible_count++;
            else if (c != '0' && c != '1')
            {
                perror("Error: Invalid character in map");
                return 0;
            }
        }
    }

    if (exit_count != 1)
    {
        perror("Error: Map must have exactly one exit (E)");
        return 0;
    }
    if (player_count != 1)
    {
        perror("Error: Map must have exactly one player (P)");
        return 0;
    }
    if (collectible_count < 1)
    {
        perror("Error: Map must have at least one collectible (C)");
        return 0;
    }

    return 1;
}

// Function to handle map validation and error messages
void validate_map(t_map *map)
{
    if (!is_map_closed(map))
    {
        perror("Error: Map is not closed");
        exit(1);
    }

    if (!validate_map_elements(map))
    {
        perror("Error: Invalid map elements");
        exit(1);
    }

/*     if (!is_valid_path_with_collectibles(map))
    {
        perror("Error: No valid path to collect all collectibles and reach the exit");
        exit(1);
    } */
}

// Update parse_map function to include the new validation
t_map parse_map(const char *filename)
{
    t_map map;
    int fd;

    fd = open_map_file(filename);
    init_map(&map);
    read_map_file(fd, &map);
    close(fd);

    validate_map(&map);

    return map;
}