/* *** IMPLEMENTASI ADT POINT *** */

#include "point.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    // Kamus Lokal //
    POINT P;

    // Algoritma //
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    // Kamus Lokal //
    int X, Y;

    // Algoritma //
    scanf("%d %d", &X, &Y);
    (*P) = MakePOINT(X,Y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    // Kamus Lokal //

    // Algoritma //
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    // Kamus Lokal //

    // Algoritma //
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

void CopyPOINT(POINT * P2, POINT P1){
/* Melakukan penyalinan P1 ke P2 */
/* I.S. P1 terdefinisi, P2 sembarang */
/* F.S. P2 sama dengan P1 */
    // Kamus Lokal //

    // Algoritma //
    Absis(*P2) = Absis(P1);
    Ordinat(*P2) = Ordinat(P1);
}