#include "so_long.h"

t_map parse_map(const char *filename) {
    t_map map;
    int fd;
    char *line;
    int ret;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    map.width = 0;
    map.height = 0;
    map.map = NULL;

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
        if (map.width == 0) {
            map.width = ft_strlen(line);
        } else if (map.width != ft_strlen(line)) {
            printf("Error: Map is not rectangular\n");
            exit(1);
        }
        map.map = realloc(map.map, (map.height + 1) * sizeof(char *));
        map.map[map.height] = line;
        map.height++;
        if (ret == 0) {
            break;
        }
    }
    close(fd);

    return map;
}