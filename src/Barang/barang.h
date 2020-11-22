#ifndef barang_H
#define barang_H

#include "../Mesin/mesinkata.h"
#include "../boolean.h"

/* Definisi elemen */
typedef Kata nama;
typedef int harga;

typedef struct { 
  nama Nama;
  harga Harga;  
} Barang;

/* ********* AKSES (Selektor) ********* */
/* Jika B adalah Barang, maka akses elemen : */
#define Nama(B) (B).Nama
#define Harga(B) (B).Harga

/*** Konstruktor ***/
Barang MakeBarang(Kata K, harga H);
/* Membuat barang berdasarkan input namanya dan harganya */

#endif