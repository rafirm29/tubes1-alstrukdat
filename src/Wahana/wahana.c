#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

// Cek apakah wahana penuh
void IsFullWahana(Wahana W) {
    return (W.kapasitasWahana == W.jumlahPemainWahana);
}

// Menampilkan detail wahana
void MakeWahana(Wahana * W, char * file) {
    STARTFILE(file);
    Kata Nama;
    Kata Tipe;
    Kata Harga;
    Kata Kapasitas;
    Kata Durasi;
    Kata Deskripsi;
    Kata Status;
    Kata BiayaBuild;
    Kata BiayaUpgrade;
    Kata Wood;
    Kata Steel;
    Kata Iron;

    Input(&Nama, true);
    ADVFILE();
    Input(&Tipe, true);
    ADVFILE();
    Input(&Harga, true);
    ADVFILE();
    Input(&Kapasitas, true);
    ADVFILE();
    Input(&Durasi, true);
    ADVFILE();
    Input(&Deskripsi, true);
    ADVFILE();
    Input(&Status, true);
    ADVFILE();
    Input(&BiayaBuild, true);
    ADVFILE();
    Input(&BiayaUpgrade, true);
    ADVFILE();
    Input(&Wood, true);
    ADVFILE();
    Input(&Steel, true);
    ADVFILE();
    Input(&Iron, true);
    ADVFILE();

    (*W).namaWahana = Nama;
    (*W).tipeWahana = atoi(Tipe.TabKata);
    (*W).hargaWahana = atoi(Harga.TabKata);
    (*W).kapasitasWahana = atoi(Kapasitas.TabKata);
    (*W).durasiWahana = atoi(Durasi.TabKata);
    (*W).deskripsiWahana = Deskripsi;
    (*W).statusWahana = atoi(Status.TabKata);
    (*W).biayaBuild = atoi(BiayaBuild.TabKata);
    (*W).biayaUpgrade = atoi(BiayaUpgrade.TabKata);
    (*W).wood = atoi(Wood.TabKata);
    (*W).steel = atoi(Steel.TabKata);
    (*W).iron = atoi(Iron.TabKata);
    (*W).jumlahPemainWahana = 0;
    (*W).lokasiWahana = MakePOINT(0, 0);
    (*W).zona = 0;
}

// Detail wahana
void Detail(Wahana W) {
    printf("Nama wahana : %s\n", W.namaWahana.TabKata);
    printf("Tipe        : %d\n", W.tipeWahana);
    printf("Harga       : %d\n", W.hargaWahana);
    printf("Lokasi      : (%d,%d) Map %d\n", W.lokasiWahana.X, W.lokasiWahana.Y), W.zona;
    printf("Deskripsi   : %s\n", W.deskripsiWahana.TabKata);
    printf("Kapasitas   : %d orang\n", W.kapasitasWahana);
    printf("Durasi      : %d menit\n", W.durasiWahana);
    printf("Status      : ");
    if (W.statusWahana) {
        printf("Berfungsi\n");
    } else printf("Rusak\n");
    // History llist wahana
}