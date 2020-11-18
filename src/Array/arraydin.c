// Irvin Andryan P. / 13519162
// file arraydin.c


#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    (*T).TI = (int*)malloc(maxel * sizeof(int));
    (*T).Neff = 0;
    (*T).MaxEl = maxel;
}

void Dealokasi(TabInt *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(T);
    (*T).Neff = 0;
    (*T).MaxEl = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    int banyakElmt;
    banyakElmt = T.Neff;
    return banyakElmt;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    int maxElmt;
    maxElmt = T.MaxEl;
    return maxElmt;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

    int firstIdx;
    firstIdx = IdxMin;
    return firstIdx;
}

IdxType GetLastIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    int lastIdx;
    lastIdx = T.Neff-1;
    return lastIdx;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    boolean valid;
    valid = false;
    if (i < T.MaxEl && i >= IdxMin)
    {
        valid = true;
    }
    return valid;
}

boolean IsIdxEff(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    boolean idxEff;
    idxEff = false;
    if (i >= GetFirstIdx(T) && i <= GetLastIdx(T)) 
    {
        idxEff = true;
    }
    return idxEff;   
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    boolean kosong;
    kosong = false;
    if (T.Neff == 0) 
    {
        kosong = true;
    }
    return kosong;
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    boolean penuh;
    penuh = false;
    if (T.Neff == T.MaxEl)
    {
        penuh = true;
    }
    return penuh;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    int N,i,maxel,el;
    do
    {
        scanf("%d",&N);
        (*T).Neff = N;
    } while (N<0 || N>=MaxElement(*T));
    if (N == 0)
    {   
        maxel = 0;
        MakeEmpty(T, maxel);
    }
    else
    {
        for (i = 0; i <= N; i++)
        {
            scanf("%d",&el);
            (*T).TI[i] = el;
        }
    }
}

void TulisIsiTab(TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    int i;
    if (IsEmpty(T))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            if (i == GetLastIdx(T))
            {
                printf("%d",T.TI[i]);
            }
            else
            {
                printf("%d,",T.TI[i]);
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt T;
    int i;
    if (IsEmpty(T1) && !IsEmpty(T2))
    {
        T = T2;
    }
    else if (IsEmpty(T2) && !IsEmpty(T1))
    {
        T = T1;
    }
    else if (T1.Neff == T2.Neff && T1.Neff != 0 && T2.Neff != 0)
    {   
        MakeEmpty(&T,T1.MaxEl);
        if (plus)
        {
            for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
            {
                T.TI[i] = T1.TI[i] + T2.TI[i];                
            }   
        }
        else
        {
            for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
            {
                T.TI[i] = T1.TI[i] - T2.TI[i];
            } 
        }
    }
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    boolean ekuivalen;
    ekuivalen = true;
    int i;
    i = GetFirstIdx(T1);
    if (T1.Neff == T2.Neff)
    {
        while (i <= T1.Neff && ekuivalen)
        {
            if (T1.TI[i] == T2.TI[i])
            {
                i = i + 1;
            }
            else
            {
                ekuivalen = false;
            }
        }
    }
    else
    {
        ekuivalen = false;
    }
    
    return ekuivalen;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    int i;
    boolean found;
    found = false;
    i = GetFirstIdx(T);
    while (i <= GetLastIdx(T) && !found)
    {
        if (T.TI[i] == X)
        {
            found = true;
        }
        else
        {
            i = i +1;
        } 
    }
    if (found)
    {
        return i;
    }
    else
    {
        return IdxUndef;
    }
}

boolean SearchB(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    int i;
    boolean found;
    found = false;
    i = GetFirstIdx(T);
    while (i <= GetLastIdx(T) && !found)
    {
        if (T.TI[i] == X)
        {
            found = true;
        }
        else
        {
            i = i +1;
        }
    }
    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    boolean asc = true;
    Sort(&T,asc);
    *Max = T.TI[GetLastIdx(T)];
    *Min = T.TI[GetFirstIdx(T)];
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
    (*Tout).MaxEl = Tin.MaxEl;
    (*Tout).Neff = Tin.Neff;
    (*Tout).TI = Tin.TI;
}

ElType SumTab(TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
    int jumlah;
    int i;
    jumlah = 0;
    if (IsEmpty(T))
    {
        jumlah = 0;
    }
    else
    {
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            jumlah = jumlah + T.TI[i];
        }
    }
    return jumlah;
}

int CountX(TabInt T, ElType X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    int jumlahMuncul;
    int i;
    jumlahMuncul = 0;
    i = GetFirstIdx(T);
    if (IsEmpty(T))
    {
        jumlahMuncul = 0;
    }
    else
    {
        while (i <= GetLastIdx(T))
        {
            if (T.TI[i] == X)
            {
                jumlahMuncul = jumlahMuncul + 1;
                i = i + 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return jumlahMuncul;
}

boolean IsAllGenap(TabInt T){
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
    boolean genap;
    int i;
    i = GetFirstIdx(T);
    genap = true;
    if (IsEmpty(T))
    {
        genap = true;
    }
    else
    {
        while (i <= GetLastIdx(T) && genap)
        {
            if (T.TI[i] % 2 != 0)
            {
                genap = false;
            }
            else
            {
                i = i + 1;
            }   
        }
    }
    return genap;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
    int i,j,swap;
    if(asc)
    {
        for (i = 0; i <= GetLastIdx(*T) -1; i++)
        {
            for (j = 0; j <= GetLastIdx(*T) - i -1; j++)
            {
                if ((*T).TI[j] > (*T).TI[j+1])
                {
                    swap = (*T).TI[j];
                    (*T).TI[j] = (*T).TI[j+1];
                    (*T).TI[j+1] = swap;
                }
            }
        }
    }
    else //descending
    {
        for (i = 0; i <= GetLastIdx(*T) -1; i++)
        {
            for (j = 0; j <= GetLastIdx(*T) - i -1; j++)
            {
                if ((*T).TI[j] < (*T).TI[j+1])
                {
                    swap = (*T).TI[j];
                    (*T).TI[j] = (*T).TI[j+1];
                    (*T).TI[j+1] = swap;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    (*T).Neff = (*T).Neff + 1;
    (*T).TI[GetLastIdx(*T)] = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    int i;
    i = GetLastIdx(*T);
    *X = T->TI[i];
    (*T).Neff = (*T).Neff - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
}

void ShrinkTab(TabInt *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
}

void CompactTab(TabInt *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    T->MaxEl = T->Neff;
}