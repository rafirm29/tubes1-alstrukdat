#ifndef ARRAYDINBARANG_H
#define ARRAYDINBARANG_H

#include "../boolean.h"
#include "Barang/barang.h"
#include "../Mesin/mesinkata.h"

#define IdxMinBarang 0
#define IdxUndefBarang -1

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeBarang; /* type indeks */
typedef Barang ElTypeBarang;  /* type elemen tabel */
typedef struct{
  ElTypeBarang *TIBarang; /* memori tempat penyimpan elemen (container) */
  int NeffBarang;   /* >=0, banyaknya elemen efektif */
  int MaxElBarang;  /* ukuran elemen maximum tabel */
} TabBarang;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.NeffBarang  untuk mengetahui banyaknya elemen
   T.TIBarang[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffBaranf = 0
  Definisi elemen pertama : T.TIBarang[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TIBarang[i] dengan i=T.NeffBarang */

/* ********** SELEKTOR ********** */
#define NeffBarang(T) (T).NeffBarang
#define ElmtBarang(T, i) (T).TIBarang[(i)]
#define MaxElBarang(T) (T).MaxElBarang

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBarang(TabBarang *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

void DealokasiBarang(TabBarang *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElBarang(T)=0; NeffBarang(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtBarang(TabBarang T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxElementBarang(TabBarang T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxTypeBarang GetFirstIdxBarang(TabBarang T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxTypeBarang GetLastIdxBarang(TabBarang T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidBarang(TabBarang T, IdxTypeBarang i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEffBarang(TabBarang T, IdxTypeBarang i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyBarang(TabBarang T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean IsFullBarang(TabBarang T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTabBarang(TabBarang T);
// Menuliskan isi sesuai implementasi

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddBarang(TabBarang *T, ElTypeBarang X);
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void MakeListBarang(TabBarang *T, char * file);
// Membentuk list dari file

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastBarang(TabBarang *T, ElTypeBarang *X);
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTabBarang(TabBarang *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTabBarang(TabBarang *T, int num);
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTabBarang(TabBarang *T);
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */

#endif
