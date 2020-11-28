/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "../boolean.h"
#include "../Listberkait/listlinier.h"

#define N 4 // Jumlah map

typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
	infotypeList info;
	List link;
	addressGraph next;
} ElmtGraph;
typedef struct {
	addressGraph First;
} Graph;

/* Definisi graph :
   Graph kosong : First(L) = Nil
   Setiap elemen dengan addressGraph P dapat diacu Info(P), Next(P)
   Elemen terakhir graph : jika addressnya Last, maka NextGraph(Last)=Nil */

#define InfoGraph(P) (P)->info
#define NextGraph(P) (P)->next
#define Link(P) 	 (P)->link
#define FirstGraph(G) ((G).First)

void CreateEmptyGraph(Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsEmptyGraphs(Graph G);
/* Mengirimkan true jika graph kosong */

addressGraph AlokasiGraph(infotypeList X);
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka InfoGraph(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

void MakeGraph(Graph *G, int n);
/* I. S. Graph G sembarang, n adalah jumlah building/ jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void PrintGraph(Graph G);
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */


void AddLink(Graph *G, infotypeList n, infotypeList m);
/* I. S. Graph G terdefinisi, n dan p pasti tidak lebih dari jumlah building
   F. S. Link dari elemen n bertambah dengan p, dan sebaliknya
   contoh :
   1 2->3
   2 1
   3 1
   Add(&G, 2, 3) 
   1 2->3
   2 1->3
   3 1->3 */

void PrintLink(Graph G, infotypeList X);

boolean IsLinked(Graph G, infotypeList n, infotypeList m);

addressGraph SearchGraph(Graph G, infotypeList X);

#endif