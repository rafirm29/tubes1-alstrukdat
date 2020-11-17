/* File: prioqueue.c */
/* Implementasi PrioQueueChar */

#include <stdio.h>
#include "boolean.h"
#include "prioqueuechar.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
boolean IsFull (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return ((Head(Q)==0) && (Tail(Q)==MaxEl(Q)-1));
}
int NBElmt (PrioQueueChar Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)){
        return 0;
    }
    if (IsFull(Q)){
        return MaxEl(Q);
    }
    return ((Tail(Q) - Head(Q) + 1) % MaxEl(Q));
}
/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype *)malloc(Max * sizeof(infotype));

    if ((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X;
    } else {
        Tail(*Q) = (Tail(*Q)+1)%MaxEl(*Q);
        InfoTail(*Q) = X;

        int i;
        i = Head(*Q);
        boolean benar = false;

        while (i != Tail(*Q)){
            if (!benar && Prio(Elmt(*Q, i)) > Prio(X)){
                benar = true;
            } if (benar) {
                infotype temp = Elmt(*Q, i);
                Elmt(*Q, i) = X;
                X = temp;
            } if (i == MaxEl(*Q)){
                i = 1;
            } else {
                i = i + 1;
            }
        }
        InfoTail(*Q) = X;
    }
}
void Dequeue (PrioQueueChar * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    *X = InfoHead(*Q);
    Prio(*X) = Prio(InfoHead(*Q));
    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
    }
}
/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
    infotype el;

    while (!IsEmpty(Q)){
        Dequeue(&Q, &el);
        printf("%d %c\n", Prio(el), Info(el));
    }

    printf("#\n");
}
