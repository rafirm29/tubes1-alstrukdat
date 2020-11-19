#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

int main() {
    STARTKATA(); // Gunakan enter
    printf("%s\n", CKata.TabKata);
    ADVKATA();
    printf("%s\n", CKata.TabKata);
    STARTKATA(); // Tambahkan mark
    printf("%s\n", CKata.TabKata);
    STARTKATA();
    printf("%s\n", CKata.TabKata);

    return 0;
}