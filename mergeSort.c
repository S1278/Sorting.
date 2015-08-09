/**
 * Merge Sort algorithm.
 * mergeSort.c
 */

#include <stdio.h>
#include <stdlib.h>

int* mergeSort(int *a, int n);
int* merge(int *a, int nA, int *b, int nB);

int main()
{
    int n, *a;
    printf("Number of Elements: ");
    scanf("%d", &n);
    a = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        printf("\nElemet %d: ", i + 1);
        scanf("%d", a + i);
    }
    a = mergeSort(a, n);

    printf("\nSorted!\n\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);

    printf("\n");

    return 0;
}

int* merge(int *a, int nA, int *b, int nB)
{
    /**
     * Merges two sorted arrays and returns the pointer to the new array.
     * ------------------------------------------------------------------
     * a -- pointer to the first array.
     * nA -- number of elements in array a.
     * b -- pointer to the second array.
     * nB -- number of elements in array b.
     */
    int i = 0, j = 0, k = 0;
    int *merged = (int*) malloc(sizeof(int) * (nA + nB));
    while (i < nA && j < nB)
    {
        if(a[i] < b[j]) { merged[k] = a[i]; i++; }
        else { merged[k] = b[j]; j++; }
        k++;
    }
    if(i != nA)
        while(i < nA) { merged[k] = a[i]; k++; i++; }
    else if(j != nB)
        while(j < nB) { merged[k] = b[j]; k++; j++; }

    return merged;
}

int* mergeSort(int *a, int n)
{
    /**
     * Recursively splits the array into two halves until it hits the base case.
     * Calls the merge function to merge sorted halves to one.
     * Returns the pointer to the sorted array.
     * -------------------------------------------------------------------------
     * a -- array to be sorted.
     * n -- number of elements in the array.
     */

    // Base case.
    if (n < 2) return a;

    // Sort two halves of the array and merge them.
    int *left = mergeSort(a, n / 2);
    int *right = mergeSort(a + n / 2, n - n / 2);

    return merge(left, n / 2, right, n - n / 2);
}
