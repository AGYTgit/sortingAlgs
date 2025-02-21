#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quickSort(int* arr, int arrLen, int pivotIndex) {
    if (arrLen <= 1) {
        return;
    }

    int pivot = arr[pivotIndex];

    int* left = malloc((arrLen - 1) * sizeof(int));
    int lLen = 0;
    int* right = malloc((arrLen - 1) * sizeof(int));
    int rLen = 0;

    for (int i = 0; i < arrLen - 1; i++) {
        if (arr[i] < pivot) {
            left[lLen++] = arr[i];
        } else {
            right[rLen++] = arr[i];
        }
    }

    quickSort(left, lLen, lLen - 1);
    quickSort(right, rLen, rLen - 1);

    memcpy(arr, left, lLen * sizeof(int));
    arr[lLen++] = pivot;
    memcpy(arr + lLen, right, rLen * sizeof(int));

    free(left);
    free(right);
}

int main() {
    int arrLen = 5;
    int* arr = (int*)malloc(arrLen * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < arrLen; i++) {
        arr[i] = rand() % 10;
        printf("%d, ", arr[i]);
    }
    printf("\n");

    quickSort(arr, arrLen, arrLen - 1); // last element as pivot

    for (int i = 0; i < arrLen; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}
