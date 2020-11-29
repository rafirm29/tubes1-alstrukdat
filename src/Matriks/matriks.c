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

POINT PosisiOffice (MATRIKS M){
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
            if (Elmt(M,i,j) == 'O'){
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

POINT PosisiAntrian (MATRIKS M){
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
            if (Elmt(M,i,j) == 'A'){
                found = true;
            }
        }
    }
    P = MakePOINT(j-1,i-1);
    return P;
}


boolean IsInOffice (MATRIKS M, POINT PO){
    int i, j, x, y;

    i = Ordinat(PosisiPlayer(M))+1;
    j = Absis(PosisiPlayer(M))+1;
    x = Ordinat(PO)+1;
    y = Absis(PO)+1;
    return ((i == x) && (j == y));
}

POINT BangunanSekitarPlayer (MATRIKS M, POINT Player){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    i = Ordinat(Player)+1;
    j = Absis(Player)+1;

    if (Elmt(M,i+1,j) == 'W' || Elmt(M,i+1,j) == 'L' || Elmt(M,i+1,j) == 'C'){
        return (MakePOINT(j-1,i-1));
    }
    if (Elmt(M,i-1,j) == 'W' || Elmt(M,i-1,j) == 'L' || Elmt(M,i-1,j) == 'C'){
        return (MakePOINT(j-1,i-2));
    }
    if (Elmt(M,i,j+1) == 'W' || Elmt(M,i,j+1) == 'L' || Elmt(M,i,j+1) == 'C'){
        return (MakePOINT(j,i-1));
    }
    if (Elmt(M,i,j-1) == 'W' || Elmt(M,i,j-1) == 'L' || Elmt(M,i,j-1) == 'C'){
        return (MakePOINT(j-2,i-1));
    } 
    if ((Elmt(M,i,j-1) == '-') && (Elmt(M,i,j+1) == '-') && (Elmt(M,i+1,j) == '-') && (Elmt(M,i-1,j) == '-')){
        return (MakePOINT(0,0));
    }
}

boolean AdaBangunanSekitarPlayer (MATRIKS M, POINT Player){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    i = Ordinat(Player)+1;
    j = Absis(Player)+1;

    if (Elmt(M,i+1,j) == 'W' || Elmt(M,i+1,j) == 'L' || Elmt(M,i+1,j) == 'C'){
        return true;
    }
    if (Elmt(M,i-1,j) == 'W' || Elmt(M,i-1,j) == 'L' || Elmt(M,i-1,j) == 'C'){
        return true;
    }
    if (Elmt(M,i,j+1) == 'W' || Elmt(M,i,j+1) == 'L' || Elmt(M,i,j+1) == 'C'){
        return true;
    }
    if (Elmt(M,i,j-1) == 'W' || Elmt(M,i,j-1) == 'L' || Elmt(M,i,j-1) == 'C'){
        return true;
    } 
    if ((Elmt(M,i,j-1) == '-') && (Elmt(M,i,j+1) == '-') && (Elmt(M,i+1,j) == '-') && (Elmt(M,i-1,j) == '-')){
        return false;
    }
}


//

//

POINT AntrianSekitarPlayer (MATRIKS M, POINT Antrian){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    i = Ordinat(Antrian)+1;
    j = Absis(Antrian)+1;

    if (Elmt(M,i+1,j) == 'A'){
        return (MakePOINT(j-1,i-1));
    }
    if (Elmt(M,i-1,j) == 'A'){
        return (MakePOINT(j-1,i-2));
    }
    if (Elmt(M,i,j+1) == 'A'){
        return (MakePOINT(j,i-1));
    }
    if (Elmt(M,i,j-1) == 'A'){
        return (MakePOINT(j-2,i-1));
    } 
    if ((Elmt(M,i,j-1) == '-') && (Elmt(M,i,j+1) == '-') && (Elmt(M,i+1,j) == '-') && (Elmt(M,i-1,j) == '-')){
        return (MakePOINT(0,0));
    }
}

