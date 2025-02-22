#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int* arr, int arrLen) {
    for (int i = 1; i < arrLen; i++) {
        int temp = arr[i];
        int sortedIndex = i - 1;

        while (sortedIndex >= 0 && arr[sortedIndex] > temp) {
            arr[sortedIndex + 1] = arr[sortedIndex];
            sortedIndex--;
        }
        arr[sortedIndex + 1] = temp;
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

    insertionSort(arr, arrLen);

    for (int i = 0; i < arrLen; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}
