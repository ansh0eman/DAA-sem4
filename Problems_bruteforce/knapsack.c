#include <stdio.h>

int Max(int a, int b) {
    return a > b ? a : b;
}

int getMaxVal(int n, int w[], int v[], int c, int i, int *included) {
    int Vinclude, Vexclude;
    if (i == n || c <= 0) {
        return 0;
    }

    if (w[i] <= c) {
        Vinclude = v[i] + getMaxVal(n, w, v, c - w[i], i + 1, included);
        Vexclude = getMaxVal(n, w, v, c, i + 1, included);
        if (Vinclude > Vexclude) {
            included[i] = 1;
            return Vinclude;
        } else {
            included[i] = 0;
            return Vexclude;
        }
    } else {
        included[i] = 0;
        return getMaxVal(n, w, v, c, i + 1, included);
    }
}

int main() {
    int n = 4;
    int w[100] = {2, 5, 10, 5};
    int v[100] = {20, 30, 50, 10};
    int capacity = 16;
    int included[100] = {0};

    int maxValue = getMaxVal(n, w, v, capacity, 0, included);
    printf("The maximum value: %d\n", maxValue);
    printf("Weights included: ");
    for (int i = 0; i < n; i++) {
        if (included[i]) {
            printf("%d ", w[i]);
        }
    }
    printf("\n");

    return 0;
}
