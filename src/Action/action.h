#ifndef action_H
#define action_H

#include "../Mesin/mesinkata.h"
#include "../boolean.h"

/* Definisi elemen */
typedef Kata aksi;
typedef int durasi;

typedef struct { 
    aksi Aksi;
    durasi Durasi;  
} Action;

/* ********* AKSES (Selektor) ********* */
/* Jika B adalah Barang, maka akses elemen : */
#define Aksi(P) (P).Aksi
#define DurasiAksi(B) (B).Durasi

/*** Konstruktor ***/
Action MakeAction (Kata K, durasi T);
/* Membuat aksi berdasarkan input namanya dan durasinya */

#endif