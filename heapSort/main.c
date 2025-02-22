#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int* arr, int arrLen, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < arrLen && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < arrLen && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        arr[i] ^= arr[largest];
        arr[largest] ^= arr[i];
        arr[i] ^= arr[largest];

        heapify(arr, arrLen, largest);
    }
}

void heapSort(int* arr, int arrLen) {
    for (int i = arrLen / 2 - 1; i >= 0; i--) {
        heapify(arr, arrLen, i);
    }

    for (int i = arrLen - 1; i > 0; i--) {
        arr[0] ^= arr[i];
        arr[i] ^= arr[0];
        arr[0] ^= arr[i];

        heapify(arr, i, 0);
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

    heapSort(arr, arrLen);

    for (int i = 0; i < arrLen; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}
