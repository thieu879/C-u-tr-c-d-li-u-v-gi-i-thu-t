#include <stdio.h>

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
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
    selectionSort(arr, n);
    printf("M?ng sau khi s?p x?p: ");
    printArray(arr, n);
    int target;
    printf("Nh?p ph?n t? c?n tìm: ");
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Ph?n t? %d du?c tìm th?y t?i v? trí %d\n", target, result + 1);
    } else {
        printf("Không tìm th?y ph?n t? %d\n", target);
    }
    return 0;
}

