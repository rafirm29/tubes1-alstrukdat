/*
13519030
13519038
13519150
13519154
13519162
*/

/**
 * gcc main.c Array/arraydinaction.c Action/action.c Array/arraydinbarang.c Barang/barang.c Matriks/matriks.c Mesin/mesinkata.c Mesin/mesinkar.c Point/point.c Jam/jam.c Player/player.c Queue/queue.c -o main
 * */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "Array/arraydinaction.h"
#include "Array/arraydinbarang.h"
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


int main() {
    /*** DEKLARASI LIST BARANG ***/
    TabBarang ListBarang;
    MakeEmptyBarang(&ListBarang, 5);
    MakeListBarang(&ListBarang, "Barang/barang.txt");

    /*** DEKLARASI KATA ***/
    Kata new;
    new.Length = 3;
    new.TabKata[0] = 'n';
    new.TabKata[1] = 'e';
    new.TabKata[2] = 'w';

    TabAction ArrayPrep;
    Kata build, buy, upgrade;
    build.Length = 5;
    build.TabKata[0] = 'b';
    build.TabKata[1] = 'u';
    build.TabKata[2] = 'i';
    build.TabKata[3] = 'l';
    build.TabKata[4] = 'd';

    buy.Length = 3;
    buy.TabKata[0] = 'b';
    buy.TabKata[1] = 'u';
    buy.TabKata[2] = 'y';

    upgrade.Length = 7;
    upgrade.TabKata[0] = 'u';
    upgrade.TabKata[1] = 'p';
    upgrade.TabKata[2] = 'g';
    upgrade.TabKata[3] = 'r';
    upgrade.TabKata[4] = 'a';
    upgrade.TabKata[5] = 'd';
    upgrade.TabKata[6] = 'e';

    Action Build, Buy, Upgrade;
    Build = MakeAction(build, 120);
    Buy = MakeAction(buy, 30);
    Upgrade = MakeAction(upgrade, 60);

    MakeEmptyAction(&ArrayPrep, 6);
    AddAction(&ArrayPrep, Build);
    AddAction(&ArrayPrep, Buy);
    AddAction(&ArrayPrep, Upgrade);

    /*************/
    Kata main;
    main.Length = 4;
    main.TabKata[0] = 'm';
    main.TabKata[1] = 'a';
    main.TabKata[2] = 'i';
    main.TabKata[3] = 'n';

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
        /***** DEKLARASI PLAYER *****/
        Player P1;
        P1 = MakePlayer(Nama);

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
        printf("***DEBUG TEST 1***");
        BacaMATRIKS(&Map1, "FileEksternal/peta1.txt");
        BacaMATRIKS(&Map2, "FileEksternal/peta2.txt");
        BacaMATRIKS(&Map3, "FileEksternal/peta3.txt");
        BacaMATRIKS(&Map4, "FileEksternal/peta4.txt");
        currentMap = Map1;
        printf("***DEBUG TEST 2***");

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

                printf("Masukkan perintah ");
                if (IsInOffice(currentMap)) {
                    printf("(Masukkan 'office' untuk mengakses office) ");
                }
                printf(":\n");
                Input(&PerintahPrep, false);

                if (IsKataSama(PerintahPrep, main)) { // Execute
                    mainPhase = true;
                    prepPhase = false;
                }
                /**** PERGERAKAN ****/
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
                } else if (IsAksiAda(ArrayPrep, PerintahPrep)) {
                    if (IsKataSama(PerintahPrep, buy)) {
                        int i;
                        do {
                            TulisIsiTabBarang(ListBarang);
                            scanf("%d", &i);
                        } while (i < 1 || i > NbElmtBarang(ListBarang));
                    } else if (IsKataSama(PerintahPrep, build)) {
                        printf("");
                    } else if (IsKataSama(PerintahPrep, upgrade)) {
                        printf("");
                    }
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

                printf("\nMasukkan perintah:\n");
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
                } else if (IsAksiAda(ArrayPrep, PerintahMain)) {
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
