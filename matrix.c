#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isNumber(char input[])
{
for (int i = 0; input[i] != '\0'; i++)
{
if (input[i] < '0' || input[i] > '9')
{
return false;
}
}
return true;
}

int main()
{
// Input: Matriks A (2x2)
int a[2][2];
printf("Masukkan elemen matriks A (2x2):\n");
for (int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
char input[100];
scanf("%s", input);
if (!isNumber(input))
{
printf("Masukkan harus berupa angka.\n");
return 1; // Exit code 1 menunjukkan kesalahan
}
a[i][j] = atoi(input);
}
}

// Input: Matriks B (2x2)
int b[2][2];
printf("Masukkan elemen matriks B (2x2):\n");
for (int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
char input[100];
scanf("%s", input);
if (!isNumber(input))
{
printf("Masukkan harus berupa angka.\n");
return 1; // Exit code 1 menunjukkan kesalahan
}
b[i][j] = atoi(input);
}
}

// Proses: Perkalian matriks
int hasil[2][2];
for (int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
hasil[i][j] = 0;
for (int k = 0; k < 2; k++)
{
hasil[i][j] += a[i][k] * b[k][j];
}
}
}

// Output: Cetak hasil perkalian matriks
printf("Hasil perkalian matriks:\n");
for (int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
printf("%d ", hasil[i][j]);
}
printf("\n");
}

return 0;
}
