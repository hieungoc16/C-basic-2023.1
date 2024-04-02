#include <stdio.h>

#define MAX_SINHVIEN 100

struct SinhVien {
    int stt;
    char masv[20];
    char hoten[50];
    char sdt[20];
    float diem;
};

void docDanhSachLop(char *filePath, struct SinhVien danhSach[], int *soSinhVien) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    *soSinhVien = 0;
    while (fscanf(file, "%d %s %s %s", &danhSach[*soSinhVien].stt,
                  danhSach[*soSinhVien].masv, danhSach[*soSinhVien].hoten,
                  danhSach[*soSinhVien].sdt) == 4) {
        (*soSinhVien)++;
    }

    fclose(file);
}

void ghiBangDiem(char *filePath, struct SinhVien danhSach[], int soSinhVien) {
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    for (int i = 0; i < soSinhVien; i++) {
        fprintf(file, "%d %s %s %s %.2f\n", danhSach[i].stt, danhSach[i].masv,
                danhSach[i].hoten, danhSach[i].sdt, danhSach[i].diem);
    }

    fclose(file);
}

void nhapDiem(struct SinhVien danhSach[], int soSinhVien) {
    for (int i = 0; i < soSinhVien; i++) {
        printf("Nhap diem cho sinh vien %s: ", danhSach[i].masv);
        scanf("%f", &danhSach[i].diem);
    }
}

int main() {
    struct SinhVien danhSach[MAX_SINHVIEN];
    int soSinhVien;

    char filePath[] = "danh_sach_lop.txt";
    docDanhSachLop(filePath, danhSach, &soSinhVien);

    nhapDiem(danhSach, soSinhVien);

    char bangDiemPath[] = "bangdiem.txt";
    ghiBangDiem(bangDiemPath, danhSach, soSinhVien);

    return 0;
}
