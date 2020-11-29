#include <stdio.h>
#include <stdlib.h>
#include "player.h"

int main(int argc, char const *argv[])
{
    /* Deklarasi awal player */
    Player P1, P2;
    Kata namaPlayer1 = MakeKata("John");
    Kata namaPlayer2 = MakeKata("Doremi");
    P1 = MakePlayer(namaPlayer1, "../Array/Inventory/inventory.txt");
    P2 = MakePlayer(namaPlayer2, "../Array/Inventory/inventory.txt");

    int HargaMahal, HargaMurah;
    HargaMahal = 9999999;
    HargaMurah = 1;

    if (!IsEnough(P1, HargaMahal)) {
        printf("Uang %s tidak cukup untuk membeli yang mahal!\n", P1.Name.TabKata);
    }
    if (IsEnough(P2, HargaMurah)) {
        printf("Uang %s cukup untuk membeli barang murah!\n", P2.Name.TabKata);
    }

    // Menampilkan isi inventory player
    TulisIsiTabInventory(P1.InvPlayer);


    return 0;
}
