#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void selectionSort(int* arr, int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arrLen; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            arr[i] ^= arr[minIndex];
            arr[minIndex] ^= arr[i];
            arr[i] ^= arr[minIndex];
        }
    }
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

    selectionSort(arr, arrLen);

    for (int i = 0; i < arrLen; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}
