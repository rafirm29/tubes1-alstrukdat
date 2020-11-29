#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main() {
    Wahana W1;
    Wahana W1_1, W1_2;
    MakeWahana(&W1, "../Wahana/wahana1.txt");
    MakeWahana(&W1_1, "../Wahana/wahana1_1.txt");
    MakeWahana(&W1_2, "../Wahana/wahana1_2.txt");

    BinTree P1;
    P1 = Tree(W1, AlokNode(W1_1), AlokNode(W1_2));
    printf("Nama wahana upgrade 1 : %s\n", Akar(Left(P1)).namaWahana.TabKata);
    printf("Biaya : %d\n", Akar(Left(P1)).biayaUpgrade);
    printf("Nama wahana upgrade 2 : %s\n", Akar(Right(P1)).namaWahana.TabKata);
    printf("Biaya : %d\n", Akar(Right(P1)).biayaUpgrade);

    return 0;
}