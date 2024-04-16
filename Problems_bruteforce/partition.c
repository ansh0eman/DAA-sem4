#include <stdio.h>
#include <stdbool.h>

void print_subset(int arr[], int n, bool is_subset[]) {
    printf("Subset 1 : ");
    for (int i = 0; i < n; i++) {
        if (is_subset[i]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("Subset 2 : ");
    for (int i = 0; i < n; i++) {
        if (!is_subset[i]) {
            printf("%d ", arr[i]);
        }
    }
}

bool is_equal_sum_partition_possible(int arr[], int n, int index, int sum, bool is_subset[]) {
    if (sum == 0) {
        print_subset(arr, n, is_subset);
        return true;
    }
    if (index >= n || sum < 0) {
        return false;
    }
    is_subset[index] = true; //include a[index] in subset
    if (is_equal_sum_partition_possible(arr, n, index + 1, sum - arr[index], is_subset)) {
        return true;
    }
    is_subset[index] = false; //dont include a[index] in subset
    return is_equal_sum_partition_possible(arr, n, index + 1, sum, is_subset);
}

int main() {
    int arr[] = {6, 3, 5, 11, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }
    if (total_sum % 2 != 0) {
        printf("Equal sum partition is not possible\n");
        return 0;
    }
    bool is_subset[n];
    for (int i = 0; i < n; i++) {
        is_subset[i] = false;
    }
    int sum = total_sum / 2;
    if (!is_equal_sum_partition_possible(arr, n, 0, sum, is_subset)) {
        printf("Equal sum partition is not possible\n");
    }
    return 0;
}
