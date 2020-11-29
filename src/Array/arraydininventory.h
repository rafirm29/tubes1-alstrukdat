#ifndef ARRAYDININVENTORY_H
#define ARRAYDININVENTORY_H

#include "../boolean.h"
#include "Inventory/inventory.h"
#include "../Mesin/mesinkata.h"

#define IdxMinInventory 0
#define IdxUndefInventory -1

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeInventory; /* type indeks */
typedef Inventory ElTypeInventory;  /* type elemen tabel */
typedef struct{
  ElTypeInventory *TIInventory; /* memori tempat penyimpan elemen (container) */
  int NeffInventory;   /* >=0, banyaknya elemen efektif */
  int MaxElInventory;  /* ukuran elemen maximum tabel */
} TabInventory;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.NeffInventory  untuk mengetahui banyaknya elemen
   T.TIInventory[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffInventory = 0
  Definisi elemen pertama : T.TIInventory[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TIInventory[i] dengan i=T.NeffInventory */

/* ********** SELEKTOR ********** */
#define NeffInventory(T) (T).NeffInventory
#define ElmtInventory(T, i) (T).TIInventory[(i)]
#define MaxElInventory(T) (T).MaxElInventory

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyInventory(TabInventory *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

void DealokasiInventory(TabInventory *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElInventory(T)=0; NeffInventory(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtInventory(TabInventory T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int MaxElementInventory(TabInventory T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */

IdxTypeInventory GetFirstIdxInventory(TabInventory T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxTypeInventory GetLastIdxInventory(TabInventory T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidInventory(TabInventory T, IdxTypeInventory i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEffInventory(TabInventory T, IdxTypeInventory i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyInventory(TabInventory T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean IsFullInventory(TabInventory T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTabInventory(TabInventory T);
// menulis isi tabel sesuai implementasi

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxTypeInventory SearchIdxInventory (TabInventory T, namainv X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

boolean IsInventoryAda (TabInventory T, namainv X);
// true jika ada inventory dengan namainventory X


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddInventory(TabInventory *T, ElTypeInventory X);
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void SubtractInventory(TabInventory *T, ElTypeInventory X);

void MakeListInventory(TabInventory *T, char * file);

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastInventory(TabInventory *T, ElTypeInventory *X);
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTabInventory(TabInventory *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTabInventory(TabInventory *T, int num);
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTabInventory(TabInventory *T);
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */

#endif
