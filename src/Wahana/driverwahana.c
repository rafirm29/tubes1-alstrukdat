#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"
#include "../Matriks/matriks.h"

int main() {
    Wahana W;
    MATRIKS Map;
    Player P1;
    P1.Money = 1000;
    MakeWahana(&W, "wahana.txt");
    Detail(W);
    BacaMATRIKS(&Map, "../FileEksternal/peta1.txt");
    TulisMATRIKS(Map);
    BuildWahana(W, &P1, &Map);
    printf("\n");
    TulisMATRIKS(Map);
    BuildWahana(W, &P1, &Map);
    printf("\n");
    TulisMATRIKS(Map);

    return 0;
}