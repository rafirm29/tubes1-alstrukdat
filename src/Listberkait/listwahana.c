/* File : listlinier.c */
/* implementasi ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressWahana dengan pointer */
/* Wahana adalah integer */

#include <stdlib.h>
#include <stdio.h>
#include "listwahana.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyWahana (List L)
/* Mengirim true jika list kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (FirstLWahana(L) == NilWahana);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyWahana (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    FirstLWahana(*L) = NilWahana;
}


/****************** Manajemen Memori ******************/
addressWahana AlokasiWahana (Wahana X)
/* Mengirimkan addressWahana hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressWahana tidak NilWahana, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilWahana */
/* Jika alokasi gagal, mengirimkan NilWahana */
{
    // KAMUS LOKAL
    addressWahana tempAd;

    // ALGORITMA
    tempAd = (addressWahana) malloc (sizeof(ElmtList));
    InfoLWahana(tempAd) = X;
    NextLWahana(tempAd) = NilWahana;
    tempAd->upgradeList.First = NilWahana;
    tempAd->laporan.dinaikiHari = 0;
    tempAd->laporan.dinaikiTotal = 0;
    tempAd->laporan.penghasilanHari = 0;
    tempAd->laporan.penghasilanTotal = 0;

    return tempAd;
}

void DealokasiWahana (addressWahana *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressWahana P */
{
    // KAMUS LOKAL

    // ALGORITMA
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressWahana SearchWahana (List L, Wahana X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressWahana elemen tersebut. */
/* Jika tidak ada, mengirimkan NilWahana */
{
    // KAMUS LOKAL
    addressWahana object;
    addressWahana ans = NilWahana;

    // ALGORITMA
    object = FirstLWahana(L);

    while ((ans == NilWahana) && (object != NilWahana)) {
        if (EQ(object->info.lokasiWahana, X.lokasiWahana) && object->info.zona == X.zona) {
            ans = object;
        }

        object = NextLWahana(object);
    }

    return ans;
}

addressWahana SerachWahanaLokasi (List L, POINT loc, int zone) {
    // KAMUS LOKAL
    addressWahana object;
    addressWahana ans = NilWahana;

    // ALGORITMA
    object = FirstLWahana(L);

    while ((ans == NilWahana) && (object != NilWahana)) {
        if (EQ(object->info.lokasiWahana, loc) && object->info.zona == zone) {
            ans = object;
        }

        object = NextLWahana(object);
    }

    return ans;
}
/* Mencari wahana dengan lokasi pada list */
/* Mengirimkan addressWahana dari Wahana yang memiliki lokasi loc dan berada di map ke-zone */


/****************** PRIMITIF BERDASARKAN NilWahanaAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstWahana (List *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilWahanaai X jika alokasi berhasil */
{
    // KAMUS LOKAL
    addressWahana insertee;

    // ALGORITMA
    X.statusWahana = 1;
    insertee = AlokasiWahana(X);

    NextLWahana(insertee) = FirstLWahana(*L);
    FirstLWahana(*L) = insertee;
}

void InsVLastWahana (List *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilWahanaai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    // KAMUS LOKAL
    addressWahana insertee;
    addressWahana lastEl;

    // ALGORITMA

    if (IsEmptyWahana(*L)) {
        InsVFirstWahana(L, X);
    }

    else {
        X.statusWahana = 1;
        insertee = AlokasiWahana(X);
        lastEl = FirstLWahana(*L);

        while(NextLWahana(lastEl) != NULL) {
            lastEl = NextLWahana(lastEl);
        }

        NextLWahana(lastEl) = insertee;
    }

}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstWahana (List *L, Wahana *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilWahanaai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    // KAMUS LOKAL
    addressWahana deletee;

    // ALGORITMA
    deletee = FirstLWahana(*L);
    FirstLWahana(*L) = NextLWahana(deletee);

    *X = InfoLWahana(deletee);
    DealokasiWahana(&deletee);
}

void DelVLastWahana (List *L, Wahana *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilWahanaai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    // KAMUS LOKAL
    addressWahana deletee = FirstLWahana(*L);
    addressWahana prevDel = NilWahana;

    // ALGORITMA
    if (NextLWahana(deletee) == NilWahana) {
        DelVFirstWahana(L,X);
    }

    else {

        while(NextLWahana(deletee) != NilWahana) {
            prevDel = deletee;
            deletee = NextLWahana(prevDel);
        }

        NextLWahana(prevDel) = NilWahana;

        *X = InfoLWahana(deletee);
        DealokasiWahana(&deletee);
    }

}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstWahana (List *L, addressWahana P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressWahana P sebagai elemen pertama */
{
    // KAMUS LOKAL
    // ALGORITMA
    NextLWahana(P) = FirstLWahana(*L);
    FirstLWahana(*L) = P;
}

void InsertAfterWahana (List *L, addressWahana P, addressWahana Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // KAMUS LOKAL
    // ALGORITMA
    NextLWahana(P) = NextLWahana(Prec);
    NextLWahana(Prec) = P;
}

void InsertLastWahana (List *L, addressWahana P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    // KAMUS LOKAL
    addressWahana prevIns;

    // ALGORITMA
    if (IsEmptyWahana(*L)) {
        InsertFirstWahana(L,P);
    }

    else {
        prevIns = FirstLWahana(*L);

        while(NextLWahana(prevIns) != NilWahana) {
            prevIns = NextLWahana(prevIns);
        }

        NextLWahana(prevIns) = P;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstWahana (List *L, addressWahana *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    // KAMUS LOKAL
    // ALGORITMA
    *P = FirstLWahana(*L);

    FirstLWahana(*L) = NextLWahana(*P);
}

void DelPWahana (List *L, Wahana X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressWahana P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNilWahanaai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // KAMUS LOKAL
    boolean found = false;

    addressWahana deletee = FirstLWahana(*L);
    addressWahana prevDel = NilWahana;

    // ALGORITMA
    if (EQ(InfoLWahana(deletee).lokasiWahana, X.lokasiWahana)) {
        found = true;
    }

    while ((!found) && (NextLWahana(deletee) != NilWahana)) {
        prevDel = deletee;
        deletee = NextLWahana(prevDel);

        if (EQ(InfoLWahana(deletee).lokasiWahana, X.lokasiWahana)) {
            found = true;
        }
    }

    if(found) {
        if (FirstLWahana(*L) == deletee) {
            FirstLWahana(*L) = NextLWahana(deletee);
        }

        else {
            NextLWahana(prevDel) = NextLWahana(deletee);
        }

        DealokasiWahana(&deletee);
    }
}

void DelLastWahana (List *L, addressWahana *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    // KAMUS LOKAL
    addressWahana deletee = FirstLWahana(*L);
    addressWahana prevDel = NilWahana;

    // ALGORITMA
    if (NextLWahana(deletee) == NilWahana) {
        DelFirstWahana(L,P);
    }

    else {
        while (NextLWahana(deletee) != NilWahana) {
            prevDel = deletee;
            deletee = NextLWahana(deletee);
        }

        *P = deletee;
        NextLWahana(prevDel) = NilWahana;
    }

}

void DelAfterWahana (List *L, addressWahana *Pdel, addressWahana Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    // KAMUS LOKAL
    // ALGORITMA
    *Pdel = NextLWahana(Prec);
    NextLWahana(Prec) = NextLWahana(*Pdel);
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoWahana (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilWahanaai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    // KAMUS LOKAL
    addressWahana scannee = FirstLWahana(L);
    int i = 1;
    // ALGORITMA
    if (IsEmptyWahana(L)) {
        printf("Tidak ada wahana.\n");
    } else {
        while(scannee != NilWahana) {
            printf("\t%d. Wahana %s", i, InfoLWahana(scannee).namaWahana.TabKata);
            if ((InfoLWahana(scannee).lokasiWahana.X != 0 || InfoLWahana(scannee).lokasiWahana.Y != 0) && InfoLWahana(scannee).zona <= 4) {
                printf(" (%d, %d) Map %d",    InfoLWahana(scannee).lokasiWahana.X, InfoLWahana(scannee).lokasiWahana.Y,
                                                InfoLWahana(scannee).zona);
            } printf("\n");
            scannee = NextLWahana(scannee);
            i++;
        }
    }
}

// Menuliskan list wahana yang rusak serta lokasinya
void PrintWahanaRusak (List L) {
    List LRusak;
    addressWahana P;
    boolean found = false;

    CreateEmptyWahana(&LRusak);
    P = FirstLWahana(L);
    while (P != NilWahana) {
        if (InfoLWahana(P).statusWahana == 0) { // Ditemukan wahana rusak
            InsVLastWahana(&LRusak, InfoLWahana(P));
            found = true;
        }
        P = NextLWahana(P);
    }
    if (found) {
        printf("List wahana rusak :\n");
        PrintInfoWahana(LRusak);
    }
}

POINT PosisiWahanaRusak(List L, POINT Pos){
    addressWahana P;
    boolean found = false;
    POINT R;
    P = FirstLWahana(L);
    while (P != NilWahana)
    {
        if ((InfoLWahana(P).statusWahana == false) && (InfoLWahana(P).lokasiWahana.X == Pos.X) && (InfoLWahana(P).lokasiWahana.Y == Pos.Y))
        {
            R = MakePOINT(InfoLWahana(P).lokasiWahana.X, InfoLWahana(P).lokasiWahana.Y);
            return R;
        }
        else
        {
            P = NextLWahana(P);
        }
    }
    R = MakePOINT(0,0);
    return R;
}

// Menuliskan history wahana pada address P
void PrintHistoryWahana(addressWahana P) {
    if (FirstLWahana(P->upgradeList) != NilWahana) {
        addressWahana Q;
        Q = P->upgradeList.First;
        for (int i = 0; i < NbElmtWahana(P->upgradeList); i++){
            printf("%s --> ", InfoLWahana(Q).namaWahana.TabKata);
            Q = NextLWahana(Q);
        }
    } 
    printf("%s", InfoLWahana(P).namaWahana.TabKata);

    printf("\n");
}

// Menuliskan report suatu wahana yang ditunjuk address P;
void ReportWahana(addressWahana P) {
    printf("[%s]\n", InfoLWahana(P).namaWahana.TabKata);
    printf("Lokasi (%d, %d) pada Map %d\n", InfoLWahana(P).lokasiWahana.X, InfoLWahana(P).lokasiWahana.Y, InfoLWahana(P).zona);
    printf("Pengunjung total    : %d\n", P->laporan.dinaikiTotal);
    printf("Pengunjung hari ini : %d\n", P->laporan.dinaikiHari);
    printf("Penghasilan total   : %d\n", P->laporan.penghasilanTotal);
    printf("Penghasilan hari ini: %d\n", P->laporan.penghasilanHari);
}

int NbElmtWahana (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    // KAMUS LOKAL
    int counter = 0;
    addressWahana scannee = FirstLWahana(L);

    // ALGORITMA
    while (scannee != NilWahana) {
        scannee = NextLWahana(scannee);
        counter++;
    }

    return counter;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1Wahana (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    // KAMUS LOKAL
    addressWahana connector = FirstLWahana(*L1);

    // ALGORITMA
    if (IsEmptyWahana(*L1)) {
        FirstLWahana(*L3) = FirstLWahana(*L2);
    }

    else {
        FirstLWahana(*L3) = FirstLWahana(*L1);

        while(NextLWahana(connector) != NilWahana) {
            connector = NextLWahana(connector);
        }

        NextLWahana(connector) = FirstLWahana(*L2);
    }

    CreateEmptyWahana(L1);
    CreateEmptyWahana(L2);
}
