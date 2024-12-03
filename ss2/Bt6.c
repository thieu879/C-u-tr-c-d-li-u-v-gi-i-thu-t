#include <stdio.h>

void mergeAndSortArrays(int arr1[], int n, int arr2[], int m, int result[]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        result[i] = arr1[i];
    }
    for (j = 0; j < m; j++) {
        result[i + j] = arr2[j];
    }
    int size = n + m;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Nh?p s? ph?n t? c?a m?ng 1 (0 < n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("S? ph?n t? c?a m?ng 1 không h?p l?.\n");
        return 1;
    }

    int arr1[n];
    printf("Nh?p các ph?n t? c?a m?ng 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Nh?p s? ph?n t? c?a m?ng 2 (0 < m <= 1000): ");
    scanf("%d", &m);

    if (m < 0 || m > 1000) {
        printf("S? ph?n t? c?a m?ng 2 không h?p l?.\n");
        return 1;
    }

    int arr2[m];
    printf("Nh?p các ph?n t? c?a m?ng 2:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    int result[n + m];
    mergeAndSortArrays(arr1, n, arr2, m, result);

    printf("K?t qu? sau khi g?p và s?p x?p:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

