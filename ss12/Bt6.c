#include <stdio.h>

void findDuplicates(int arr[], int n) {
    int count[n],i,j, k;
    int hasDuplicates = 0;

    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (count[i] > 1) {
            int alreadyPrinted = 0;
            for (k = 0; k < i; k++) {
                if (arr[i] == arr[k]) {
                    alreadyPrinted = 1;
                    break;
                }
            }
            if (!alreadyPrinted) {
                printf("Ph?n t? %d xu?t hi?n %d l?n.\n", arr[i], count[i]);
                hasDuplicates = 1;
            }
        }
    }

    if (!hasDuplicates) {
        printf("Không có ph?n t? l?p l?i.\n");
    }
}

int main() {
    int n, i;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nh?p các ph?n t? c?a m?ng:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findDuplicates(arr, n);

    return 0;
}

