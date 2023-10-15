#include <stdio.h>
#include <string.h>
#include <ctype.h> // Library untuk isalpha

int main() {
    char *bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    char huruf;
    char pilihan_bulan[20];
    int vokal = 0, non_vokal = 0;

    printf("Masukkan huruf (A-Z): ");
    scanf(" %c", &huruf);

    // Validasi input huruf kapital A-Z
    if (!isalpha(huruf) || huruf < 'A' || huruf > 'Z') {
        printf("Masukan tidak valid. Masukkan huruf kapital A-Z.\n");
        return 1; // Keluar dari program dengan kode error
    }

    printf("Bulan dengan awalan %c adalah: ", huruf);
    int bulan_cocok = 0;

    for (int i = 0; i < 12; i++) {
        if (bulan[i][0] == huruf) {
            printf("%s, ", bulan[i]);
            bulan_cocok++;
        }
    }

    if (bulan_cocok > 0) {
        printf("\nPilih bulan: ");
        scanf("%s", pilihan_bulan);

        // Validasi input hanya huruf
        int is_valid_input = 1;
        for (int i = 0; i < strlen(pilihan_bulan); i++) {
            if (!isalpha(pilihan_bulan[i])) {
                printf("Masukan tidak valid. Masukkan bulan yang tertera.\n");
                is_valid_input = 0;
                break;
            }
        }

        if (is_valid_input) {
            // Menghitung jumlah karakter vokal dan non-vokal
            // Menghitung jumlah karakter vokal dan non-vokal
        for (int i = 0; i < strlen(pilihan_bulan); i++) {
            if (pilihan_bulan[i] == 'a' || pilihan_bulan[i] == 'i' || pilihan_bulan[i] == 'u' || pilihan_bulan[i] == 'e' || pilihan_bulan[i] == 'o' ||
                pilihan_bulan[i] == 'A' || pilihan_bulan[i] == 'I' || pilihan_bulan[i] == 'U' || pilihan_bulan[i] == 'E' || pilihan_bulan[i] == 'O') {
                vokal++;
            } else {
                non_vokal++;
            }
        }


            printf("Jumlah vokal di %s adalah: %d\n", pilihan_bulan, vokal);
            printf("Jumlah non-vokal di %s adalah: %d\n", pilihan_bulan, non_vokal);
        }
    } else {
        printf("\nTidak ada bulan yang memiliki awalan %c.\n", huruf);
    }

    return 0;
}
