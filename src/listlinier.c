/* File : listlinier.c */
/* implementasi ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (First(L) == Nil);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    First(*L) = Nil;
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    // KAMUS LOKAL
    address tempAd;

    // ALGORITMA
    tempAd = (address) malloc (sizeof(address));
    Info(tempAd) = X;
    Next(tempAd) = Nil;

    return tempAd;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    // KAMUS LOKAL

    // ALGORITMA
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    // KAMUS LOKAL
    address object;
    address ans = Nil;

    // ALGORITMA
    object = First(L);

    while ((ans == Nil) && (object != Nil)) {
        if (Info(object) == X) {
            ans = object;
        }

        object = Next(object);
    }

    return ans;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    // KAMUS LOKAL
    address insertee;

    // ALGORITMA
    insertee = Alokasi(X);

    Next(insertee) = First(*L);
    First(*L) = insertee;
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    // KAMUS LOKAL
    address insertee;
    address lastEl;

    // ALGORITMA

    if (IsEmpty(*L)) {
        InsVFirst(L, X);
    }

    else {
        insertee = Alokasi(X);
        lastEl = First(*L);

        while(Next(lastEl) != Nil) {
            lastEl = Next(lastEl);
        }

        Next(lastEl) = insertee;
    }

}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    // KAMUS LOKAL
    address deletee;

    // ALGORITMA
    deletee = First(*L);
    First(*L) = Next(deletee);

    *X = Info(deletee);
    Dealokasi(&deletee);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    // KAMUS LOKAL
    address deletee = First(*L);
    address prevDel = Nil;

    // ALGORITMA
    if (Next(deletee) == Nil) {
        DelVFirst(L,X);
    }

    else {

        while(Next(deletee) != Nil) {
            prevDel = deletee;
            deletee = Next(prevDel);
        }

        Next(prevDel) = Nil;

        *X = Info(deletee);
        Dealokasi(&deletee);
    }

}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    // KAMUS LOKAL
    // ALGORITMA
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // KAMUS LOKAL
    // ALGORITMA
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    // KAMUS LOKAL
    address prevIns;

    // ALGORITMA
    if (IsEmpty(*L)) {
        InsertFirst(L,P);
    }

    else {
        prevIns = First(*L);

        while(Next(prevIns) != Nil) {
            prevIns = Next(prevIns);
        }

        Next(prevIns) = P;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
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

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // KAMUS LOKAL
    boolean found = false;

    address deletee = First(*L);
    address prevDel = Nil;

    // ALGORITMA
    if (Info(deletee) == X) {
        found = true;
    }

    while ((!found) && (Next(deletee) != Nil)) {
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

        Dealokasi(&deletee);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    // KAMUS LOKAL
    address deletee = First(*L);
    address prevDel = Nil;

    // ALGORITMA
    if (Next(deletee) == Nil) {
        DelFirst(L,P);
    }

    else {
        while (Next(deletee) != Nil) {
            prevDel = deletee;
            deletee = Next(deletee);
        }

        *P = deletee;
        Next(prevDel) = Nil;
    }

}

void DelAfter (List *L, address *Pdel, address Prec)
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
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    // KAMUS LOKAL
    address scannee = First(L);

    // ALGORITMA
    printf("[");

    while(scannee != Nil) {
        printf("%d", Info(scannee));

        scannee = Next(scannee);

        if (scannee != Nil) {
            printf(",");
        }
    }

    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    // KAMUS LOKAL
    int counter = 0;
    address scannee = First(L);

    // ALGORITMA
    while (scannee != Nil) {
        scannee = Next(scannee);
        counter++;
    }

    return counter;
}


/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
    // KAMUS LOKAL
    address scannee = First(L);
    infotype minVal = Info(scannee);

    // ALGORITMA
    while (scannee != Nil) {
        if (Info(scannee) < minVal) {
            minVal = Info(scannee);
        }

        scannee = Next(scannee);
    }

    return minVal;
}


/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    // KAMUS LOKAL
    address scannee = First(L);
    infotype maxVal = Info(scannee);

    // ALGORITMA
    while (scannee != Nil) {
        if (Info(scannee) > maxVal) {
            maxVal = Info(scannee);
        }

        scannee = Next(scannee);
    }

    return maxVal;
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    // KAMUS LOKAL
    address connector = First(*L1);

    // ALGORITMA
    if (IsEmpty(*L1)) {
        First(*L3) = First(*L2);
    }

    else {
        First(*L3) = First(*L1);

        while(Next(connector) != Nil) {
            connector = Next(connector);
        }

        Next(connector) = First(*L2);
    }

    CreateEmpty(L1);
    CreateEmpty(L2);
}
