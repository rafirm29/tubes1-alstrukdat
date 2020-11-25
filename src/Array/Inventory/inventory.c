#include <stdio.h>
#include "inventory.h"

/*** Konstruktor ***/
Inventory MakeInventory(Kata K, jumlah J){
/* Membuat inventory berdasarkan input namanya dan jumlahnya */
    Inventory P;
    (P).NamaInv = K;
    (P).Jumlah = J;
    return P;
}