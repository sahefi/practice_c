#include <stdio.h>
#include <string.h>

void swap(char arr[][20], int i, int j) {
    char temp[20];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], temp);
}

int partition(char arr[][20], int low, int high) {
    char pivot[20];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSort(char arr[][20], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char nama[10][20] = {"Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida", "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur", "Bella Christie", "Chelshe Love"};
    int n = 10;

    printf("Sebelum diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    // Tambahkan nomor unik ke setiap nama
    for (int i = 0; i < n; i++) {
        char nomor[4];
        snprintf(nomor, sizeof(nomor), "%03d", i);
        strcat(nama[i], nomor);
    }

    quickSort(nama, 0, n - 1);

    printf("\nSetelah diurutkan secara ascending:\n");
    for (int i = 0; i < n; i++) {
        // Hilangkan nomor unik saat mencetak
        printf("%s\n", nama[i]);
    }

    return 0;
}
