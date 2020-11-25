#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

int main() {
    Wahana W;
    MakeWahana(&W, "wahana.txt");
    Detail(W);

    return 0;
}