#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void bubble_sort(char arr[][50], int n) {
    int i, j;
    char temp[50];
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

int main() {
    char strings[][50] = {"banana", "apple", "orange", "grape", "pineapple"};
    int n = sizeof(strings) / sizeof(strings[0]);
    
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    
    bubble_sort(strings, n);
    
    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    
    return 0;
}
