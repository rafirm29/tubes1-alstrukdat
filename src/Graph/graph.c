#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void CreateEmptyGraph(Graph *G){
    /* KAMUS LOKAL */

    /* ALGORITMA */
    FirstGraph(*G) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsEmptyGraph(Graph G){
    return (FirstGraph(G) == NULL);
}
/* Mengirimkan true jika graph kosong */

addressGraph AlokasiGraph(infotypeList X){
    addressGraph P;

    P = (addressGraph) malloc (sizeof(ElmtGraph));
    if (P != NULL) {
        InfoGraph(P) = X;
        NextGraph(P) = NULL;
        CreateEmptyList(&Link(P));
    }
    return P;
}
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka InfoGraph(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

void MakeGraph(Graph *G, int n){
    /* KAMUS LOKAL */
    addressGraph P;
    int i;

    /* ALGORITMA */
    CreateEmptyGraph(G);
    FirstGraph(*G) = AlokasiGraph(1);
    P = FirstGraph(*G);
    for (i = 2; i <= n; i++) {
        NextGraph(P) = AlokasiGraph(i);
        P = NextGraph(P);
    }
}
/* I. S. Graph G sembarang, n adalah jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void PrintGraph(Graph G){
    /* KAMUS LOKAL */
    addressGraph P;

    /* ALGORITMA */
    P = FirstGraph(G);
    printf("[");
    while (NextGraph(P) != NULL) {
        printf("%d, ", InfoGraph(P));
        P = NextGraph(P);
    }
    printf("%d", InfoGraph(P));
    printf("]\n");
}
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */

void AddLink(Graph *G, infotypeList n, infotypeList m){
    /* KAMUS LOKAL */
    addressGraph P1, P2;

    /* ALGORITMA */
    /* Proses menambahkan link elemen n dengan m */
    P1 = FirstGraph(*G);
    while (InfoGraph(P1) != n) {
        P1 = NextGraph(P1);
    }
    if (SearchList(Link(P1), m) == NULL) {
        InsVLastList(&Link(P1), m);
    }

    /* Proses menambahkan link elemen p dengan m */
    P2 = FirstGraph(*G);
    while (InfoGraph(P2) != m) {
        P2 = NextGraph(P2);
    }
    if (SearchList(Link(P2), n) == NULL) {
        InsVLastList(&Link(P2), n);
    }
}
/* I. S. Graph G terdefinisi, n dan p pasti tidak lebih dari jumlah building
   F. S. Link dari elemen n bertambah dengan p, dan sebaliknya (soalnya bolak balik)
   contoh :
   1 2->3
   2 1
   3 1
   Add(&G, 2, 3) 
   1 2->3
   2 1->3
   3 1->3 */

void PrintLink(Graph G, infotypeList X){
    /* KAMUS LOKAL */
    addressGraph P;
    ListLinier L;

    /* ALGORITMA */
    P = FirstGraph(G);
    while (InfoGraph(P) != X) {
        P = NextGraph(P);
    }
    L = Link(P);
    PrintInfoList(L);

}

boolean IsLinked(Graph G, infotypeList n, infotypeList m){
    /* KAMUS LOKAL */
    addressGraph P1;

    /* ALGORITMA */
    /* Proses menambahkan link elemen n dengan m */
    P1 = FirstGraph(G);
    while (InfoGraph(P1) != n) {
        P1 = NextGraph(P1);
    }

    if (SearchList(Link(P1), m) != NULL) {
        return true;
    } else {
        return false;
    }
}
/* Mengembalikan true jika pada link n ada p */

addressGraph SearchGraph(Graph G, infotypeList X){
    /* KAMUS LOKAL */
    addressGraph P;

    /* ALGORITMA */
    P = FirstGraph(G);
    while ((InfoGraph(P) != X) && (P != NULL)) {
        P = NextGraph(P);
    }

    return P;
}