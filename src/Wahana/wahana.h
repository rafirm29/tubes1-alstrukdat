#ifndef wahana_H
#define wahana_H

#include "../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../Matriks/matriks.h"
#include "../Point/point.h"

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
    int jumlahPemainWahana;
    POINT lokasiWahana;
    int zona;
} Wahana;

// Cek apakah wahana penuh
void IsFullWahana(Wahana W);

// Menampilkan detail wahana
void MakeWahana(Wahana * W, char * file);

// Detail wahana
void Detail(Wahana W);

#endif