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

// Membuat wahana baru
void BuildWahana(Wahana W, Player * P, MATRIKS * M, boolean * success) {
    *success = false;
    if (IsEnough(*P, W.biayaBuild)) {

        boolean IsMaterialEnough;
        IsMaterialEnough =  ((InvPlayer(*P).TIInventory[0].Jumlah >= W.wood) && 
                            (InvPlayer(*P).TIInventory[1].Jumlah >= W.steel) &&
                            (InvPlayer(*P).TIInventory[2].Jumlah >= W.iron));
        if (IsMaterialEnough) {
            POINT Player;
            Player = PosisiPlayer(*M);
            if (Elmt(*M, Ordinat(Player), Absis(Player)+1) == 'W') {
                printf("Can't build. There's already a building.\n");
            } else {
                Elmt(*M, Ordinat(Player), Absis(Player)+1) = 'W';
                SubstractMoney(P, W.biayaBuild);    // Mengurangi jumlah uang pemain
                printf("Build Successful.\n");
                (InvPlayer(*P).TIInventory[0].Jumlah -= W.wood);
                (InvPlayer(*P).TIInventory[1].Jumlah -= W.steel);
                (InvPlayer(*P).TIInventory[2].Jumlah -= W.iron);
                *success = true;
            }
        } else printf("Not enugh material. Please try again.\n");
    } else printf("Not enough money. Please try again.\n");
}

// Mengupgrade wahana (Prekondisi : Player sudah berada di sebelah wahana.)
void UpgradeWahana(BinTree T, Player * P, MATRIKS * M, int i, POINT LokasiWahana, List * L) {

    if (i == 1) {   /* Memilih upgrade 1 (Left) */
        if (IsEnough(*P, Akar(Left(T)).biayaBuild)) {

            boolean IsMaterialEnough;
            IsMaterialEnough =  ((InvPlayer(*P).TIInventory[0].Jumlah >= Akar(Left(T)).wood) && 
                                (InvPlayer(*P).TIInventory[1].Jumlah >= Akar(Left(T)).steel) &&
                                (InvPlayer(*P).TIInventory[2].Jumlah >= Akar(Left(T)).iron));
            if (IsMaterialEnough) {
                Elmt(*M, Ordinat(LokasiWahana)+1, Absis(LokasiWahana)+1) = Akar(Left(T)).namaWahana.TabKata[0];
                SubstractMoney(P, Akar(Left(T)).biayaUpgrade);
                (InvPlayer(*P).TIInventory[0].Jumlah -= Akar(Left(T)).wood);
                (InvPlayer(*P).TIInventory[1].Jumlah -= Akar(Left(T)).steel);
                (InvPlayer(*P).TIInventory[2].Jumlah -= Akar(Left(T)).iron);
                
                //
                // TO DO: UPDATE LIST WAHANA
                //

            } else printf("Not enugh material. Please try again.\n");
        } else printf("Not enough money. Please try again.\n");
    } else if (i == 2) {
        if (IsEnough(*P, Akar(Right(T)).biayaBuild)) {

            boolean IsMaterialEnough;
            IsMaterialEnough =  ((InvPlayer(*P).TIInventory[0].Jumlah >= Akar(Right(T)).wood) && 
                                (InvPlayer(*P).TIInventory[1].Jumlah >= Akar(Right(T)).steel) &&
                                (InvPlayer(*P).TIInventory[2].Jumlah >= Akar(Right(T)).iron));
            if (IsMaterialEnough) {
                Elmt(*M, Ordinat(LokasiWahana)+1, Absis(LokasiWahana)+1) = Akar(Right(T)).namaWahana.TabKata[0];
                SubstractMoney(P, Akar(Right(T)).biayaUpgrade);
                (InvPlayer(*P).TIInventory[0].Jumlah -= Akar(Right(T)).wood);
                (InvPlayer(*P).TIInventory[1].Jumlah -= Akar(Right(T)).steel);
                (InvPlayer(*P).TIInventory[2].Jumlah -= Akar(Right(T)).iron);
                
                //
                // TO DO: UPDATE LIST WAHANA
                //
                
            } else printf("Not enugh material. Please try again.\n");
        } else printf("Not enough money. Please try again.\n");
    }
}