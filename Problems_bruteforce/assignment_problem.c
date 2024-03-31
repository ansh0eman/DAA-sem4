#include <stdio.h>
#include <limits.h>

#define MAX_WORKERS 3
#define MAX_TASKS 3

int costs[MAX_WORKERS][MAX_TASKS] = {
    {8, 6, 5},
    {7, 4, 3},
    {8, 7, 4}
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

int assignmen(int assignment[], int index, int total_cost) {
    if (index == MAX_WORKERS) {
        // Calculate total cost for this assignment
        for (int i = 0; i < MAX_WORKERS; i++) {
            total_cost += costs[i][assignment[i]];
        }
        return total_cost;
    }

    int min_cost = INT_MAX;
    for (int i = 0; i < MAX_TASKS; i++) {
        assignment[index] = i;
        min_cost = min(min_cost, assignmen(assignment, index + 1, total_cost));
    }
    return min_cost;
}

int main() {
    int assignment[MAX_WORKERS];
    int total_cost = assignmen(assignment, 0, 0);
    printf("Minimum total cost: %d\n", total_cost);
    return 0;
}
