/*
13519030
13519038
13519150
13519154
13519162
*/

/**
 * gcc main.c Array/arraydinaction.c Array/Action/action.c Array/arraydinbarang.c Array/Barang/barang.c Array/arraydininventory.c Array/Inventory/inventory.c Matriks/matriks.c Mesin/mesinkata.c Mesin/mesinkar.c Point/point.c Jam/jam.c Player/player.c Queue/queue.c Command/command.c Wahana/wahana.c Tree/bintree.c Listberkait/listwahana.c -o main
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "boolean.h"
#include "Array/arraydinaction.h"
#include "Array/arraydinbarang.h"
#include "Array/arraydininventory.h"
// #include "Jam/jam.h"
// #include "List berkait/listlinier.h"
#include "Matriks/matriks.h"
#include "Mesin/mesinkata.h"
#include "Mesin/mesinkar.h"
// #include "MesinFile/mesinfile.h"
#include "Point/point.h"
#include "Jam/jam.h"
#include "Queue/queue.h"
// #include "Stack/stackt.h"
// #include "Tree/tree.h"
#include "Player/player.h"
#include "Wahana/wahana.h"
#include "Tree/bintree.h"
#include "Command/command.h"
#include "Listberkait/listwahana.h"


int main() {
    /*** DEKLARASI WAHANA ***/
    Wahana W1;
    Wahana W1_1, W1_2;
    MakeWahana(&W1, "Wahana/wahana1.txt");
    MakeWahana(&W1_1, "Wahana/wahana1_1.txt");
    MakeWahana(&W1_2, "Wahana/wahana1_2.txt");

    List listWahana;
    CreateEmptyWahana(&listWahana);

    // printf("**** BREAK POINT ****\n");
    // int xy;
    // scanf("%d", &xy);

    BinTree T1;
    T1 = Tree(W1, AlokNode(W1_1), AlokNode(W1_2));

    /*** DEKLARASI LIST BARANG ***/
    TabBarang ListBarang;
    MakeEmptyBarang(&ListBarang, 5);
    MakeListBarang(&ListBarang, "Array/Barang/barang.txt");

    /*** DEKLARASI LIST PERINTAH ***/
    // List perintah pada Prep Phase
    TabAction TAPrep;
    MakeEmptyAction(&TAPrep, 6);
    MakeListAction(&TAPrep, "Array/Action/actionPrep.txt");

    // List perintah pada Main Phase
    TabAction TAMain;
    MakeEmptyAction(&TAMain, 6);
    MakeListAction(&TAMain, "Array/Action/mainPrep.txt");

    /*************/
    Kata new;
    new.Length = 3;
    new.TabKata[0] = 'n';
    new.TabKata[1] = 'e';
    new.TabKata[2] = 'w';

    Kata udah;
    udah.Length = 4;
    udah.TabKata[0] = 'u';
    udah.TabKata[1] = 'd';
    udah.TabKata[2] = 'a';
    udah.TabKata[3] = 'h';

    Kata First, Nama, PerintahPrep, PerintahMain;

    printf("// Welcome to Willy wangky's fum factory!!//\n");
    printf("// New game / exit? //\n");
    Input(&First, false); // Input pertama


    /***** NEW GAME *****/
    if (IsKataSama(First, new)) {
        printf("Memulai permainan baru...\n");
        printf("Masukkan nama:\n");
        Input(&Nama, false);
        printf("Halo, %s\n", Nama.TabKata);
        sleep(1);
        printf("Loading...\n");
        sleep(1);
        printf("Selamat bermain!\n");
        sleep(1);

        /***** DEKLARASI PLAYER *****/
        Player P1;
        P1 = MakePlayer(Nama, "Array/Inventory/inventory.txt");

        /***** DEKLARASI VARIABEL UNIVERSAL *****/
        int day;
        boolean prepPhase;
        boolean mainPhase;
        boolean exit = false;
        day = 1; // Hari ke-day
        prepPhase = true;
        MATRIKS Map1, Map2, Map3, Map4;
        MATRIKS currentMap;

        /***** LOAD MAP *****/
        BacaMATRIKS(&Map1, "FileEksternal/peta1.txt");
        BacaMATRIKS(&Map2, "FileEksternal/peta2.txt");
        BacaMATRIKS(&Map3, "FileEksternal/peta3.txt");
        BacaMATRIKS(&Map4, "FileEksternal/peta4.txt");
        currentMap = Map1;

        while (!exit) { // Loop pergantian day
            /***** DEKLARASI VARIABEL *****/
            JAM currentJam, closingJam, hourRemaining;
            int timeRemaining;
            Queue Q;
            MakeEmptyQueue(&Q, 5); // Deklarasi queue dan mengosongkan queue.

            POINT PO;
            PO = PosisiOffice(currentMap); // Deklarasi Posisi office pada map pertama.

            /***************************************/
            /********** PREPERATION PHASE **********/
            /***************************************/

            currentJam = MakeJAM(21,0); // Deklarasi Jam saat preperation phase.
            closingJam = MakeJAM(9,0);

            while (prepPhase) {
                printf("Preperation day %d\n", day);

                TulisMATRIKS(currentMap);

                printf("\n\n");
                printf("Name: %s\n", Name(P1).TabKata);
                printf("Money: %d\n", Money(P1));

                timeRemaining = Durasi(currentJam, closingJam);
                hourRemaining = MenitToJAM(timeRemaining);
                printf("Current Time : ");
                TulisJAM(currentJam);
                printf("Closing Time : ");
                TulisJAM(closingJam);
                printf("Time Remaining : ");
                TulisJAM(hourRemaining);
                TulisIsiTabInventory(InvPlayer(P1));

                printf("Masukkan perintah ");
                if (IsInOffice(currentMap)) {
                    printf("(Masukkan 'office' untuk mengakses office) ");
                }
                printf(":\n");
                Input(&PerintahPrep, false);


                /* **** EKSEKUSI **** */
                if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 4).Aksi)) {             // Execute
                    mainPhase = true;
                    prepPhase = false;
                } else if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 5).Aksi)) {      // Main
                    PrintInfoWahana(listWahana);
                }
                /* **** PERGERAKAN **** */
                else if (PerintahPrep.Length == 1) {
                    if (PerintahPrep.TabKata[0] == 'w') {
                        Move(&currentMap, 'w', PO);
                    } else if (PerintahPrep.TabKata[0] == 'a') {
                        Move(&currentMap, 'a', PO);
                    } else if (PerintahPrep.TabKata[0] == 's') {
                        Move(&currentMap, 's', PO);
                    } else if (PerintahPrep.TabKata[0] == 'd') {
                        Move(&currentMap, 'd', PO);
                    }
                /* **** PERINTAH **** */
                } else if (IsAksiAda(TAPrep, PerintahPrep)) {
                    if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 0).Aksi)) {         // Buy
                        int i, j;
                        TulisIsiTabBarang(ListBarang);
                        while (true) {
                            printf("Beli barang nomor : ");
                            scanf("%d", &i);
                            if (i >= 1 && i <= NbElmtBarang(ListBarang)) break;
                            printf("Input tidak valid, silakan ulangi.\n");
                        }
                        while (true) {
                            printf("Jumlah : ");
                            scanf("%d", &j);
                            if (j > 0) break;
                            printf("Input tidak valid, silakan ulangi.\n");
                        }
                        Buy(&P1, ListBarang, i, j);
                    } else if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 1).Aksi)) {  // Build
                        boolean successBuild;
                        BuildWahana(W1, &P1, &currentMap, &successBuild);
                        if (successBuild) {
                            POINT currentP;
                            POINT wahanaBuild;
                            currentP = PosisiPlayer(currentMap);
                            wahanaBuild = MakePOINT(Absis(currentP), Ordinat(currentP)-1);
                            InsVLastWahana(&listWahana, W1, wahanaBuild);
                        }
                        sleep(1);
                    } else if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 2).Aksi)) {  // Upgrade
                        if (AdaBangunanSekitarPlayer(currentMap, PosisiPlayer(currentMap))) {
                            UpgradeWahana(T1, &P1, &currentMap);
                        } else {
                            printf("Tidak ada wahana sekitar player.\n");
                        }
                        sleep(1);
                    }
                    sleep(2);
                } else {
                    printf("Command tidak ditemukan.\n");
                }
            }

            /********************************/
            /********** MAIN PHASE **********/
            /********************************/

            currentJam = MakeJAM(9,0); // Deklarasi Jam saat main phase.
            closingJam = MakeJAM(21,0);

            while (mainPhase && JLT(currentJam, closingJam)) {
                printf("Main day %d\n", day);

                TulisMATRIKS(currentMap);

                printf("\n\n");

                printf("Name: %s\n", Name(P1).TabKata);
                printf("Money: %d\n", Money(P1));

                timeRemaining = Durasi(currentJam, closingJam);
                hourRemaining = MenitToJAM(timeRemaining);
                printf("Current Time : ");
                TulisJAM(currentJam);
                printf("Closing Time : ");
                TulisJAM(closingJam);
                printf("Time Remaining : ");
                TulisJAM(hourRemaining);

                if (rand() % 5 == 0) {
                    EnqueuePrio(&Q);
                }
                PrintAntrian(Q);

                printf("Masukkan perintah ");
                if (IsInOffice(currentMap)) {
                    printf("(Masukkan 'office' untuk mengakses office) ");
                }
                printf(":\n");
                Input(&PerintahMain, false);

                if (IsKataSama(PerintahMain, udah)) {// Exit
                    mainPhase = false;
                    prepPhase = true;
                }
                /**** PERGERAKAN ****/
                else if (PerintahMain.Length == 1) {
                    if (PerintahMain.TabKata[0] == 'w') {
                        Move(&currentMap, 'w', PO);
                        currentJam = NextNMenit(currentJam, 1);
                    } else if (PerintahMain.TabKata[0] == 'a') {
                        Move(&currentMap, 'a', PO);
                        currentJam = NextNMenit(currentJam, 1);
                    } else if (PerintahMain.TabKata[0] == 's') {
                        Move(&currentMap, 's', PO);
                        currentJam = NextNMenit(currentJam, 1);
                    } else if (PerintahMain.TabKata[0] == 'd') {
                        Move(&currentMap, 'd', PO);
                        currentJam = NextNMenit(currentJam, 1);
                    }
                } else if (IsAksiAda(TAMain, PerintahMain)) {
                    printf("BERAKSI\n");
                    KurangKesabaran(&Q);
                } else {
                    printf("Command tidak ditemukan.\n");
                }
            }
            day++;
        }
    }

    return 0;
}
