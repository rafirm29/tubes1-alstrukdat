#include <stdio.h>
#include <stdlib.h>
#include "arraydinaction.h"

int main() {
    TabAction TA;
    MakeListAction(&TA, "Action/actionPrep.txt");
    printf("Nama action 1: %s\n", TA.TIAction[0].Aksi.TabKata);
    printf("Durasi action 1: %d\n", ElmtAction(TA, 0).Durasi);
    printf("Nama action 3: %s\n", TA.TIAction[2].Aksi.TabKata);
    printf("Durasi action 3: %d\n", ElmtAction(TA, 2).Durasi);
    // Kata build, buy, upgrade;
    // build.Length = 5;
    // build.TabKata[0] = 'b';
    // build.TabKata[1] = 'u';
    // build.TabKata[2] = 'i';
    // build.TabKata[3] = 'l';
    // build.TabKata[4] = 'd';

    // buy.Length = 3;
    // buy.TabKata[0] = 'b';
    // buy.TabKata[1] = 'u';
    // buy.TabKata[2] = 'y';

    // upgrade.Length = 7;
    // upgrade.TabKata[0] = 'u';
    // upgrade.TabKata[1] = 'p';
    // upgrade.TabKata[2] = 'g';
    // upgrade.TabKata[3] = 'r';
    // upgrade.TabKata[4] = 'a';
    // upgrade.TabKata[5] = 'd';
    // upgrade.TabKata[6] = 'e';

    // Action Build, Buy, Upgrade;
    // Build = MakeAction(build, 120);
    // Buy = MakeAction(buy, 30);
    // Upgrade = MakeAction(upgrade, 60);

    MakeEmptyAction(&TA, 6);
    AddAction(&TA, Build);
    // AddAction(&TA, Buy);
    AddAction(&TA, Upgrade);

    TulisIsiTabAction(TA);

    if (!IsAksiAda(TA, buy)) {
        printf("Tidak ada aksi buy.\n");
    } 

    return 0;
}