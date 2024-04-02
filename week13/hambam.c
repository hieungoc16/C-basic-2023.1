#include <stdio.h>
#include <string.h>

#define MAX_LEN 128

typedef struct {
    int id;
    char name[MAX_LEN];
} Student;

typedef struct {
    int n;
} Slot;

Slot hashTable[1000];
Student a[1000];

int add(int id, char* name, int i) {
    a[i].id = id;
    strcpy(a[i].name, name);
}

int linear(int key, int m) {
    return key % m;
}

int quadratic(int key, int c1, int c2, int i, int m) {
    return (key + c1 * i + c2 * i * i) % m;
}

int hash_double_1(int key) {
    return key % 13;
}

int hash_double_2(int key) {
    return 7 - (key % 7);
}

int double_hashing(int key, int size, int i) {
    return (hash_double_1(key) + i * hash_double_2(key)) % size;
}

void add_student(int m, int key, char* name, int probing_type, int c1, int c2) {
    int index;

    switch (probing_type) {
        case 1:
            index = linear(key, m);
            break;
        case 2:
            index = quadratic(key, c1, c2, 0, m);
            break;
        case 3:
            index = double_hashing(key, m, 0);
            break;
        default:
            printf("Invalid probing type.\n");
            return;
    }

    int i = 0;
    while (hashTable[index].n) {
        if (probing_type == 1) {
            index = (index + 1) % m;
        } else if (probing_type == 2) {
            i++;
            index = quadratic(key, c1, c2, i, m);
        } else {
            i++;
            index = double_hashing(key, m, i);
        }
    }

    a[index].id = key;
    strcpy(a[index].name, name);
    hashTable[index].n = 1;
}

void search_student(int m, int key, int probing_type, int c1, int c2) {
    int index;

    switch (probing_type) {
        case 1:
            index = linear(key, m);
            break;
        case 2:
            index = quadratic(key, c1, c2, 0, m);
            break;
        case 3:
            index = double_hashing(key, m, 0);
            break;
        default:
            printf("Invalid probing type.\n");
            return;
    }

    int i = 0;
    int original_index = index;
    while (hashTable[index].n) {
        if (a[index].id == key) {
            printf("Found student name %s id %d at position %d.\n", a[index].name, a[index].id, index);
            return;
        }

        if (probing_type == 1) {
            i++;
            index = (original_index + i) % m;
        } else if (probing_type == 2) {
            i++;
            index = quadratic(key, c1, c2, i, m);
        } else {
            i++;
            index = double_hashing(key, m, i);
        }

        if (i >= m) {
            printf("Id %d not found.\n", key);
            return;
        }

        if (index == original_index) {
            printf("Id %d not found.\n", key);
            return;
        }
    }

    printf("Id %d not found.\n", key);
}

void print_students(int m) {
    for (int i = 0; i < m; ++i) {
        if (hashTable[i].n) {
            printf("%s ", a[i].name);
        }
    }
    printf("\n");
}

int main() {
    int b = 0, m, n, k, c1 = 0, c2 = 0, id, t;
    char c, cmd[10], name[MAX_LEN];
    scanf("%d", &m);
    scanf(" %s", cmd);
    if (strcmp(cmd, "quadratic") == 0) {
        scanf(" %d %d", &c1, &c2);
        for (int i = 0; i < m; i++) {
            scanf("%d %s", &id, name);
            t = 2;
            add_student(m, id, name, 2, c1, c2);
        }
    } else if (strcmp(cmd, "linear") == 0) {
        for (int i = 0; i < m; i++) {
            scanf("%d %s", &id, name);
            t = 1;
            add_student(m, id, name, 1, 0, 0);
        }
    } else if (strcmp(cmd, "double") == 0) {
        for (int i = 0; i < m; i++) {
            scanf("%d %s", &id, name);
            t = 3;
            add_student(m, id, name, 3, 0, 0);
        }
    } else {
        printf("Invalid probing type.\n");
        b = 1;
    }
    if (b == 0) {
        while (1) {
            scanf(" %s", cmd);
            if (strcmp(cmd, "Search") == 0) {
                int k;
                scanf("%d", &k);
                search_student(m, k, t, c1, c2);
            } else if (strcmp(cmd, "Print") == 0) {
                print_students(m);
            } else if (strcmp(cmd, "Quit") == 0) {
                break;
            } else {
                while (c != '\n') scanf("%c", &c);
                printf("Invalid command.\n");
            }
        }
    }
    return 0;
}
