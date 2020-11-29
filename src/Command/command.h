#ifndef command_H
#define command_H

#include "../boolean.h"
#include "../Matriks/matriks.h"
#include "../Player/player.h"
#include "../Array/arraydinbarang.h"
#include "../Wahana/wahana.h"
#include "../Tree/bintree.h"
#include "../Listberkait/listwahana.h"

// Buy material
void Buy(Player * P, TabBarang B, IdxTypeBarang i, int Jumlah);
/* I.S. P terdefinisi, B adalah tabel daftar barang, i adalah idx barang yang valid, Jumlah adalah jumlah barang */
/* F.S. Jumlah barang dengan idx i pada P bertambah sebanyak Jumlah, uang pada P berkurang sesuai ketentuan harga barang */


// Membuat wahana baru
void BuildWahana(Wahana W, Player * P, MATRIKS * M, POINT lokBuild);
/* I.S. P terdefinisi, W adalah wahana yang ingin dibangun, M adalah map taman bermain, lokBuild adalah koordinat tempat wahana akan dibangun */
/* F.S. wahana terbangun pada lokasi lokBuild di M, uang serta material P berkurang */


// Mengupgrade wahana
void UpgradeWahana(BinTree T, Player * P, MATRIKS * M, int i, POINT lokUpgrade, List * L, int zona);
/* I.S. T adalah BinTree Upgrade wahana, P terdefinisi, M adalah map, L adalah List wahana yang telah dibangun */
/* lokUpgrade adalah koordinat wahana yang ingin diupgrade, zona adalah zona map wahana */
/* i adalah arah upgrade: 
    1. subpohon kiri, 
    2. subpohon kanan,  */
/* F.S. wahana pada L yang berkoordinat di lokUpgrade dengan zona zona terupgrade, material dan uang pada P berkurang, tanda wahana di M berubah */


#endif