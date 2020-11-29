#include <stdio.h>
#include <stdlib.h>
#include "arraydininventory.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyInventory(TabInventory *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    (*T).TIInventory = (ElTypeInventory *) malloc (maxel * sizeof (ElTypeInventory));
    (*T).NeffInventory = 0;
    (*T).MaxElInventory = maxel;
}

void DealokasiInventory(TabInventory *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElInventory(T)=0; NeffInventory(T)=0 */
    free(T);
    (*T).NeffInventory = 0;
    (*T).MaxElInventory = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtInventory(TabInventory T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    return ((T).NeffInventory);
}

/* *** Daya tampung container *** */

int MaxElementInventory(TabInventory T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (T).MaxElInventory;
}

/* *** Selektor INDEKS *** */
IdxTypeInventory GetFirstIdxInventory(TabInventory T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMinInventory;
}

IdxTypeInventory GetLastIdxInventory(TabInventory T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return ((T).NeffInventory - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidInventory(TabInventory T, IdxTypeInventory i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMinInventory) && (i < (T).MaxElInventory));
}

boolean IsIdxEffInventory(TabInventory T, IdxTypeInventory i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i >= GetFirstIdxInventory(T) && i <= GetLastIdxInventory(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyInventory(TabInventory T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return ((T).NeffInventory == 0);
}

/* *** Test tabel penuh *** */
boolean IsFullInventory(TabInventory T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return ((T).NeffInventory == (T).MaxElInventory);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTabInventory(TabInventory T){
    IdxTypeInventory i;
    if (IsEmptyInventory(T))
    {
        printf("Inventory Kosong\n");
    }
    else
    {
        printf("Inventory : \n");
        for (i = 0; i < NeffInventory(T); i++)
        {
            // printf("Inventory : %d\n", i+1);
            printf("\t- %s (%dx)\n", NamaInv(ElmtInventory(T,i)).TabKata, JumlahInv(ElmtInventory(T, i)));
            // printf("Jumlah : %d\n", Jumlah(ElmtInventory(T, i))); 
        } 
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxTypeInventory SearchIdxInventory (TabInventory T, namainv X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    boolean found = false;
    int i = GetFirstIdxInventory(T);
    while (!found && i < (T).NeffInventory)
    {
        if (IsKataSama(NamaInv(ElmtInventory(T, i)), X))
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
        return IdxUndefInventory;
    }
}

boolean IsInventoryAda (TabInventory T, namainv X){
    boolean found = false;
    int i = GetFirstIdxInventory(T);
    while (!found && i < (T).NeffInventory)
    {
        if (IsKataSama(NamaInv(ElmtInventory(T, i)), X))
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

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddInventory(TabInventory *T, ElTypeInventory X){
/* Proses: Menambahkan barang sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (IsEmptyInventory(*T))
    {
        ElmtInventory(*T, 0) = X;
        NeffInventory(*T) = 1;
    }
    else
    {
        IdxTypeInventory i = SearchIdxInventory(*T, NamaInv(X));
        if (i != IdxUndefInventory)
        {
            JumlahInv(ElmtInventory(*T,i)) += JumlahInv(X);
        }
        else
        {
            ElmtInventory(*T, (GetLastIdxInventory(*T) + 1)) = X;
            NeffInventory(*T) = NeffInventory(*T) + 1;
        }        
    }
}

void SubtractInventory(TabInventory *T, ElTypeInventory X){
// I.S. barang ada di dalam inventory dan jumlah yang dipakai <= jumlah yang ada
    IdxTypeInventory i = SearchIdxInventory(*T, NamaInv(X));
    JumlahInv(ElmtInventory(*T,i)) -= JumlahInv(X);
}

void MakeListInventory(TabInventory *T, char * file) {
    Inventory I;
    int jumlah;
    STARTFILE(file);
    while (CC != '.') {
        Kata NamaBarang;
        Kata JumlahBarang;
        Input(&NamaBarang, true);
        ADVFILE();
        Input(&JumlahBarang, true);
        ADVFILE();
        jumlah = atoi(JumlahBarang.TabKata);
        NamaInv(I) = NamaBarang;
        JumlahInv(I) = jumlah;
        AddInventory(T, I);
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastInventory(TabInventory *T, ElTypeInventory *X){
/* Proses : Menghapus barang terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = ElmtInventory(*T, (GetLastIdxInventory(*T)));
    NeffInventory(*T) = NeffInventory(*T) - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTabInventory(TabInventory *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    MaxElInventory(*T) = MaxElInventory(*T) + num;
}

void ShrinkTabInventory(TabInventory *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    MaxElInventory(*T) = MaxElInventory(*T) - num;
}

void CompactTabInventory(TabInventory *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    MaxElInventory(*T) = NeffInventory(*T);
}