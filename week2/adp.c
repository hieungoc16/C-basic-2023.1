#include <stdio.h>
#include <stdlib.h>

void apd(FILE *fin, FILE *fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Su dung: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *fptr1, *fptr2;

    fptr1 = fopen(argv[1], "r");
    if (fptr1 == NULL) {
        printf("Loi khi mo tap tin 1");
        return 1;
    }

    fptr2 = fopen(argv[2], "a");
    if (fptr2 == NULL) {
        printf("Loi khi mo tap tin 2");
        fclose(fptr1);
        return 1;
    }

    apd(fptr1, fptr2);

    fclose(fptr1);
    fclose(fptr2);

    printf("Ghep noi dung cua %s vao cuoi %s thanh cong.\n", argv[1], argv[2]);

    return 0;
}

