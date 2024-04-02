#include<stdio.h>
#include<string.h>
#include<math.h>
int main(int argc, char* argv[]){
    if (argc != 4) {
        printf("Nhap lai");
        return 1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double delta = b * b - 4 * a * c;
    if ( delta < 0 ) printf("Phuong trinh vo nghiem");
    if ( delta == 0 ){ 
        double x = -b / ( 2 * a );
        printf("x1 = x2 = %.2lf", x);
        }
    if ( delta > 0 ) printf("x1 = %.2lf\nx2 = %.2lf", (-b + sqrt(delta))/ (2 * a), (-b - sqrt(delta))/ (2 * a));
}