#include "so_long.h"

// Function to count collectibles
int count_collectibles(t_map *map) {
    int count = 0;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (map->map[i][j] == 'C') {
                count++;
            }
        }
    }
    return count;
}

// Function to find player position
t_pos find_player(t_map *map) {
    t_pos pos;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (map->map[i][j] == 'P') {
                pos.x = j;
                pos.y = i;
                return pos;
            }
        }
    }
    pos.x = -1;
    pos.y = -1;
    return pos;
}

// Helper function for DFS to find a valid path
int dfs_collect(t_map *map, int x, int y, int *collectibles, int **visited) {
    // Check boundaries and if the cell is a wall or already visited
    if (x < 0 || x >= map->height || y < 0 || y >= map->width || 
        map->map[x][y] == '1' || visited[x][y]) {
        return 0;
    }

    // Mark current cell as visited
    visited[x][y] = 1;

    // If we found a collectible, decrease the counter
    if (map->map[x][y] == 'C') {
        (*collectibles)--;
    }

    // If we reach the exit and have collected all collectibles
    if (map->map[x][y] == 'E' && *collectibles == 0) {
        return 1;
    }

    // Recursively explore all four directions
    if (dfs_collect(map, x + 1, y, collectibles, visited) ||
        dfs_collect(map, x - 1, y, collectibles, visited) ||
        dfs_collect(map, x, y + 1, collectibles, visited) ||
        dfs_collect(map, x, y - 1, collectibles, visited)) {
        return 1;
    }

    // If this path doesn't work, restore collectible if we found one here
    if (map->map[x][y] == 'C') {
        (*collectibles)++;
    }

    return 0;
}

// Function to check if there is a valid path collecting all collectibles
int is_valid_path_with_collectibles(t_map *map) {
    int **visited = malloc(map->height * sizeof(int *));
    for (int i = 0; i < map->height; i++) {
        visited[i] = calloc(map->width, sizeof(int));
    }

    t_pos player = find_player(map);
    if (player.x == -1 || player.y == -1) {
        printf("Error: No player position 'P' found in the map\n");
        return 0;
    }

    int collectibles = count_collectibles(map);
    int result = dfs_collect(map, player.y, player.x, &collectibles, visited);

    // Free visited array
    for (int i = 0; i < map->height; i++) {
        free(visited[i]);
    }
    free(visited);

    return result;
}