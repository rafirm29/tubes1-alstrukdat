/* dstackt.c : Driver stack */

#include "stackt.h"
#include <stdio.h>
#include "../Matriks/matriks.h"
#include "../Point/point.h"

int main() {
    // KAMUS
    Stack S;
    infoStack iS[3];
    infoStack newIS[3];

    // ALGORITMA
    CreateEmptyStack(&S);

    for (int i=1; i<=3; i++) {
        iS[i-1].action = i*1;
        iS[i-1].idxcode = i*2;
        iS[i-1].Jumlah = i*200;
        MakeMATRIKS(5,5,&(iS[i-1].matriks));
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++) {
                Elmt((iS[i-1].matriks), j, k) = (char) 64+i;
            }
        }
        iS[i-1].lokasiBuild = MakePOINT(2*i,3*i);
    }

    /* Test primitif stack dan print status Stack*/
    for (int i=0; i<3; i++) {
        Push(&S, iS[i], 1, 10);
    }

    PrintStack(S);

    for (int i=2; i>=0; i--) {
        Pop(&S, &(newIS[i]), 1, 10);
        printf("isi InfoStack ke-%d: \n", i+1);
        printf("Action: %d \n", newIS[i].action);
        printf("IndexCode: %d \n", newIS[i].idxcode);
        printf("Jumlah: %d \n", newIS[i].Jumlah);
        TulisPOINT(newIS[i].lokasiBuild); printf("\n");
        TulisMATRIKS(newIS[i].matriks); printf("\n\n");
    }

    /* test kondisi stack */
    printf("Stack Kosong? %d \n", IsEmptyStack(S));
    printf("Stack Penuh? %d \n", IsFullStack(S));



    return 0;
}