#ifndef ARRAYDINACTION_H
#define ARRAYDINACTION_H

#include "../boolean.h"
#include "Action/action.h"

#define IdxMinAction 0
#define IdxUndefAction -1

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeAction; /* type indeks */
typedef Action ElTypeAction;  /* type elemen tabel */
typedef struct{
  ElTypeAction *TIAction; /* memori tempat penyimpan elemen (container) */
  int NeffAction;   /* >=0, banyaknya elemen efektif */
  int MaxElAction;  /* ukuran elemen / elemen maximum tabel */
} TabAction;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.NeffAction untuk mengetahui banyaknya elemen efektif
   T.TIAction[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffAction = 0
  Definisi elemen pertama : T.TIAction[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TIAction[i] dengan i=T.NeffAction */

/* ********** SELEKTOR ********** */
#define NeffAction(T) (T).NeffAction
#define ElmtAction(T, i) (T).TIAction[(i)]
#define MaxElAction(T) (T).MaxElAction

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyAction(TabAction *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

void DealokasiAction(TabAction *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElAction(T)=0; NeffAction(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtAction(TabAction T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxElementAction(TabAction T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxTypeAction GetFirstIdxAction(TabAction T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxTypeAction GetLastIdxAction(TabAction T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidAction(TabAction T, IdxTypeAction i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEffAction(TabAction T, IdxTypeAction i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyAction(TabAction T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean IsFullAction(TabAction T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/** Baca Tulis **/
void TulisIsiTabAction(TabAction T);
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: dituliskan elemen tabel sesuai implementasi */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxTypeAction SearchIdxAksi (TabAction T, aksi X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */


boolean IsAksiAda (TabAction T, aksi X);
/* Mengecek apakah ada aksi dengan nama aksi X */

Action SearchAction (TabAction T, aksi X);
/* mencari aksi dalam tabel dan mengembalikan lokasinya */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAction(TabAction *T, ElTypeAction X);
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void MakeListAction(TabAction *T, char * file);
// Membaca file kemudian membuat list barang.

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastAction(TabAction *T, ElTypeAction *X);
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTabAction(TabAction *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTabAction(TabAction *T, int num);
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTabAction(TabAction *T);
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */

#endif
