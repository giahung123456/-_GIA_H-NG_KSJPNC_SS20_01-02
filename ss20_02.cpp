#include <stdio.h>
#include <string.h>

typedef struct {
    char productCode[100];
    char productName[100];
    float purchasePrice;
    float sellingPrice;
    int quantity;
} Product;

Product products[100];
int productCount = 0;
float revenue = 0.0;

void inputProducts() {
    int quantity;
    printf("Nhap so luong san pham: ");
    scanf("%d", &quantity);
    getchar();

    for (int i = 0; i < quantity; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        fgets(products[productCount].productCode, 100, stdin);
        products[productCount].productCode[strcspn(products[productCount].productCode, "\n")] = 0;

        printf("Ten san pham: ");
        fgets(products[productCount].productName, 100, stdin);
        products[productCount].productName[strcspn(products[productCount].productName, "\n")] = 0;

        printf("Gia nhap: ");
        scanf("%f", &products[productCount].purchasePrice);

        printf("Gia ban: ");
        scanf("%f", &products[productCount].sellingPrice);

        printf("So luong: ");
        scanf("%d", &products[productCount].quantity);
        getchar();

        revenue -= products[productCount].purchasePrice * products[productCount].quantity;

        productCount++;
    }
}

void displayProducts() {
    if (productCount == 0) {
        printf("Danh sach san pham rong.\n");
        return;
    }

    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Ma san pham: %s\n", products[i].productCode);
        printf("Ten san pham: %s\n", products[i].productName);
        printf("Gia nhap: %.2f\n", products[i].purchasePrice);
        printf("Gia ban: %.2f\n", products[i].sellingPrice);
        printf("So luong: %d\n\n", products[i].quantity);
    }
}

void updateProduct() {
    char code[100];
    printf("Nhap ma san pham muon cap nhat: ");
    fgets(code, 100, stdin);
    code[strcspn(code, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productCode, code) == 0) {
            printf("Nhap thong tin cap nhat cho san pham:\n");
            printf("Ten san pham: ");
            fgets(products[i].productName, 100, stdin);
            products[i].productName[strcspn(products[i].productName, "\n")] = 0;

            printf("Gia nhap: ");
            scanf("%f", &products[i].purchasePrice);

            printf("Gia ban: ");
            scanf("%f", &products[i].sellingPrice);

            printf("So luong: ");
            scanf("%d", &products[i].quantity);
            getchar();

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("San pham khong tim thay.\n");
    }
}

void sortProductsByPrice() {
    int choice;
    printf("Chon thu tu sap xep:\n1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &choice);

    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            if ((choice == 1 && products[i].sellingPrice > products[j].sellingPrice) ||
                (choice == 2 && products[i].sellingPrice < products[j].sellingPrice)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

void searchProduct() {
    char name[100];
    printf("Nhap ten san pham muon tim: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i].productName, name) != NULL) {
            printf("Ma san pham: %s\n", products[i].productCode);
            printf("Ten san pham: %s\n", products[i].productName);
            printf("Gia nhap: %.2f\n", products[i].purchasePrice);
            printf("Gia ban: %.2f\n", products[i].sellingPrice);
            printf("So luong: %d\n\n", products[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay san pham.\n");
    }
}

void sellProduct() {
    char code[100];
    int quantityToSell;
    printf("Nhap ma san pham can ban: ");
    fgets(code, 100, stdin);
    code[strcspn(code, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productCode, code) == 0) {
            found = 1;
            printf("Nhap so luong ban: ");
            scanf("%d", &quantityToSell);
            getchar();

            if (quantityToSell > products[i].quantity) {
                printf("Khong con du hang.\n");
            } else if (products[i].quantity == 0) {
                printf("San pham het hang.\n");
            } else {
                products[i].quantity -= quantityToSell;
                revenue += quantityToSell * products[i].sellingPrice;
                printf("Ban thanh cong %d san pham.\n", quantityToSell);
            }
            break;
        }
    }

    if (!found) {
        printf("San pham khong tim thay.\n");
    }
}

void displayRevenue() {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}

int main() {
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham.\n");
        printf("2. Hien thi danh sach san pham.\n");
        printf("3. Cap nhat thong tin san pham.\n");
        printf("4. Sap xep san pham theo gia (Tang/Giam).\n");
        printf("5. Tim kiem san pham.\n");
        printf("6. Ban san pham.\n");
        printf("7. Doanh thu hien tai.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputProducts();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                sortProductsByPrice();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                sellProduct();
                break;
            case 7:
                displayRevenue();
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
