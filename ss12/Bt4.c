#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    int n, i;
    char searchName[50];
    int found = 0;

    printf("Nh?p s? lu?ng sinh vi�n: ");
    scanf("%d", &n);

    Student students[n];

    for (i = 0; i < n; i++) {
        printf("Nh?p t�n sinh vi�n %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Nh?p di?m c?a %s: ", students[i].name);
        scanf("%d", &students[i].score);
    }

    printf("Nh?p t�n sinh vi�n c?n t�m: ");
    scanf("%s", &searchName);

    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("�i?m c?a %s l�: %d\n", searchName, students[i].score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Kh�ng t�m th?y sinh vi�n.\n");
    }

    return 0;
}

