#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree(Wahana Akar, BinTree L, BinTree R) {
    BinTree T;
    T = AlokNode(Akar);
    if (T != NilTree) {
        Left(T) = L;
        Right(T) = R;
    }
    return T;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilTree) jika alokasi gagal */
void MakeTree(Wahana Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = NilTree jika alokasi gagal. */
BinTree BuildBalanceTree(int n) {
    Wahana Akar;
    BinTree L, R;
    if (n != 0) {
        scanf("%d", &Akar);
        L = BuildBalanceTree(n/2);
        R = BuildBalanceTree(n - (n/2) - 1);
        return Tree(Akar, L, R);
    } else {
        return NilTree;
    }

}
/* Menghasilkan sebuah balanced tree dengan n node, Nilai setiap node dibaca */

/* Manajemen Memory */
addrNode AlokNode(Wahana X) {
    addrNode N;
    N = (addrNode) malloc (sizeof(Node));
    if (N != NilTree) {
        Akar(N) = X;
        Left(N) = NilTree;
        Right(N) = NilTree;
    }
    return N;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NilTree, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = NilTree, Right(P)=NilTree */
/* Jika alokasi gagal, mengirimkan NilTree */
void DealokNode(addrNode P) {
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P) {
    return (P == NilTree);
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P) {
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        return ((Left(P) == NilTree) && (Right(P) == NilTree));
    }
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P) {
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        return ((Left(P) != NilTree) && (Right(P) == NilTree));
    }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P) {
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        return ((Left(P) == NilTree) && (Right(P) != NilTree));
    }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P) {
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        return ((Left(P) != NilTree) && (Right(P) != NilTree));
    }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
