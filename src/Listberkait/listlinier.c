/* File : listlinier.c */
/* implementasi ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressLinier dengan pointer */
/* infotypeList adalah integer */

#include <stdlib.h>
#include <stdio.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (ListLinier L)
/* Mengirim true jika list kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (First(L) == NilLinier);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (ListLinier *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    First(*L) = NilLinier;
}


/****************** Manajemen Memori ******************/
addressLinier AlokasiList (infotypeList X)
/* Mengirimkan addressLinier hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLinier tidak NilLinier, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilLinier */
/* Jika alokasi gagal, mengirimkan NilLinier */
{
    // KAMUS LOKAL
    addressLinier tempAd;

    // ALGORITMA
    tempAd = (addressLinier) malloc (sizeof(addressLinier));
    Info(tempAd) = X;
    Next(tempAd) = NilLinier;

    return tempAd;
}

void DealokasiList (addressLinier *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLinier P */
{
    // KAMUS LOKAL

    // ALGORITMA
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLinier SearchList (ListLinier L, infotypeList X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressLinier elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLinier */
{
    // KAMUS LOKAL
    addressLinier object;
    addressLinier ans = NilLinier;

    // ALGORITMA
    object = First(L);

    while ((ans == NilLinier) && (object != NilLinier)) {
        if (Info(object) == X) {
            ans = object;
        }

        object = Next(object);
    }

    return ans;
}


/****************** PRIMITIF BERDASARKAN NilLinierAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (ListLinier *L, infotypeList X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilLinierai X jika alokasi berhasil */
{
    // KAMUS LOKAL
    addressLinier insertee;

    // ALGORITMA
    insertee = AlokasiList(X);

    Next(insertee) = First(*L);
    First(*L) = insertee;
}

void InsVLastList (ListLinier *L, infotypeList X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLinierai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    // KAMUS LOKAL
    addressLinier insertee;
    addressLinier lastEl;

    // ALGORITMA

    if (IsEmptyList(*L)) {
        InsVFirstList(L, X);
    }

    else {
        insertee = AlokasiList(X);
        lastEl = First(*L);

        while(Next(lastEl) != NilLinier) {
            lastEl = Next(lastEl);
        }

        Next(lastEl) = insertee;
    }

}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (ListLinier *L, infotypeList *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilLinierai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    // KAMUS LOKAL
    addressLinier deletee;

    // ALGORITMA
    deletee = First(*L);
    First(*L) = Next(deletee);

    *X = Info(deletee);
    DealokasiList(&deletee);
}

void DelVLastList (ListLinier *L, infotypeList *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilLinierai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    // KAMUS LOKAL
    addressLinier deletee = First(*L);
    addressLinier prevDel = NilLinier;

    // ALGORITMA
    if (Next(deletee) == NilLinier) {
        DelVFirstList(L,X);
    }

    else {

        while(Next(deletee) != NilLinier) {
            prevDel = deletee;
            deletee = Next(prevDel);
        }

        Next(prevDel) = NilLinier;

        *X = Info(deletee);
        DealokasiList(&deletee);
    }

}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (ListLinier *L, addressLinier P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLinier P sebagai elemen pertama */
{
    // KAMUS LOKAL
    // ALGORITMA
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterList (ListLinier *L, addressLinier P, addressLinier Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // KAMUS LOKAL
    // ALGORITMA
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastList (ListLinier *L, addressLinier P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    // KAMUS LOKAL
    addressLinier prevIns;

    // ALGORITMA
    if (IsEmptyList(*L)) {
        InsertFirstList(L,P);
    }

    else {
        prevIns = First(*L);

        while(Next(prevIns) != NilLinier) {
            prevIns = Next(prevIns);
        }

        Next(prevIns) = P;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (ListLinier *L, addressLinier *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    // KAMUS LOKAL
    // ALGORITMA
    *P = First(*L);

    First(*L) = Next(*P);
}

void DelPList (ListLinier *L, infotypeList X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLinier P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNilLinierai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // KAMUS LOKAL
    boolean found = false;

    addressLinier deletee = First(*L);
    addressLinier prevDel = NilLinier;

    // ALGORITMA
    if (Info(deletee) == X) {
        found = true;
    }

    while ((!found) && (Next(deletee) != NilLinier)) {
        prevDel = deletee;
        deletee = Next(prevDel);

        if (Info(deletee) == X) {
            found = true;
        }
    }

    if(found) {
        if (First(*L) == deletee) {
            First(*L) = Next(deletee);
        }

        else {
            Next(prevDel) = Next(deletee);
        }

        DealokasiList(&deletee);
    }
}

void DelLastList (ListLinier *L, addressLinier *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    // KAMUS LOKAL
    addressLinier deletee = First(*L);
    addressLinier prevDel = NilLinier;

    // ALGORITMA
    if (Next(deletee) == NilLinier) {
        DelFirstList(L,P);
    }

    else {
        while (Next(deletee) != NilLinier) {
            prevDel = deletee;
            deletee = Next(deletee);
        }

        *P = deletee;
        Next(prevDel) = NilLinier;
    }

}

void DelAfterList (ListLinier *L, addressLinier *Pdel, addressLinier Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    // KAMUS LOKAL
    // ALGORITMA
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoList (ListLinier L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilLinierai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    // KAMUS LOKAL
    addressLinier scannee = First(L);

    // ALGORITMA
    printf("[");

    while(scannee != NilLinier) {
        printf("%d", Info(scannee));

        scannee = Next(scannee);

        if (scannee != NilLinier) {
            printf(",");
        }
    }

    printf("]");
}

int NbElmtList (ListLinier L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    // KAMUS LOKAL
    int counter = 0;
    addressLinier scannee = First(L);

    // ALGORITMA
    while (scannee != NilLinier) {
        scannee = Next(scannee);
        counter++;
    }

    return counter;
}


/*** Prekondisi untuk Min: List tidak kosong ***/
infotypeList MinList (ListLinier L)
/* Mengirimkan NilLinierai Info(P) yang minimum */
{
    // KAMUS LOKAL
    addressLinier scannee = First(L);
    infotypeList minVal = Info(scannee);

    // ALGORITMA
    while (scannee != NilLinier) {
        if (Info(scannee) < minVal) {
            minVal = Info(scannee);
        }

        scannee = Next(scannee);
    }

    return minVal;
}


/*** Prekondisi untuk Max: List tidak kosong ***/
infotypeList MaxList (ListLinier L)
/* Mengirimkan NilLinierai Info(P) yang maksimum */
{
    // KAMUS LOKAL
    addressLinier scannee = First(L);
    infotypeList maxVal = Info(scannee);

    // ALGORITMA
    while (scannee != NilLinier) {
        if (Info(scannee) > maxVal) {
            maxVal = Info(scannee);
        }

        scannee = Next(scannee);
    }

    return maxVal;
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1List (ListLinier *L1, ListLinier *L2, ListLinier *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    // KAMUS LOKAL
    addressLinier connector = First(*L1);

    // ALGORITMA
    if (IsEmptyList(*L1)) {
        First(*L3) = First(*L2);
    }

    else {
        First(*L3) = First(*L1);

        while(Next(connector) != NilLinier) {
            connector = Next(connector);
        }

        Next(connector) = First(*L2);
    }

    CreateEmptyList(L1);
    CreateEmptyList(L2);
}
