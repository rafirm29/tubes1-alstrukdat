#include <stdio.h>
#include "jam.h"

int main(){
    JAM J, J1;
    int A;
    J = MakeJAM(9,0);
    TulisJAM(J);
    J = NextMenit(J);
    TulisJAM(J);
    J = NextNMenit(J, 79);
    TulisJAM(J);
    J = NextNMenit(J, 50);
    TulisJAM(J);
    J = NextNMenit(J, 50);
    TulisJAM(J);
    J = PrevMenit(J);
    TulisJAM(J);
    J = PrevNMenit(J, 10);
    TulisJAM(J);
    return 0;
}