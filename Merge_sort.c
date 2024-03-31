#include <stdio.h>

void printArray(int A[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void merge(int A[], int lo, int mid, int hi)
{
    int i, j, k;
    int B[100];
    i = lo;
    j = mid + 1;
    k = lo;
    while (i <= mid && j <= hi)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= hi)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for(i =lo; i<=hi; i++){
        A[i]= B[i];
    }
}

void mergesort(int A[], int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo + hi) / 2;
        mergesort(A, lo, mid);
        mergesort(A, mid + 1, hi);
        merge(A, lo, mid, hi);
    }
}

int main()
{
    int A[] = {9, 14, 4, 8, 7, 5, 6};
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A,n);
    mergesort(A, 0, n-1);
    printArray(A, n);
}