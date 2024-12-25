#include <stdio.h>
#include <stdbool.h>

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubbleSortOptimized(int arr[], int n) {
	int i, j;
    int numIterations = 0;
    bool swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        numIterations++;
        printf("Sau l?n l?p %d: ", numIterations);
        printArray(arr, n);
        if (!swapped) {
            break;
        }
    }

    printf("S?p x?p hoàn thành sau %d l?n l?p.\n", numIterations);
}

int main() {
    int n, i;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nh?p các ph?n t? c?a m?ng: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("M?ng ban d?u: ");
    printArray(arr, n);
    bubbleSortOptimized(arr, n);
    printf("M?ng dã s?p x?p: ");
    printArray(arr, n);
    return 0;
}

