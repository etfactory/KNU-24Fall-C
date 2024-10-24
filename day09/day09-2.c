#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int price;
} Product;

void printProduct(Product product) {
    printf("상품 ID : %d\n", product.id);
    printf("상품명 : %s\n", product.name);
    printf("가격 : %d\n", product.price);
}

int main() {
    int id; char name[20]; int price;
    Product product[5];
    int count = 0;

    while (count<sizeof(product)/sizeof(Product)) {
        printf("상품 정보를 입력하세요. (입력 중단은 id에 0 입력)\n");
        printf("상품 ID:");
        scanf_s("%d", &id);

        if (id == 0) break;

        printf("상품명:");
        scanf_s("%s", name, sizeof(name));
        printf("가격:");
        scanf_s("%d", &price);

        product[count].id = id;
        strcpy(product[count].name, name);
        product[count].price = price;
        count++;
    }

    printf("<<입력된 상품 정보 출력>>\n");
    for (int i=0; i<count; i++) {
        printProduct(product[i]);
        printf("\n");
    }

    return 0;
}