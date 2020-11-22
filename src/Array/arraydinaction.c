#include <stdio.h>
#include <stdlib.h>
#include "arraydinaction.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyAction(TabAction *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    (*T).TIAction = (ElTypeAction *) malloc (maxel * sizeof (ElTypeAction));
    (*T).NeffAction = 0;
    (*T).MaxElAction = maxel;
}

void DealokasiAction(TabAction *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(T);
    (*T).NeffAction = 0;
    (*T).MaxElAction = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

int NbElmtAction(TabAction T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    return (T).NeffAction;
}

/* *** Daya tampung container *** */
int MaxElementAction(TabAction T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (T).MaxElAction;
}

/* *** Selektor INDEKS *** */
IdxTypeAction GetFirstIdxAction(TabAction T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMinAction;
}

IdxTypeAction GetLastIdxAction(TabAction T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return ((T).NeffAction - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidAction(TabAction T, IdxTypeAction i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMinAction) && (i < (T).MaxElAction));
}

boolean IsIdxEffAction(TabAction T, IdxTypeAction i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i >= GetFirstIdxAction(T) && i <= GetLastIdxAction(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyAction(TabAction T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return ((T).NeffAction == 0);
}

/* *** Test tabel penuh *** */

boolean IsFullAction(TabAction T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return ((T.NeffAction == (T).MaxElAction));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
//void BacaIsi(TabBarang *T);
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */

void TulisIsiTabAction(TabAction T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    IdxTypeAction i;
    if (IsEmptyAction(T))
    {
        printf("Tidak ada aksi\n");
    }
    else
    {
        for (i = 0; i < (T).NeffAction; i++)
        {
          printf("Aksi : %s\n", Aksi(ElmtAction(T, i)));
          printf("Durasi : %d\n", Durasi(ElmtAction(T,i)));
        } 
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */

IdxTypeAction SearchIdxAksi (TabAction T, aksi X){
// Mengirim index adanya aksi X jika tidak ada mengirim idxundef
  boolean found = false
  int i = GetFirstIdxAction(T);
  while (!found && i < (T).NeffAction)
  {
    if (IsKataSama(Aksi(ElmtAction(T, i)), X))
    {
      found = true;
    }
    else
    {
      i = i + 1;
    }
  }
  if (found)
  {
    return i;
  }
  else
  {
    return IdxUndefAction;
  }
}

boolean IsAksiAda (TabAction T, aksi X){
// Mengirim true jika aksi ada false jika tidak
  boolean found = false;
  int i = GetFirstIdxAction(T);
  while (!found && i < (T).NeffAction)
  {
    if (IsKataSama(Aksi(ElmtAction(T, i)), X))
    {
      found = true;
    }
    else
    {
      i = i + 1;
    }
  }
  return found;
}

Action SearchAction (TabAction T, aksi X){
  boolean found = false;
  int i = GetFirstIdxAction(T);
  while (!found && i < (T).NeffAction)
  {
    if (IsKataSama(Aksi(ElmtAction(T, i)), X)){
      found = true;
    }
    else
    {
      i = i + 1;
    }
  }
  if (found)
  {
    return ElmtAction(T, i);
  }
  else
  {
    return NULL;
  }
}

/* ********** OPERASI LAIN ********** */
//void CopyTab(TabBarang Tin, TabInt *Tout);
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAction(TabAction *T, ElTypeAction X){
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (!IsFullAction(*T))
    {
        ElmtAction(*T, (GetLastIdxAction(*T) + 1)) = X;
        (*T).NeffAction = (*T).NeffAction + 1;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastAction(TabAction *T, ElTypeAction *X){
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = ElmtAction(*T, (GetLastIdxAction(*T)));
    (*T).NeffAction = (*T).NeffAction - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTabAction(TabAction *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    (*T).MaxElAction = (*T).MaxElAction + num;
}

void ShrinkTabAction(TabAction *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    (*T).MaxElAction = (*T).MaxElAction - num;
}

void CompactTabAction(TabAction *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    (*T).MaxElAction = (*T).NeffAction;
}