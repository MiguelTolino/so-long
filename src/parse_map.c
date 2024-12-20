#include "so_long.h"

// Function to open the map file
int open_map_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    return fd;
}

// Function to initialize the map structure
void init_map(t_map *map) {
    map->width = 0;
    map->height = 0;
    map->map = NULL;
}

// Function to read and parse the map file
void read_map_file(int fd, t_map *map, const char *filename) {
    char *line;
    int ret;

    while (1) {
        ret = get_next_line(fd, &line);
        printf("line: %s\n", line);
        if (ret == -1) {
            printf("Error: Could not read file %s\n", filename);
            exit(1);
        }
        if (ft_strncmp(line, "", 1) == 0) {
            break;
        }
        if (map->width == 0) {
            map->width = ft_strlen(line);
        } else if (map->width != ft_strlen(line)) {
            printf("Error: Map is not rectangular\n");
            exit(1);
        }
        map->map = realloc(map->map, (map->height + 1) * sizeof(char *));
        map->map[map->height] = line;
        map->height++;
        if (ret == 0) {
            break;
        }
    }
}


// Function to check if the map is closed
int is_map_closed(t_map *map) {
    // Check top and bottom borders
    for (int i = 0; i < map->width; i++) {
        if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1') {
            return 0;
        }
    }

    // Check left and right borders
    for (int i = 0; i < map->height; i++) {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1') {
            return 0;
        }
    }

    return 1;
}

// Main function to parse the map
t_map parse_map(const char *filename) {
    t_map map;
    int fd;

    fd = open_map_file(filename);
    init_map(&map);
    read_map_file(fd, &map, filename);
    close(fd);

    if (!is_map_closed(&map)) {
        printf("Error: Map is not closed\n");
        exit(1);
    }

    if (!is_valid_path_with_collectibles(&map)) {
        printf("Error: No valid path to collect all collectibles and reach the exit\n");
        exit(1);
    }

    return map;
}