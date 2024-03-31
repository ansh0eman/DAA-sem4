#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices (cities)

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int visited[], int pos, int n, int count) {
    if (count == n && graph[pos][0]) {
        return graph[pos][0];
    }

    int min_cost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if (visited[city] == 0 && graph[pos][city]) {
            visited[city] = 1;
            int new_cost = graph[pos][city] + tsp(visited, city, n, count + 1);
            min_cost = min(min_cost, new_cost);
            visited[city] = 0; // Backtrack
        }
    }
    return min_cost;
}

int main() {
    int visited[V] = {0};
    visited[0] = 1; // Start with the first city
    printf("Minimum cost: %d\n", tsp(visited, 0, V, 1));
    return 0;
}
