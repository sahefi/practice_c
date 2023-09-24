#include <stdio.h>

void passbyvalue(int a, int b) { 
    printf("a = %d, b = %d", a, b); 
}

void passbyaddress(int *a, int *b) { 
    printf("\na = %p, b = %p", a, b); 
}

int main() {
    int angka1 = 55;
    int angka2 = 77;

    // Pass  value
    printf("Hasil angka1 = %d, Hasil angka2 = %d\n", angka1, angka2);
    passbyvalue(angka1, angka2);

    // Pass Address
    printf("\n\nHasil angka1 = %d, Hasil angka2 = %d", angka1, angka2);
    passbyaddress(&angka1, &angka2);

    return 0;
}
