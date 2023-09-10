#include <stdio.h>
#include <string.h>

int main() {
    //declare i/o
    char tipeBensin[10];
    double konsumsiBahanBakar = 0.0;
    double bensinAwal, bensinAkhir, jarakTempuh;
    char modeMenyupir[10];
    
    //Tampilan awal
    printf("\nPenghitung Efisiensi Bahan Bakar");
    printf("\n-------------------------------------------------------\n\n");
    printf("Pilih jenis Bahan Bakar  (Pertamax/Pertalite): ");
    scanf("%s", tipeBensin);

    if (strcmp(tipeBensin, "Pertamax") == 0 || strcmp(tipeBensin,"pertamax")==0|| strcmp(tipeBensin,"PERTAMAX")==0) {
        printf("Pilih cara berkendara (konstan/stop&go): ");
        scanf("%s", modeMenyupir);

        if (strcmp(modeMenyupir, "konstan") == 0) {
            konsumsiBahanBakar = 15.0;
        } else if (strcmp(modeMenyupir, "stop&go") == 0) {
            konsumsiBahanBakar = 10.0;
        } else {
            printf("Cara berkendara tidak valid.\n");
            return 1;
        }
    } else if (strcmp(tipeBensin, "Pertalite") == 0 || strcmp(tipeBensin,"pertalite")==0|| strcmp(tipeBensin,"PERTALITE")==0) {
        printf("Pilih cara berkendara  (konstan/stop&go): ");
        scanf("%s", modeMenyupir);

        if (strcmp(modeMenyupir, "konstan") == 0) {
            konsumsiBahanBakar = 12.0;
        } else if (strcmp(modeMenyupir, "stop&go") == 0) {
            konsumsiBahanBakar = 8.0;
        } else {
            printf("Cara berkendara tidak valid.\n");
            return 1;
        }
    } else {
        printf("Jenis bahan bakar tidak valid.\n");
        return 1;
    }

    printf("Masukkan jumlah awal bahan bakar (liter): ");
    scanf("%lf", &bensinAwal);

    printf("Masukkan jarak yang ditempuh (km): ");
    scanf("%lf", &jarakTempuh);

	printf("\n----------------------------------------------\n");
    double bensinDibutuhkan = jarakTempuh / konsumsiBahanBakar;
    bensinAkhir = bensinAwal - bensinDibutuhkan;

    if (bensinAkhir <= 0) {
        printf("\n Anda kehabisan bensin di tengah perjalanan!\n");
    } else {
        printf("\nJumlah bahan bakar yang dibutuhkan: %.2lf liter\n", bensinDibutuhkan);
        printf("Jumlah bahan bakar akhir: %.2lf liter\n", bensinAkhir);
    }

    return 0;
}