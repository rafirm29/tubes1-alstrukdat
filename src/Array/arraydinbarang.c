#include <stdio.h>
#include <stdlib.h>
#include "arraydinbarang.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabBarang *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    (*T).TI = (ElType *) malloc (maxel * sizeof (ElType));
    (*T).Neff = 0;
    (*T).MaxEl = maxel;
}

void Dealokasi(TabBarang *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(T);
    (*T).Neff = 0;
    (*T).MaxEl = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabBarang T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    return (T).Neff;
}

int MaxElement(TabBarang T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (T).MaxEl;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBarang T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}

IdxType GetLastIdx(TabBarang T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return ((T).Neff - 1);
}   

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabBarang T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMin) && (i < (T).MaxEl));
}

boolean IsIdxEff(TabBarang T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabBarang T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return ((T).Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabBarang T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return ((T).Neff == (T).MaxEl);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void TulisIsiTab(TabBarang T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    IdxType i;
    if (IsEmpty(T))
    {
        printf("Tidak ada barang\n");
    }
    else
    {
        for (i = 0; i < (T).Neff; i++)
        {
            printf("Barang %d\n", i+1);
            printf("Nama : \n");
            printf("Harga : %d\n", Harga(Elmt(T, i))); 
        } 
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
//IdxType Search1(TabInt T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
//void CopyTab(TabBarang Tin, TabBarang *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddBarang(TabBarang *T, ElType X){
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (!IsFull(*T))
    {
        Elmt(*T, (GetLastIdx(*T) + 1)) = X;
        (*T).Neff = (*T).Neff + 1;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastBarang(TabBarang *T, ElType *X){
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T, (GetLastIdx(*T)));
    (*T).Neff = (*T).Neff - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabBarang *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    (*T).MaxEl = (*T).MaxEl + num;
}

void ShrinkTab(TabBarang *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    (*T).MaxEl = (*T).MaxEl - num;
}

void CompactTab(TabBarang *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    (*T).MaxEl = (*T).Neff;
}