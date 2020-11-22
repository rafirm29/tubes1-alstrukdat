#include <stdio.h>
#include "action.h"

/*** Konstruktor ***/
Action MakeAction (Kata K, durasi T){
/* Membuat aksi berdasarkan input namanya dan durasinya */
    Action A;
    (A).Aksi = K;
    (A).Durasi = T;
    return A;
}