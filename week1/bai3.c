#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCT_NAME 100
#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[MAX_PRODUCT_NAME];
    double price;
};

void displayProducts(struct Product products[], int numProducts) {
    printf("No\tProduct Name\t\t\t\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%-30s\t%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

int main() {
    FILE *file = fopen("product.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (fscanf(file, "%d %s %lf", &products[numProducts].id, products[numProducts].name, &products[numProducts].price) == 3) {
        numProducts++;
    }

    fclose(file);

    displayProducts(products, numProducts);

    return 0;
}
