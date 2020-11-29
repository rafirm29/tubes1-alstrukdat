/* *** ADT MATRIKS *** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../boolean.h"
#include "../Point/point.h"
#include "../Mesin/mesinkar.h"
#include <stdio.h>

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 10
#define KolMin 1
#define KolMax 20

typedef int indeks; /* indeks baris, kolom */
typedef char ElType;

typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

void MakeMATRIKS (int NB, int NK, MATRIKS * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

indeks GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

POINT PosisiPlayer (MATRIKS M);

POINT PosisiOffice (MATRIKS M);

POINT PosisiBangunan (MATRIKS M);

POINT PosisiAntrian (MATRIKS M){

boolean IsInOffice (MATRIKS M, POINT PO);

POINT BangunanSekitarPlayer (MATRIKS M, POINT Player);

boolean AdaBangunanSekitarPlayer (MATRIKS M, POINT Player);

POINT AntrianSekitarPlayer (MATRIKS M, POINT Antrian);

boolean AdaAntrianSekitarPlayer (MATRIKS M, POINT Antrian);

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl) ;

void BacaMATRIKS (MATRIKS * M, char * file);

void TulisFileMatriks(MATRIKS M,FILE *f);

void TulisMATRIKS (MATRIKS M);

void Move (MATRIKS * M, char X, POINT PO, int * zone);

void MoveZone(MATRIKS * M, MATRIKS zoneMap, char gate);

#endif