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
/* Menghasilkan sebuah balanced tree dengan n node, NilTreeai setiap node dibaca */

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

// /* *** Traversal *** */
// void PrintPreorder(BinTree P) {
//     printf("(");

//     if (!IsTreeEmpty(P)) {
//         printf("%d", Akar(P));
//         PrintPreorder(Left(P));
//         PrintPreorder(Right(P));
//     }

//     printf(")\n");
// }
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (A()()) adalah pohon dengan 1 elemen dengan akar A
//    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
// void PrintInorder(BinTree P) {
//     printf("(");

//     if (!IsTreeEmpty(P)) {
//         PrintInorder(Left(P));
//         printf("%d", Akar(P));
//         PrintInorder(Right(P));
//     }

//     printf(")\n");
// }
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (()A()) adalah pohon dengan 1 elemen dengan akar A
//    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
// void PrintPostorder(BinTree P) {
//     printf("(");

//     if (!IsTreeEmpty(P)) {
//         PrintPostorder(Left(P));
//         PrintPostorder(Right(P));
//         printf("%d", Akar(P));
//     }

//     printf(")\n");
// }
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh: 
//    (()()A) adalah pohon dengan 1 elemen dengan akar A
//    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
// void PrintTree(BinTree P, int h) {
//     printf("");
// }
// /* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
// /* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
// /* Penulisan akar selalu pada baris baru (diakhiri newline) */
// /* Contoh, jika h = 2: 
// 1) Pohon preorder: (A()()) akan ditulis sbb:
// A
// 2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
// A
//   B
//   C
// 3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
// A
//   B
//     D
//   C
//     E
// */

// /* *** Searching *** */
// boolean SearchTree(BinTree P, infotype X) {
//     if (IsTreeEmpty(P)) {
//         return false;
//     } else if (Akar(P) == X) {
//         return true;
//     } else {
//         return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
//     }
// }
// /* Mengirimkan true jika ada node dari P yang berNilTreeai X */

// /* *** Fungsi-Fungsi Lain *** */
// int NbElmt(BinTree P) {
//     if (IsTreeEmpty(P)) {
//         return 0;
//     } else {
//         return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
//     }
// }
// /* Mengirimkan banyaknya elemen (node) pohon biner P */
// int NbDaun(BinTree P) {
//     if (IsTreeOneElmt(P)) {
//         return 1;
//     } else if (IsUnerLeft(P)) {
//         return (NbDaun(Left(P)));
//     } else if (IsUnerRight(P)) {
//         return (NbDaun(Right(P)));
//     } else {
//         return (NbDaun(Left(P)) + NbDaun(Right(P)));
//     }
// }
// /* Mengirimkan banyaknya daun (node) pohon biner P */
// /* Prekondisi: P tidak kosong */
// boolean IsSkewLeft(BinTree P) {
//     if (IsTreeEmpty(P)) {
//         return true;
//     } else if (IsTreeOneElmt(P)) {
//         return true;
//     } else {
//         return IsUnerLeft && IsSkewLeft(Left(P));
//     }
// }
// /* Mengirimkan true jika P adalah pohon condong kiri */
// /* Pohon kosong adalah pohon condong kiri */
// boolean IsSkewRight(BinTree P) {
//     if (IsTreeEmpty(P)) {
//         return true;
//     } else if (IsTreeOneElmt(P)) {
//         return true;
//     } else {
//         return IsUnerRight(P) && IsSkewRight(Right(P));
//     }
// }
// /* Mengirimkan true jika P adalah pohon condong kanan */
// /* Pohon kosong adalah pohon condong kanan */
// int Level(BinTree P, infotype X) {
//     if (Akar(P) == X) {
//         return 1;
//     } else if (IsBiner(P)) {
//         if (SearchTree(Left(P), X)) {
//             return 1 + Level(Left(P), X);
//         } else {
//             return 1 + Level(Right(P), X);
//         }
//     } else if (IsUnerLeft(P)) {
//         return 1 + Level(Left(P), X);
//     } else if (IsUnerRight(P)) {
//         return 1 + Level(Right(P), X);
//     }
// }
// /* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
//    Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
// int Tinggi(BinTree P) {
//     if (IsTreeEmpty(P)) {
//         return 0;
//     } else {
//         int TinggiR;
//         int TinggiL;
//         TinggiR = Tinggi(Right(P));
//         TinggiL = Tinggi(Left(P));
//         if (TinggiR > TinggiL) {
//             return 1 + TinggiR;
//         } else {
//             return 1 + TinggiL;
//         }
//     }
// }
// /* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
//    Mengirim "height" yaitu tinggi dari pohon */

