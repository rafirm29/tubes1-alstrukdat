#include <stdio.h>
#include <stdlib.h>
#include "arraydinbarang.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBarang(TabBarang *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    (*T).TIBarang = (ElTypeBarang *) malloc (maxel * sizeof (ElTypeBarang));
    (*T).NeffBarang = 0;
    (*T).MaxElBarang = maxel;
}

void DealokasiBarang(TabBarang *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(T);
    (*T).NeffBarang = 0;
    (*T).MaxElBarang = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtBarang(TabBarang T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    return (T).NeffBarang;
}

int MaxElementBarang(TabBarang T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (T).MaxElBarang;
}

/* *** Selektor INDEKS *** */
IdxTypeBarang GetFirstIdxBarang(TabBarang T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMinBarang;
}

IdxTypeBarang GetLastIdxBarang(TabBarang T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return ((T).NeffBarang - 1);
}   

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidBarang(TabBarang T, IdxTypeBarang i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMinBarang) && (i < (T).MaxElBarang));
}

boolean IsIdxEffBarang(TabBarang T, IdxTypeBarang i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i >= GetFirstIdxBarang(T) && i <= GetLastIdxBarang(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyBarang(TabBarang T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return ((T).NeffBarang == 0);
}

/* *** Test tabel penuh *** */
boolean IsFullBarang(TabBarang T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return ((T).NeffBarang == (T).MaxElBarang);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void TulisIsiTabBarang(TabBarang T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    IdxTypeBarang i;
    if (IsEmptyBarang(T))
    {
        printf("Tidak ada barang\n");
    }
    else
    {
        printf("Ingin membeli apa?\n");
        for (i = 0; i < (T).NeffBarang; i++)
        {
            //printf("Barang %d\n", i+1);
            printf("\t%d. %s (Harga: %d)\n", i+1, Nama(ElmtBarang(T, i)).TabKata, Harga(ElmtBarang(T, i)));
            //printf("Harga : %d\n", Harga(ElmtBarang(T, i))); 
        } 
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
// IdxTypeBarang SearchIdxBarang (TabBarang T, nama X){
// /* Search apakah ada elemen tabel T yang bernilai X */
// /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
// /* Jika tidak ada, mengirimkan IdxUndef */
// /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
// /* Skema Searching yang digunakan bebas */
//   boolean found = false;
//   int i = GetFirstIdxBarang(T);
//   while (!found && i < (T).NeffBarang)
//   {
//     if (IsKataSama(Nama(ElmtBarang(T, i)), X))
//     {
//       found = true;
//     }
//     else
//     {
//       i = i + 1;
//     }
//   }
//   if (found)
//   {
//     return i;
//   }
//   else
//   {
//     return IdxUndefBarang;
//   }
// }

// boolean IsBarangAda (TabBarang T, nama X){
//   boolean found = false;
//   int i = GetFirstIdxBarang(T);
//   while (!found && i < (T).NeffBarang)
//   {
//     if (IsKataSama(Nama(ElmtBarang(T, i)), X))
//     {
//       found = true;
//     }
//     else
//     {
//       i = i + 1;
//     }
//   }
//   return found;
// }

/* ********** OPERASI LAIN ********** */
//void CopyTab(TabBarang Tin, TabBarang *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddBarang(TabBarang *T, ElTypeBarang X){
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (IsEmptyBarang(*T))
    {
        ElmtBarang(*T, 0) = X;
        NeffBarang(*T) = 1;
    } else
    {
        ElmtBarang(*T, (GetLastIdxBarang(*T) + 1)) = X;
        (*T).NeffBarang = (*T).NeffBarang + 1;
    }
}

void MakeListBarang(TabBarang *T, char * file) {
    Barang B;
    int harga;

    STARTFILE(file);
    while (CC != '.') {
        Kata NamaBarang;
        Kata HargaBarang;
        Input(&NamaBarang, true);
        ADVFILE();
        Input(&HargaBarang, true);
        ADVFILE();
        harga = atoi(HargaBarang.TabKata);
        Nama(B) = NamaBarang;
        Harga(B) = harga;
        AddBarang(T, B);
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastBarang(TabBarang *T, ElTypeBarang *X){
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = ElmtBarang(*T, (GetLastIdxBarang(*T)));
    (*T).NeffBarang = (*T).NeffBarang - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTabBarang(TabBarang *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    (*T).MaxElBarang = (*T).MaxElBarang + num;
}

void ShrinkTabBarang(TabBarang *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    (*T).MaxElBarang = (*T).MaxElBarang - num;
}

void CompactTabBarang(TabBarang *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    (*T).MaxElBarang = (*T).NeffBarang;
}