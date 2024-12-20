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

int main(int argc, char *argv[]) {

    t_map map;
    if (argc != 2) {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    if (validate_map_file(argv[1]) != 0) {
        return 1;
    }

    map = parse_map(argv[1]);
    printf("Map width: %d\n", map.width);
    printf("Map height: %d\n", map.height);
    for (int i = 0; i < map.height; i++) {
        printf("%s\n", map.map[i]);
    }
    


    return 0;
}