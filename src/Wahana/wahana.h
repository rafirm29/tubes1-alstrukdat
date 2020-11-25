#ifndef wahana_H
#define wahana_H

#include "../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../Matriks/matriks.h"
#include "../Point/point.h"
#include "../Player/player.h"

typedef struct {
    Kata namaWahana;
    int tipeWahana;
    int hargaWahana;
    int kapasitasWahana;
    int durasiWahana;
    Kata deskripsiWahana;
    boolean statusWahana;
    int biayaBuild;
    int biayaUpgrade;
    int wood;
    int steel;
    int iron;
} Wahana;


// Menampilkan detail wahana
void MakeWahana(Wahana * W, char * file);

// Membuat wahana baru
void BuildWahana(Wahana W, Player * P, MATRIKS * M);

// Detail wahana
void Detail(Wahana W);

#endif