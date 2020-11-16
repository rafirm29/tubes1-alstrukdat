/* *** IMPLEMENTASI ADT MATRIKS *** */

#include "matriks.h"
#include <stdio.h>

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    // KAMUS LOKAL //

    // ALGORITMA //
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    // KAMUS LOKAL //

    // ALGORITMA //
    return ((i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax));

}

indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
    // KAMUS LOKAL //

    // ALGORITMA //
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
    // KAMUS LOKAL //

    // ALGORITMA //
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
    // KAMUS LOKAL //

    // ALGORITMA //
    return BrsMax;
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
    // KAMUS LOKAL //

    // ALGORITMA //
    return KolMax;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    // KAMUS LOKAL //

    // ALGORITMA //
    return ((i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M)));
}

POINT PosisiPlayer (MATRIKS M){
    // KAMUS LOKAL //
    int i, j;
    POINT P;
    boolean found;

    // ALGORITMA //
    found = false;
    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);

    while ((i <= GetLastIdxBrs(M)) && (!found)){
        i++;
        while ((j <= GetLastIdxKol(M)) && (!found)){
            j++;
            if (Elmt(M,i,j) == 'P'){
                found = true;
            }
        }
    }
    if (found){
        P = MakePOINT(j-1,i-1);
    } else{
        P = MakePOINT(0,0);
    }
    return P;
}

POINT PosisiBangunan (MATRIKS M){
    // KAMUS LOKAL //
    int i, j;
    POINT P;
    boolean found;

    // ALGORITMA //
    found = false;
    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);

    while ((i <= GetLastIdxBrs(M)) && (!found)){
        i++;
        while ((j <= GetLastIdxKol(M)) && (!found)){
            j++;
            if (Elmt(M,i,j) == 'W'){
                found = true;
            }
        }
    }
    P = MakePOINT(j-1,i-1);
    return P;
}

POINT BangunanSekitarPlayer (MATRIKS M, POINT Player){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    i = Ordinat(Player);
    j = Absis(Player);

    if (Elmt(M,i+1,j) == 'W'){
        return (MakePOINT(j,i+1));
    } else if (Elmt(M,i-1,j) == 'W'){
        return (MakePOINT(j,i-1));
    } else if (Elmt(M,i,j+1) == 'W'){
        return (MakePOINT(j+1,i));
    } else if (Elmt(M,i,j-1) == 'W'){
        return (MakePOINT(j-1,i));
    } else {
        return (MakePOINT(0,0));
    }
}

void BacaFile (MATRIKS M, FILE * F){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if (!fscanf(F, "%c", &Elmt(M,i,j))){
                break;
            }
        }
    }
    fclose(F);
}

void Move (MATRIKS M, char X){
    // KAMUS LOKAL //
    int i, j;
    POINT CurrPlayer;

    // ALGORITMA //
    CurrPlayer = PosisiPlayer(M);
    i = Ordinat(CurrPlayer);
    j = Absis(CurrPlayer);

    if (X == 'a'){
        if (Elmt(M,i,j-1) == '-'){
            Elmt(M,i,j-1) = Elmt(M,i,j);
            Elmt(M,i,j) = '-';
        } else if (Elmt(M,i,j-1) == 'W'){
            printf("Tidak bisa pindah ke kiri, ada bangunan!");
        }
    } else if (X == 'd'){
        if (Elmt(M,i,j+1) == '-'){
            Elmt(M,i,j+1) = Elmt(M,i,j);
            Elmt(M,i,j) = '-';
        } else if (Elmt(M,i,j+1) == 'W'){
            printf("Tidak bisa pindah ke kanan, ada bangunan!");
        }
    } else if (X == 'w'){
        if (Elmt(M,i+1,j) == '-'){
            Elmt(M,i+1,j) = Elmt(M,i,j);
            Elmt(M,i,j) = '-';
        } else if (Elmt(M,i+1,j) == 'W'){
            printf("Tidak bisa pindah ke atas, ada bangunan!");
        }
    } else if (X == 's'){
        if (Elmt(M,i-1,j) == '-'){
            Elmt(M,i-1,j) = Elmt(M,i,j);
            Elmt(M,i,j) = '-';
        } else if (Elmt(M,i-1,j) == 'W'){
            printf("Tidak bisa pindah ke bawah, ada bangunan!");
        }
    }
}