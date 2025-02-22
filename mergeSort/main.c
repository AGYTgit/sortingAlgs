#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mergeSort(int* arr, int arrLen) {
    if (arrLen <= 1) {
        return;
    }

    int rLen = arrLen / 2;
    int lLen = arrLen - rLen;
    int* left = malloc(lLen * sizeof(int));
    int* right = malloc(rLen * sizeof(int));

    memcpy(left, arr, lLen * sizeof(int));
    memcpy(right, arr + lLen, rLen * sizeof(int));

    mergeSort(left, lLen);
    mergeSort(right, rLen);

    for (int i = 0, l = 0, r = 0; i < arrLen; i++) {
        if (l < lLen) {
            if (r < rLen) {
                if (left[l] <= right[r]) {
                    arr[i] = left[l++];
                } else {
                    arr[i] = right[r++];
                }
            } else {
                arr[i] = left[l++];
            }
        } else if (r < rLen) {
            arr[i] = right[r++];
        }
    }

    free(left);
    free(right);
    left = NULL;
    right = NULL;
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

    mergeSort(arr, arrLen);

    for (int i = 0; i < arrLen; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}
