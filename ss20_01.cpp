#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char bookCode[100];
    char bookTitle[100];
    char author[100];
    float price;
    char genre[100];
} Book;

Book books[100];
int bookCount = 0;

void inputBooks() {
    printf("Nhap so luong sach: ");
    scanf("%d", &bookCount);
    getchar();

    for (int i = 0; i < bookCount; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        fgets(books[i].bookCode, 100, stdin);
        books[i].bookCode[strcspn(books[i].bookCode, "\n")] = 0;

        printf("Ten sach: ");
        fgets(books[i].bookTitle, 100, stdin);
        books[i].bookTitle[strcspn(books[i].bookTitle, "\n")] = 0;

        printf("Tac gia: ");
        fgets(books[i].author, 100, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;

        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        getchar();

        printf("The loai: ");
        fgets(books[i].genre, 100, stdin);
        books[i].genre[strcspn(books[i].genre, "\n")] = 0;
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("Chua co sach nao.\n");
        return;
    }

    printf("\nDanh sach sach:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Ma sach: %s\n", books[i].bookCode);
        printf("Ten sach: %s\n", books[i].bookTitle);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n\n", books[i].genre);
    }
}

void addBookAtPosition() {
    int position;
    printf("Nhap vi tri muon them sach (0 - %d): ", bookCount);
    scanf("%d", &position);
    getchar();

    if (position < 0 || position > bookCount) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    if (bookCount >= 100) {
        printf("Danh sach sach da day.\n");
        return;
    }

    for (int i = bookCount; i > position; i--) {
        books[i] = books[i - 1];
    }

    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    fgets(books[position].bookCode, 100, stdin);
    books[position].bookCode[strcspn(books[position].bookCode, "\n")] = 0;

    printf("Ten sach: ");
    fgets(books[position].bookTitle, 100, stdin);
    books[position].bookTitle[strcspn(books[position].bookTitle, "\n")] = 0;

    printf("Tac gia: ");
    fgets(books[position].author, 100, stdin);
    books[position].author[strcspn(books[position].author, "\n")] = 0;

    printf("Gia tien: ");
    scanf("%f", &books[position].price);
    getchar();

    printf("The loai: ");
    fgets(books[position].genre, 100, stdin);
    books[position].genre[strcspn(books[position].genre, "\n")] = 0;

    bookCount++;
}

void deleteBookByCode() {
    char code[100];
    printf("Nhap ma sach muon xoa: ");
    fgets(code, 100, stdin);
    code[strcspn(code, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookCode, code) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            found = 1;
            printf("Xoa sach thanh cong.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ma sach: %s\n", code);
    }
}

void updateBookByCode() {
    char code[100];
    printf("Nhap ma sach muon cap nhat: ");
    fgets(code, 100, stdin);
    code[strcspn(code, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookCode, code) == 0) {
            printf("Nhap thong tin cap nhat cho sach:\n");
            printf("Ma sach: ");
            fgets(books[i].bookCode, 100, stdin);
            books[i].bookCode[strcspn(books[i].bookCode, "\n")] = 0;

            printf("Ten sach: ");
            fgets(books[i].bookTitle, 100, stdin);
            books[i].bookTitle[strcspn(books[i].bookTitle, "\n")] = 0;

            printf("Tac gia: ");
            fgets(books[i].author, 100, stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;

            printf("Gia tien: ");
            scanf("%f", &books[i].price);
            getchar();

            printf("The loai: ");
            fgets(books[i].genre, 100, stdin);
            books[i].genre[strcspn(books[i].genre, "\n")] = 0;

            found = 1;
            printf("Cap nhat thong tin sach thanh cong.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ma sach: %s\n", code);
    }
}

void sortBooksByPrice() {
    int choice;
    printf("Chon thu tu sap xep:\n1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &choice);

    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if ((choice == 1 && books[i].price > books[j].price) || 
                (choice == 2 && books[i].price < books[j].price)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("Sap xep sach theo gia thanh cong.\n");
}

void searchBookByTitle() {
    char title[100];
    printf("Nhap ten sach muon tim: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].bookTitle, title) != NULL) {
            printf("Ma sach: %s\n", books[i].bookCode);
            printf("Ten sach: %s\n", books[i].bookTitle);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia tien: %.2f\n", books[i].price);
            printf("The loai: %s\n\n", books[i].genre);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ten: %s\n", title);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (Tang/Giam).\n");
        printf("7. Tim kiem sach theo ten.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Đọc ký tự Enter còn lại

        switch (choice) {
            case 1:
                inputBooks();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                addBookAtPosition();
                break;
            case 4:
                deleteBookByCode();
                break;
            case 5:
                updateBookByCode();
                break;
            case 6:
                sortBooksByPrice();
                break;
            case 7:
                searchBookByTitle();
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
