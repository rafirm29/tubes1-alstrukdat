#include <stdio.h>
#include <stdlib.h>
#include "command.h"

void Buy(Player * P, TabBarang B, IdxTypeBarang i, int Jumlah) {
/* I.S. P terdefinisi, B adalah tabel daftar barang, i adalah idx barang yang valid, Jumlah adalah jumlah barang */
/* F.S. Jumlah barang dengan idx i pada P bertambah sebanyak Jumlah, uang pada P berkurang sesuai ketentuan harga barang */
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
void BuildWahana(Wahana W, Player * P, MATRIKS * M, POINT LokasiBuild) {
/* I.S. P terdefinisi, W adalah wahana yang ingin dibangun, M adalah map taman bermain, lokBuild adalah koordinat tempat wahana akan dibangun */
/* F.S. wahana terbangun pada lokasi lokBuild di M, uang serta material P berkurang */
    if (IsEnough(*P, W.biayaBuild)) {

        boolean IsMaterialEnough;
        IsMaterialEnough =  ((InvPlayer(*P).TIInventory[0].Jumlah >= W.wood) && 
                            (InvPlayer(*P).TIInventory[1].Jumlah >= W.steel) &&
                            (InvPlayer(*P).TIInventory[2].Jumlah >= W.iron));
        if (IsMaterialEnough) {
            Elmt(*M, Ordinat(LokasiBuild)+1, Absis(LokasiBuild)+1) = 'W';
            SubstractMoney(P, W.biayaBuild);    // Mengurangi jumlah uang pemain
            (InvPlayer(*P).TIInventory[0].Jumlah -= W.wood);
            (InvPlayer(*P).TIInventory[1].Jumlah -= W.steel);
            (InvPlayer(*P).TIInventory[2].Jumlah -= W.iron);
        } else printf("Not enugh material. Please try again.\n");
    } else printf("Not enough money. Please try again.\n");
}

// Mengupgrade wahana (Prekondisi : Player sudah berada di sebelah wahana.)
void UpgradeWahana(BinTree T, Player * P, MATRIKS * M, int i, POINT LokasiWahana, List * L, int z) {
/* I.S. T adalah BinTree Upgrade wahana, P terdefinisi, M adalah map, L adalah List wahana yang telah dibangun */
/* lokUpgrade adalah koordinat wahana yang ingin diupgrade, zona adalah zona map wahana */
/* i adalah arah upgrade: 
    1. subpohon kiri, 
    2. subpohon kanan,  */
/* F.S. wahana pada L yang berkoordinat di lokUpgrade dengan zona zona terupgrade, material dan uang pada P berkurang, tanda wahana di M berubah */
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
                
                // Penambahan history upgrade
                addressWahana P;
                P = FirstLWahana(*L);
                while (!EQ(LokasiWahana, InfoLWahana(P).lokasiWahana) || InfoLWahana(P).zona != z) {
                    P = NextLWahana(P);
                }
                InsVLastWahana(&(P->upgradeList), P->info);
                InfoLWahana(P) = Akar(Left(T));
                InfoLWahana(P).zona = z;
                InfoLWahana(P).lokasiWahana = LokasiWahana;

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
                
                // Penambahan history upgrade
                addressWahana P;
                P = FirstLWahana(*L);
                while (!EQ(LokasiWahana, InfoLWahana(P).lokasiWahana) || InfoLWahana(P).zona != z) {
                    P = NextLWahana(P);
                }
                InsVLastWahana(&(P->upgradeList), P->info);
                InfoLWahana(P) = Akar(Right(T));
                InfoLWahana(P).zona = z;
                InfoLWahana(P).lokasiWahana = LokasiWahana;
                
            } else printf("Not enugh material. Please try again.\n");
        } else printf("Not enough money. Please try again.\n");
    }
}