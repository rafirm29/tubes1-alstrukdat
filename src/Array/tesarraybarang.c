#include <stdio.h>
#include "arraydinbarang.h"

int main(){
    Barang Bar, Bar1;
    TabBarang T;
    Kata b;
    Bar = MakeBarang(b, 7000);
    MakeEmptyBarang(&T, 10);
    printf("maxel tab %d\n", (T).MaxElBarang);
    printf("Neff array %d\n", (T.NeffBarang));
    AddBarang(&T, Bar);
    AddBarang(&T, Bar1);
    TulisIsiTabBarang(T);
    GrowTabBarang(&T, 10);
    printf("maxel tab %d\n", (T).MaxElBarang);
    return 0;
}