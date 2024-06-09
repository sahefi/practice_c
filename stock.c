#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur untuk barang
typedef struct Barang {
    char nama[50];
    int stok;
    struct Barang* prev;
    struct Barang* next;
} Barang;

// Fungsi untuk membuat simpul baru
Barang* createNode(char nama[], int stok) {
    Barang* newNode = (Barang*)malloc(sizeof(Barang));
    strcpy(newNode->nama, nama);
    newNode->stok = stok;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambah barang baru di awal linked list
void tambahBarang(Barang** head, char nama[], int stok) {
    Barang* newNode = createNode(nama, stok);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Fungsi untuk menampilkan stok barang
void lihatStok(Barang* head) {
    Barang* temp = head;
    if (temp == NULL) {
        printf("Stok barang kosong.\n");
        return;
    }
    printf("Stok Barang:\n");
    while (temp != NULL) {
        printf("Nama: %s, Stok: %d\n", temp->nama, temp->stok);
        temp = temp->next;
    }
}

// Fungsi utama
int main() {
    Barang* head = NULL;
    int pilihan;
    char namaBarang[50];
    int stokBarang;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Stok Barang\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama barang: ");
                scanf("%s", namaBarang);
                printf("Masukkan stok barang: ");
                scanf("%d", &stokBarang);
                tambahBarang(&head, namaBarang, stokBarang);
                break;
            case 2:
                lihatStok(head);
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    // Membebaskan memori
    while (head != NULL) {
        Barang* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
