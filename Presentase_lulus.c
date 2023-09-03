#include <stdio.h>

int main() {
//Deklarasi variabel
int hasilTes[10]; // Array menyimpan inputan hasil tes 1/2
char namaMahasiswa[5][50]; // Array untuk menyimpan nama mahasiswa
int jumlahLulus = 0, jumlahGagal = 0; // Variabel untuk menghitung jumlah lulus dan gagal
int i;

// Menginput data hasil ujian dan nama mahasiswa
printf ( " ------------ INPUT DATA MAHASISWA ------------\n ");
printf ( " ---- PILIHAN MENU (1: Lulus, 2: Gagal) ----\n ");
for (i = 0; i < 5; i++) {// looping untuk menampilkan perintah inputan mahasiswa sebanyak 5 kali
printf("Nama mahasiswa ke-%d: ", i + 1);
scanf("%s", namaMahasiswa[i]);
printf("Masukkan hasil ujian untuk %s: ", namaMahasiswa[i]);
scanf("%d", &hasilTes[i]);


//perkondisian
if (hasilTes[i] == 1) {
jumlahLulus++;
} else if (hasilTes[i] == 2) {
jumlahGagal++;
}else {
printf("Input tidak valid. Harap masukkan 1 atau 2.\n");
i--;
}
}

// Menampilkan nama dan hasil ujian masing-masing mahasiswa
printf("\n------------ HASIL UJIAN ------------\n");
for (i = 0; i < 5; i++) {
printf("Mahasiswa %s Dinyatakan %s\n", namaMahasiswa[i], (hasilTes[i] == 1) ? "Lulus" : "Gagal");
}

// Menampilkan jumlah kelulusan dan keterangan jika target tercapai
printf("\nJumlah Mahasiswa Lulus %d\n", jumlahLulus);
printf("Jumlah Mahasiswa Gagal %d\n", jumlahGagal);

float persentaseLulus = (float)jumlahLulus / 100 * 100;
if (persentaseLulus > 3) {
printf("Kelulusan Berhasil mencapai target!\n");
}
else if (persentaseLulus < 3){
printf("Kelulusan Gagal mencapai target\n");
}


return 0;
}