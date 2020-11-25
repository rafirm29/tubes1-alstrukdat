#ifndef inventory_H
#define inventory_H

#include "../../Mesin/mesinkata.h"
#include "../../boolean.h"

/* Definisi elemen */
typedef Kata namainv;
typedef int jumlah;

typedef struct { 
  namainv NamaInv;
  jumlah Jumlah;  
} Inventory;

/* ********* AKSES (Selektor) ********* */
/* Jika B adalah Barang, maka akses elemen : */
#define NamaInv(B) (B).NamaInv
#define JumlahInv(B) (B).Jumlah

/*** Konstruktor ***/
Inventory MakeInventory(Kata K, jumlah J);
/* Membuat inventory berdasarkan input namanya dan jumlahnya */

#endif