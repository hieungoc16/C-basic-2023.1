#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void uppercase(FILE *file) {

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (islower(c)) {
            fseek(file, -1, SEEK_CUR); 
            fputc(toupper(c), file);
        }
    }

    printf("Chuyen doi tap tin va ghi lai thanh cong %s.\n", file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Su dung: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r+");

    if (file == NULL) {
        printf("Loi khi mo tap tin");
        return 1;
    }

    uppercase(file);
    fclose(file);
    return 0;
}
