#include <stdio.h>

int main(void)
{

    int nim;
    char nama[50];
    float a, b, c, ttl;

    printf("\v");
    printf("------------Masukkan Data Diri------------\n");
    printf("Nama        : ");
    scanf("%[^\n]%*c", nama);

    printf("Nim         : ");
    scanf("%i", &nim);

    printf("Nilai tugas : ");
    scanf("%f", &a);

    printf("Nilai UTS   : ");
    scanf("%f", &b);

    printf("Nilai UAS   : ");
    scanf("%f", &c);

    ttl = (a * 0.4) + (b * 0.3) + (c * 0.3);

    printf("\v");
    printf("------------Hasil Nilai Akhir------------\n");
    printf("Nama        : %s\n", nama);
    printf("NIM         : %i\n", nim);
    printf("Nilai akhir : %f\n", ttl);

    if (ttl >= 90)
    {
        printf("Grade       : A\n");
    }
    else if (ttl >= 85 && ttl < 90)
    {
        printf("Grade       : A-\n");
    }
    else if (ttl >= 80 && ttl <85)
    {
        printf("Grade       : B+\n");
    }
    else if (ttl >= 75 && ttl < 80)
    {
        printf("Grade       : B\n");
    }
    else if (ttl >= 70 && ttl < 75)
    {
        printf("Grade       : B-\n");
    }
    else if (ttl >= 65 && ttl < 70)
    {
        printf("Grade       : C\n");
    }
    else if (ttl >= 50 && ttl < 65)
    {
        printf("Grade       : D\n");
    }

    printf("\v");
}