#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10
int calculate_distance(int dist[MAX_CITIES][MAX_CITIES], int path[], int n) {
    int total_distance = 0;
    int i;
    for ( i = 0; i < n - 1; i++) {
        total_distance += dist[path[i]][path[i + 1]];
    }
    total_distance += dist[path[n - 1]][path[0]]; 
    return total_distance;
}

void find_shortest_path(int dist[MAX_CITIES][MAX_CITIES], int path[], int visited[], int n, int current_city, int count, int *min_distance, int *best_path) {
	int i;
    if (count == n) {
        int total_distance = calculate_distance(dist, path, n);
        if (total_distance < *min_distance) {
            *min_distance = total_distance;
            for ( i = 0; i < n; i++) {
                best_path[i] = path[i];
            }
        }
        return;
    }

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[count] = i;
            find_shortest_path(dist, path, visited, n, i, count + 1, min_distance, best_path);
            visited[i] = 0;
        }
    }
}

int main() {
    int dist[MAX_CITIES][MAX_CITIES] = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 5},
        {20, 25, 30, 0, 15},
        {25, 30, 5, 15, 0}
    };

    int n = 5; 
    int path[MAX_CITIES];
    int visited[MAX_CITIES] = {0};
    int min_distance = INT_MAX;
    int best_path[MAX_CITIES];
    int i;
    visited[0] = 1;
    path[0] = 0;
    find_shortest_path(dist, path, visited, n, 0, 1, &min_distance, best_path);

    printf("The shortest path is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", best_path[i]);
    }
    printf("\n");
    printf("The minimum distance is: %d\n", min_distance);

    return 0;
}
