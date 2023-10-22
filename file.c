#include <stdio.h>

int main() {
    char data[255];
    FILE *sumber;

    // Membuka file
    if ((sumber = fopen("data.txt", "r")) == NULL) {
        printf("File Tidak Tersedia\n");
        // Keluar dari program karena file tidak ada.
        return 1;
    }

    // Baca isi file dengan fgets lalu simpan ke data
    while (fgets(data, sizeof(data), sumber)) {

        // Cetak data ke layar
        printf("%s", data);
    }

    // Tutup file
    fclose(sumber);

    return 0;
}