#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "listwahana.h"

int main() {
    // Load wahana
    Wahana W1, W2, W3;
    MakeWahana(&W1, "../Wahana/wahana1.txt");
    MakeWahana(&W2, "../Wahana/wahana1_1.txt");
    MakeWahana(&W3, "../Wahana/wahana1_2.txt");
    POINT P = MakePOINT(1,1);
    W1.lokasiWahana = P; W1.zona = 1;
    W2.lokasiWahana = P; W2.zona = 2;
    W3.lokasiWahana = P; W3.zona = 3;

    // Make list wahana
    List listWahana;
    CreateEmptyWahana(&listWahana);

    // Menambahkan wahana dalam list
    InsVLastWahana(&listWahana, W1);
    InsVLastWahana(&listWahana, W2);
    InsVLastWahana(&listWahana, W3);

    // Menampilkan list wahana
    PrintInfoWahana(listWahana);

    // Randomize pemilihan wahana dalam list yang akan dirusak
    int i = rand() % 3;
    addressWahana Q;
    Q = FirstLWahana(listWahana);
    for (int j = 0; j < i; j++) {
        Q = NextLWahana(Q);
    }

    Q->info.statusWahana = 0; // Status wahana rusak

    // Print list wahana yang rusak
    PrintWahanaRusak(listWahana);



    return 0;
}