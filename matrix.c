#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("=-= Program Perkalian Matrix =-=\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    // Input matriks pertama
    int matrix1[2][2];
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Masukkan Nilai Matriks Pertama\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            char input[100];
            int validInput = 0;
            do
            {
                if (fgets(input, sizeof(input), stdin))
                {
                    if (sscanf(input, "%d", &matrix1[i][j]) == 1)
                    {
                        validInput = 1; // Input adalah angka yang valid
                    }
                    else
                    {
                        printf("\nInput harus berupa angka. Masukkan Ulang:\n");
                    }
                }
            } while (!validInput);
        }
    }

    // Input matriks kedua
    int matrix2[2][2];
    system("cls");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Masukkan Nilai Matriks Kedua\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            char input[100];
            int validInput = 0;
            do
            {
                if (fgets(input, sizeof(input), stdin))
                {
                    if (sscanf(input, "%d", &matrix2[i][j]) == 1)
                    {
                        validInput = 1; // Input adalah angka yang valid
                    }
                    else
                    {
                        printf("\nInput harus berupa angka. Masukkan Ulang:\n");
                    }
                }
            } while (!validInput);
        }
    }

    // Proses perkalian matriks
    int result[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Output hasil perkalian matriks
    system("cls");
    printf("=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Hasil perkalian matriks\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
