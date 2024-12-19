#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int n, target, result,i;

    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nh?p các ph?n t? c?a m?ng (theo th? t? tang d?n):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nh?p giá tr? c?n tìm: ");
    scanf("%d", &target);

    result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Ph?n t? %d n?m ? v? trí: %d\n", target, result + 1);
    } else {
        printf("Không tìm th?y ph?n t? trong m?ng.\n");
    }

    return 0;
}

