#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 128
#define MAX_NUM 1000

typedef struct profile{
    char name[MAX_LEN];
    char email[MAX_LEN];
}profile;


profile students[MAX_NUM];
int num_students = 0;

int compare_names(const void *a, const void *b) {
    return strcmp(((profile *)a)->name, ((profile *)b)->name);
}

// Hàm tìm kiếm nhị phân
int find(char* name) {
    int left = 0, right = num_students - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(students[mid].name, name);

        if (cmp == 0) {
            return mid; // Tìm thấy sinh viên
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Không tìm thấy sinh viên
}

int insert(char* name, char* email, int i){
    qsort(students, num_students, sizeof(profile), compare_names);
    if (find(name) == -1){
        strcpy(students[i].name, name);
        strcpy(students[i].email, email);
        num_students++;
    } else printf("Name %s exists, do not insert\n", name);
}

void print(){
    qsort(students, num_students, sizeof(profile), compare_names);
    for (int i = 0; i < num_students; i++){
        printf("student[%d]: %s, %s\n", i, students[i].name, students[i].email);
    }
    return;
}

void removeStudents(char *name){
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            for (int j = i; j < num_students - 1; j++) {
                strcpy(students[j].name, students[j + 1].name);
                strcpy(students[j].email, students[j + 1].email);
            }
            num_students--;
            return;
        }
    }
    printf("Not found %s\n", name);
}


int main() {
    char s[10];
    char name[MAX_LEN];
    char email[MAX_LEN];

    while (1) {
        scanf("%s", s);
        if (strcmp(s, "Insert") == 0) {
            scanf("%s %s", name, email);
            insert(name, email, num_students);
        } else if (strcmp(s, "Find") == 0) {
            scanf("%s", name);
            qsort(students, num_students, sizeof(profile), compare_names);
            if (find(name) >= 0){
                int h = find(name);
                printf("Found student %s, at position %d, email %s\n", name, h , students[h].email);
            }else printf("Not found student %s\n", name);
        } else if (strcmp(s, "Print") == 0) {
            print();
        } else if (strcmp(s, "Remove") == 0) {
            scanf("%s", name);
            removeStudents(name);
        } else if (strcmp(s, "Quit") == 0) {
            break;
        }
    }

    return 0;
}