boolean AdaAntrianSekitarPlayer (MATRIKS M, POINT Antrian){
    // KAMUS LOKAL //
    int i, j;

    // ALGORITMA //
    i = Ordinat(Antrian)+1;
    j = Absis(Antrian)+1;

    if (Elmt(M,i+1,j) == 'A'){
        return true;
    }
    if (Elmt(M,i-1,j) == 'A'){
        return true;
    }
    if (Elmt(M,i,j+1) == 'A'){
        return true;
    }
    if (Elmt(M,i,j-1) == 'A'){
        return true;
    } 
    if ((Elmt(M,i,j-1) == '-') && (Elmt(M,i,j+1) == '-') && (Elmt(M,i+1,j) == '-') && (Elmt(M,i-1,j) == '-')){
        return false;
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
    STARTFILE(namafile);
    while (!EOP){
        if (CC == '\n'){
            NB++;
            NK = 0;
        } else{
            NK++;
        }
        Elmt(*M, NB, NK) = CC;
        ADVFILE();
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

void Move (MATRIKS * M, char X, POINT PO, int * zone){
    // KAMUS LOKAL //
    int i, j;
    POINT CurrPlayer;

    // ALGORITMA //
    CurrPlayer = PosisiPlayer(*M);
    i = Ordinat(CurrPlayer)+1;
    j = Absis(CurrPlayer)+1;

    if ((Absis(PO)+1 == j) && (Ordinat(PO)+1 == i)){
        if (X == 'a' || X == 'A'){
            if (Elmt(*M,i,j-1) == '-' || Elmt(*M,i,j-1) == 'O'){
                Elmt(*M,i,j-1) = Elmt(*M,i,j);
                Elmt(*M,i,j) = 'O';
            } else if (Elmt(*M,i,j-1) == 'W' || Elmt(*M,i,j-1) == 'L' || Elmt(*M,i,j-1) == 'C'){
                printf("Tidak bisa pindah ke kiri, ada bangunan!\n");
            } else if (Elmt(*M,i,j-1) == '*'){
                printf("Tidak bisa pindah ke kiri, ada tembok!\n");
            }
        } else if (X == 'd' || X == 'D'){
            if (Elmt(*M,i,j+1) == '-' || Elmt(*M,i,j+1) == 'O'){
                Elmt(*M,i,j+1) = Elmt(*M,i,j);
                Elmt(*M,i,j) = 'O';
            } else if (Elmt(*M,i,j+1) == 'W' || Elmt(*M,i,j+1) == 'L' || Elmt(*M,i,j+1) == 'C'){
                printf("Tidak bisa pindah ke kanan, ada bangunan!\n");
            } else if (Elmt(*M,i,j+1) == '*'){
                printf("Tidak bisa pindah ke kanan, ada tembok!\n");
            }
        } else if (X == 's' || X == 'S'){
            if (Elmt(*M,i+1,j) == '-' || Elmt(*M,i+1,j) == 'O'){
                Elmt(*M,i+1,j) = Elmt(*M,i,j);
                Elmt(*M,i,j) = 'O';
            } else if (Elmt(*M,i+1,j) == 'W' || Elmt(*M,i+1,j) == 'L' || Elmt(*M,i+1,j) == 'C'){
                printf("Tidak bisa pindah ke bawah, ada bangunan!\n");
            } else if (Elmt(*M,i+1,j) == '*'){
                printf("Tidak bisa pindah ke bawah, ada tembok!\n");
            }
        } else if (X == 'w' || X == 'W'){
            if (Elmt(*M,i-1,j) == '-' || Elmt(*M,i-1,j) == 'O'){
                Elmt(*M,i-1,j) = Elmt(*M,i,j);
                Elmt(*M,i,j) = 'O';
            } else if (Elmt(*M,i-1,j) == 'W' || Elmt(*M,i-1,j) == 'L' || Elmt(*M,i-1,j) == 'C'){
                printf("Tidak bisa pindah ke atas, ada bangunan!\n");
            } else if (Elmt(*M,i-1,j) == '*'){
                printf("Tidak bisa pindah ke atas, ada tembok!\n");
            }
        }
    } else{
        if (X == 'a' || X == 'A'){
            if (Elmt(*M,i,j-1) == '-' || Elmt(*M,i,j-1) == 'O'){
                Elmt(*M,i,j-1) = Elmt(*M,i,j);
                Elmt(*M,i,j) = '-';
            } else if (Elmt(*M,i,j-1) == 'W' || Elmt(*M,i,j-1) == 'L' || Elmt(*M,i,j-1) == 'C'){
                printf("Tidak bisa pindah ke kiri, ada bangunan!\n");
            } else if (Elmt(*M,i,j-1) == '*'){
                printf("Tidak bisa pindah ke kiri, ada tembok!\n");
            } else if (Elmt(*M,i,j-1) == '<'){
                Elmt(*M,i,j) = '-';
                if (*zone == 2) {
                    *zone = 1;
                } else if (*zone == 4) {
                    *zone = 3;
                }
            }
        } else if (X == 'd' || X == 'D'){
            if (Elmt(*M,i,j+1) == '-' || Elmt(*M,i,j+1) == 'O'){
                Elmt(*M,i,j+1) = Elmt(*M,i,j);
                Elmt(*M,i,j) = '-';
            } else if (Elmt(*M,i,j+1) == 'W' || Elmt(*M,i,j+1) == 'L' || Elmt(*M,i,j+1) == 'C'){
                printf("Tidak bisa pindah ke kanan, ada bangunan!\n");
            } else if (Elmt(*M,i,j+1) == '*'){
                printf("Tidak bisa pindah ke kanan, ada tembok!\n");
            } else if (Elmt(*M,i,j+1) == '>'){
                Elmt(*M,i,j) = '-';
                if (*zone == 1) {
                    *zone = 2;
                } else if (*zone == 3) {
                    *zone = 4;
                }
            }
        } else if (X == 's' || X == 'S'){
            if (Elmt(*M,i+1,j) == '-' || Elmt(*M,i+1,j) == 'O'){
                Elmt(*M,i+1,j) = Elmt(*M,i,j);
                Elmt(*M,i,j) = '-';
            } else if (Elmt(*M,i+1,j) == 'W' || Elmt(*M,i+1,j) == 'L' || Elmt(*M,i+1,j) == 'C'){
                printf("Tidak bisa pindah ke bawah, ada bangunan!\n");
            } else if (Elmt(*M,i+1,j) == '*'){
                printf("Tidak bisa pindah ke bawah, ada tembok!\n");
            } else if (Elmt(*M,i+1,j) == 'v'){
                Elmt(*M,i,j) = '-';
                if (*zone == 1) {
                    *zone = 3;
                } else if (*zone == 2) {
                    *zone = 4;
                }
            }
        } else if (X == 'w' || X == 'W'){
            if (Elmt(*M,i-1,j) == '-' || Elmt(*M,i-1,j) == 'O'){
                Elmt(*M,i-1,j) = Elmt(*M,i,j);
                Elmt(*M,i,j) = '-';
            } else if (Elmt(*M,i-1,j) == 'W' || Elmt(*M,i-1,j) == 'L' || Elmt(*M,i-1,j) == 'C'){
                printf("Tidak bisa pindah ke atas, ada bangunan!\n");
            } else if (Elmt(*M,i-1,j) == '*'){
                printf("Tidak bisa pindah ke atas, ada tembok!\n");
            } else if (Elmt(*M,i-1,j) == '^'){
                Elmt(*M,i,j) = '-';
                if (*zone == 3) {
                    *zone = 1;
                } else if (*zone == 4) {
                    *zone = 2;
                }
            }
        }
    }
}

void MoveZone(MATRIKS * M, MATRIKS zoneMap, char gate) {
    *M = zoneMap;
    
    int i, j;
    POINT P;
    boolean found;

    
    found = false;
    i = 0;
    j = 0;

    if (gate == '<') {
        while ((i <= GetLastIdxBrs(*M)+1) && !found){
            i++;
            j = 0;
            while ((j <= GetLastIdxKol(*M)+1) && !found){
                j++;
                if (Elmt(*M,i,j) == '>'){
                    found = true;
                }
            }
        }
        if (found){
            P = MakePOINT(j-1,i-1);
        }
        Elmt(*M,i,j-1) = 'P';
    } else if (gate == '>') {
        while ((i <= GetLastIdxBrs(*M)+1) && !found){
            i++;
            j = 0;
            while ((j <= GetLastIdxKol(*M)+1) && !found){
                j++;
                if (Elmt(*M,i,j) == '<'){
                    found = true;
                }
            }
        }
        Elmt(*M,i,j+1) = 'P';
    } else if (gate == 'v') {
        while ((i <= GetLastIdxBrs(*M)+1) && !found){
            i++;
            j = 0;
            while ((j <= GetLastIdxKol(*M)+1) && !found){
                j++;
                if (Elmt(*M,i,j) == '^'){
                    found = true;
                }
            }
        }
        Elmt(*M,i+1,j) = 'P';
    } else if (gate == '^') {
        while ((i <= GetLastIdxBrs(*M)+1) && !found){
            i++;
            j = 0;
            while ((j <= GetLastIdxKol(*M)+1) && !found){
                j++;
                if (Elmt(*M,i,j) == 'v'){
                    found = true;
                }
            }
        }
        Elmt(*M,i-1,j) = 'P';
    }
}