// /* *** Operasi lain *** */
// void AddDaunTerkiri(BinTree *P, infotype X) {
//     if (IsTreeEmpty(*P)) {
//         *P = AlokNode(X);
//     } else if (IsUnerRight(*P)) {
//         Left(*P) = AlokNode(X);
//     } else {
//         AddDaunTerkiri(&(Left(*P)), X);
//     }
// }
// /* I.S. P boleh kosong */
// /* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
// void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
//     printf("");
// }
// /* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
// /* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
//         sebagai anak Kanan X (jika Kiri = false) */
// /*		Jika ada > 1 daun berNilTreeai X, diambil daun yang paling kiri */
// void DelDaunTerkiri(BinTree *P, infotype *X) {
//     if (IsTreeOneElmt(*P)) {
//         BinTree N;

//         *X = Akar(*P);
//         N = *P;
//         DealokNode(N);
//     } else if (IsUnerRight(*P)) {
//         DelDaunTerkiri(&Right(*P), X);
//     } else {
//         DelDaunTerkiri(&(Left(*P)), X);
//     }
// }
// /* I.S. P tidak kosong */
// /* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
//         disimpan pada daun terkiri yang dihapus */
// void DelDaun(BinTree *P, infotype X) {
//     if (IsTreeEmpty(*P)) {
//         if (IsTreeOneElmt(*P)) {
//             if (Akar(*P) == X) {
//                 addrNode N;

//                 N = *P;
//                 *P = NilTree;
//                 DealokNode(N);
//             }
//         } else {
//             DelDaun(&(Left(*P)), X);
//             DelDaun(&(Right(*P)), X);
//         }
//     }
// }
// /* I.S. P tidak kosong, minimum ada 1 daun berNilTreeai X. */
// /* F.S. Semua daun berNilTreeai X dihapus dari P. */
// List MakeListDaun(BinTree P) {
//     if (IsTreeEmpty(P)){
//         return NilTree;
//     } else if (IsTreeOneElmt(P)){
//         return Alokasi(Akar(P));
//     } else if (Tinggi(Left(P)) == 1 && Tinggi(Right(P)) == 1){
//         return (Concat(Alokasi(Akar(Left(P))), Alokasi(Akar(Right(P)))));
//     } else if (Tinggi(Left(P)) == 1){
//         return (Concat(Alokasi(Akar(Left(P))), MakeListDaun(Right(P))));
//     } else if (Tinggi(Right(P)) == 1){
//         return (Concat(MakeListDaun(Left(P)), Alokasi(Akar(Right(P)))));
//     } else {
//         return (Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P))));
//     }
// }
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
//    jika semua alokasi list berhasil.
//    Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListPreorder(BinTree P) {
//     if (IsTreeEmpty(P)) {
//         return NilTree;
//     } else {
//         address Q;
//         Q = Alokasi(Akar(P));
//         if (Q != NilTree) {
//             Next(Q) = MakeListPreorder(Left(P));
//             return Concat(Q, MakeListPreorder(Right(P)));
//         } else {
//             return NilTree;
//         }
//     }
// }
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
//    dengan urutan preorder, jika semua alokasi berhasil.   
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListLevel(BinTree P, int N) {
//     if (IsTreeEmpty(P)) {
//         return NilTree;
//     } else if (N < 1) {
//         return NilTree;
//     } else if (N == 1) {
//         return Alokasi(Akar(P));
//     } else {
//         return Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1));
//     }
// }
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
//    yang levelnya=N, jika semua alokasi berhasil. 
//    Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */

// /* *** Binary  Search  Tree  *** */
// boolean BSearch(BinTree P, infotype X) {
//     if (IsTreeEmpty(P)){
//         return false;
//     } else if (Akar(P) == X){
//         return true;
//     } else {
//         if (X < Akar(P)){
//             return BSearch(Left(P), X);
//         } else {
//             return BSearch(Right(P), X);
//         }
//     }
// }
// /* Mengirimkan true jika ada node dari P yang berNilTreeai X */

// void InsSearch(BinTree *P, infotype X) {
//     if (IsTreeEmpty(*P)) {
//         MakeTree(X, NilTree, NilTree, P);
//     } else if (X < Akar(*P)) {
//         InsSearch(&(Left(*P)), X);
//     } else if (X > Akar(*P)) {
//         InsSearch(&(Right(*P)), X);
//     } else if (X == Akar(*P)){
//         return;
//     }
// }
// /* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang berNilTreeai X. */

// void DelBtree(BinTree *P, infotype X) {
//     if (Akar(*P) == X) {
//         addrNode N;

//         N = *P;
//         *P = NilTree;
//         DealokNode(N);
//     } else if (X < Akar(*P)) {
//         DelBtree(&(Left(*P)), X);
//     } else {
//         DelBtree(&(Right(*P)), X);
//     }
// }
// /* I.S. Pohon P tidak  kosong */
// /* F.S. NilTreeai X yang dihapus pasti ada */
// /* Sebuah node dengan NilTreeai X dihapus */