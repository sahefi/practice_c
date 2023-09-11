#include <stdio.h>

int main() {

    int km,m,cm;

    printf("Masukkan Jarak Dalam Satuan KM : \n" );
    scanf("%d" , &km);
    getchar();

    m = km * 1000;
    cm = km * 100000;

    printf("hasil nya adalah %d",m);
    getchar();
    printf("hasilnya adalah %d",cm);
    
return 0 ;
}