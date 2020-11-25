#include <stdio.h>
#include <stdlib.h>
#include "barang.h"

/*** Konstruktor ***/
Barang MakeBarang(Kata K, harga H){
/* Membuat barang berdasarkan input namanya dan harganya */
    Barang B;
    (B).Nama = K;
    (B).Harga = H;
    return B;
}

