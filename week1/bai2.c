#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

void displayWholeFile(FILE *file) {
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", buffer);
    }
}

void displayByPage(FILE *file) {
    char buffer[MAX_LINE_LENGTH];
    int lineNumber = 0;
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", buffer);
        lineNumber++;

        // Nếu đã đọc đủ một trang, chờ người dùng chạm một phím để xem trang tiếp theo
        if (lineNumber % 24 == 0) {
            
            getchar(); // Chờ người dùng chạm một phím Enter
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename> [-p]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 2;
    }

    if (argc == 3 && strcmp(argv[2], "-p") == 0) {
        displayByPage(file);
    } else {
        displayWholeFile(file);
    }

    fclose(file);
    return 0;
}
