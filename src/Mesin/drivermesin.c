#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

int main() {
    // Kata cobaInput;
    // Input(&cobaInput, false); // false = tidak membaca input dari dari file (pembacaan stdin)
    // printf("%s\n", cobaInput.TabKata);

    Kata Convert;
    Convert = MakeKata("Test");
    printf("Jumlah huruf = %d\n", Convert.Length);
    printf("Kalimat = %s\n", Convert.TabKata);

    return 0;
}