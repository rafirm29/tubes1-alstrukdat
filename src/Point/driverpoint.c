#include "point.h"

int main(){
    POINT P1, P2;
    int x, y;

    BacaPOINT(&P1);
    CopyPOINT(&P2,P1);
    if (EQ(P1,P2)){
        TulisPOINT(P2);
        printf("\n kedua titik equal\n");
    } else{
        printf("Kedua titik tidak equal\n");
    }
}