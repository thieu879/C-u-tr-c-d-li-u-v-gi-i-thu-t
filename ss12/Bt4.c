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

    printf("Nh?p s? lu?ng sinh viên: ");
    scanf("%d", &n);

    Student students[n];

    for (i = 0; i < n; i++) {
        printf("Nh?p tên sinh viên %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Nh?p di?m c?a %s: ", students[i].name);
        scanf("%d", &students[i].score);
    }

    printf("Nh?p tên sinh viên c?n tìm: ");
    scanf("%s", &searchName);

    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Ði?m c?a %s là: %d\n", searchName, students[i].score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Không tìm th?y sinh viên.\n");
    }

    return 0;
}

