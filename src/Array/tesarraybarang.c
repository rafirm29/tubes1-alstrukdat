#include <stdio.h>
#include "arraydinbarang.h"

int main(){
    Barang Bar, Bar1;
    TabBarang T;
    Kata b;
    Bar = MakeBarang(b, 7000);
    MakeEmpty(&T, 10);
    printf("maxel tab %d\n", (T).MaxEl);
    printf("Neff array %d\n", (T.Neff));
    AddBarang(&T, Bar);
    AddBarang(&T, Bar1);
    TulisIsiTab(T);
    GrowTab(&T, 10);
    printf("maxel tab %d\n", (T).MaxEl);
    return 0;
}