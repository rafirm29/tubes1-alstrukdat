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
    return (GetFirstIdxBrs(M) + NBrsEff(M) - 1);
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
    // KAMUS LOKAL //

    // ALGORITMA //
    return (GetFirstIdxKol(M) + NKolEff(M) - 1);
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

    while ((i <= GetLastIdxBrs(M)) && !found){
        i++;
        j = GetFirstIdxKol(M);
        while ((j <= GetLastIdxKol(M)) && !found){
            j++;
            if (Elmt(M,i,j) == 'P'){
                found = true;
            }
        }
    }
    if (found){
        P = MakePOINT(j-1,i-1);
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
    i = Ordinat(Player)+1;
    j = Absis(Player)+1;

    if (Elmt(M,i+1,j) == 'W'){
        return (MakePOINT(j-1,i-1));
    }
    if (Elmt(M,i-1,j) == 'W'){
        return (MakePOINT(j-1,i-2));
    }
    if (Elmt(M,i,j+1) == 'W'){
        return (MakePOINT(j,i-1));
    }
    if (Elmt(M,i,j-1) == 'W'){
        return (MakePOINT(j-2,i-1));
    } 
    if ((Elmt(M,i,j-1) == '-') && (Elmt(M,i,j+1) == '-') && (Elmt(M,i+1,j) == '-') && (Elmt(M,i-1,j) == '-')){
        return (MakePOINT(0,0));
    }
}

void CopyMATRIKS (MATRIKS Awal, MATRIKS * Hasil) {
    // KAMUS LOKAL //

    // ALGORITMA // 
	NBrsEff(*Hasil) = NBrsEff(Awal);
  	NKolEff(*Hasil) = NKolEff(Awal);
	for(int i=GetFirstIdxBrs(Awal); i<=GetLastIdxBrs(Awal); i++){
		for (int j=GetFirstIdxKol(Awal); j<=GetLastIdxKol(Awal); j++){
			Elmt(*Hasil, i, j) = Elmt(Awal, i, j);
        }
    }
}

void BacaMATRIKS (MATRIKS * M, char * namafile) {
    // KAMUS LOKAL //
    int NB;
    int NK;
    
    // ALGORITMA //
    NB = 1;
    NK = 0;
    START(namafile);
    while (!EOP){
        if (CC == '\n'){
            NB++;
            NK = 0;
        } else{
            NK++;
        }
        Elmt(*M, NB, NK) = CC;
        ADV();
    }
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

void TulisFileMatriks(MATRIKS M, FILE *f){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            fprintf(f, "%c", Elmt(M,i,j));
        }
        fprintf(f,"\n");
    }
}

void TulisMATRIKS (MATRIKS M) {
    // KAMUS LOKAL //

    // ALGORITMA //
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            printf("%c", Elmt(M, i, j));
        }
        if (i != GetLastIdxBrs(M)){
            printf("\n");
        }
    }
}

void Move (MATRIKS * M, char X){
    // KAMUS LOKAL //
    int i, j;
    POINT CurrPlayer;

    // ALGORITMA //
    CurrPlayer = PosisiPlayer(*M);
    i = Ordinat(CurrPlayer)+1;
    j = Absis(CurrPlayer)+1;

    if (X == 'a' || X == 'A'){
        if (Elmt(*M,i,j-1) == '-'){
            Elmt(*M,i,j-1) = Elmt(*M,i,j);
            Elmt(*M,i,j) = '-';
        } else if (Elmt(*M,i,j-1) == 'W'){
            printf("Tidak bisa pindah ke kiri, ada bangunan!");
        } else if (Elmt(*M,i,j-1) == '*'){
            printf("Tidak bisa pindah ke kiri, ada tembok!");
        }
    } else if (X == 'd' || X == 'D'){
        if (Elmt(*M,i,j+1) == '-'){
            Elmt(*M,i,j+1) = Elmt(*M,i,j);
            Elmt(*M,i,j) = '-';
        } else if (Elmt(*M,i,j+1) == 'W'){
            printf("Tidak bisa pindah ke kanan, ada bangunan!");
        } else if (Elmt(*M,i,j+1) == '*'){
            printf("Tidak bisa pindah ke kanan, ada tembok!");
        }
    } else if (X == 's' || X == 'S'){
        if (Elmt(*M,i+1,j) == '-'){
            Elmt(*M,i+1,j) = Elmt(*M,i,j);
            Elmt(*M,i,j) = '-';
        } else if (Elmt(*M,i+1,j) == 'W'){
            printf("Tidak bisa pindah ke bawah, ada bangunan!");
        } else if (Elmt(*M,i+1,j) == '*'){
            printf("Tidak bisa pindah ke bawah, ada tembok!");
        }
    } else if (X == 'w' || X == 'W'){
        if (Elmt(*M,i-1,j) == '-'){
            Elmt(*M,i-1,j) = Elmt(*M,i,j);
            Elmt(*M,i,j) = '-';
        } else if (Elmt(*M,i-1,j) == 'W'){
            printf("Tidak bisa pindah ke atas, ada bangunan!");
        } else if (Elmt(*M,i-1,j) == '*'){
            printf("Tidak bisa pindah ke atas, ada tembok!");
        }
    }
}