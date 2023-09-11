#include <stdio.h>

int main() {
    int belanjaLagi = 1; // Inisialisasi dengan 1 untuk memulai belanja
    double totalBelanja = 0.0;
    int jumlahTransaksi = 0; // Menghitung jumlah transaksi
    double totalHargaSebelumDiskon = 0.0; // Menyimpan total harga sebelum diskon

    printf("------------Program Menghitung Diskon------------\n");

    while (belanjaLagi) {
        double totalHargaBarang;
        printf("Masukkan total harga barang: Rp. ");
        scanf("%lf", &totalHargaBarang);

        totalHargaSebelumDiskon += totalHargaBarang;
        totalBelanja += totalHargaBarang;
        jumlahTransaksi++;

        if (jumlahTransaksi == 4) {
            // Diskon jika jumlah transaksi adalah 4
            double diskonTransaksi = totalHargaBarang * 0.20;
            printf("Anda mendapatkan diskon transaksi ke-4 sebesar Rp. %.2lf\n", diskonTransaksi);
            totalBelanja -= diskonTransaksi;
            
        }

        printf("Apakah Anda ingin belanja lagi? (1: Ya / 0: Tidak): ");
        scanf("%d", &belanjaLagi);

        if (belanjaLagi) {
            // Membersihkan buffer stdin
            while (getchar() != '\n');
        }
    }

    double diskon = 0.0;

    if (totalBelanja < 200000) {
        // Tidak mendapatkan diskon jika total belanja kurang dari Rp 200.000
        printf("Anda tidak mendapatkan diskon.\n");
    } else if (totalBelanja >= 200000 && totalBelanja <= 550000) {
        // Diskon 10% jika total belanja antara Rp 200.000 - Rp 500.000
        diskon = totalBelanja * 0.10;
        printf("Anda mendapatkan diskon 10%% sebesar Rp. %.2lf\n", diskon);
    } else if (totalBelanja > 550000 && totalBelanja <= 1000000) {
        // Diskon 20% jika total belanja antara Rp 550.000 - Rp 1.000.000
        diskon = totalBelanja * 0.20;
        printf("Anda mendapatkan diskon 20%% sebesar Rp. %.2lf\n", diskon);
    } else if (totalBelanja > 1000000) {
        // Diskon 30% jika total belanja di atas Rp 1.000.000
        diskon = totalBelanja * 0.30;
        printf("Anda mendapatkan diskon 30%% sebesar Rp. %.2lf\n", diskon);
    }

    double totalHargaSetelahDiskon = totalBelanja - diskon;
    printf("\n-----------Rekap Transaksi-----------\n");

    printf("Total harga sebelum diskon : Rp. %.2lf\n", totalHargaSebelumDiskon);
    printf("Total harga setelah diskon: Rp. %.2lf\n", totalHargaSetelahDiskon);

    return 0;
}
