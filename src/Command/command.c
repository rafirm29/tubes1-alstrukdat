#include <stdio.h>
#include <stdlib.h>
#include "command.h"

void Buy(Player * P, TabBarang B, IdxTypeBarang i, int Jumlah) {
    ElTypeBarang Barang;
    Barang = ElmtBarang(B, i-1);
    int HargaTotal;
    HargaTotal = Harga(Barang) * Jumlah;
    if (IsEnough(*P, HargaTotal)) {
        JumlahInv(InvPlayer(*P).TIInventory[i-1]) += Jumlah;
        SubstractMoney(P, HargaTotal);
        printf("Buy successful!\n");
    } else {
        printf("Money is not enough. Try again.\n");
    }
}