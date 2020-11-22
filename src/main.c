/*
13519030
13519038
13519150
13519154
13519162
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
// #include "Array/arraydin.h"
// #include "Jam/jam.h"
// #include "List berkait/listlinier.h"
#include "Matriks/matriks.h"
#include "Mesin/mesinkata.h"
#include "Mesin/mesinkar.h"
#include "MesinFile/mesinfile.h"
#include "Point/point.h"
#include "Jam/jam.h"
// #include "Queue/prioqueuechar.h"
// #include "Queue/queue.h"
// #include "Stack/stackt.h"
// #include "Tree/tree.h"
#include "Player/player.h"


int main() {
    /*** DEKLARASI KATA ***/
    Kata new;
    new.Length = 3;
    new.TabKata[0] = 'n';
    new.TabKata[1] = 'e';
    new.TabKata[2] = 'w';

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

    Kata nama;

    printf("// Welcome to Willy wangky's fum factory!!//\n");
    printf("// New game / load game / exit? //\n");
    STARTKATA(); // Input pertama

    
    /***** NEW GAME *****/
    if (IsKataSama(CKata, new)) {
        printf("Memulai permainan baru...\n");
        printf("Masukkan nama:\n");
        EndKata = false;
        STARTKATA();
        // char nama[CKata.Length] = CKata.TabKata;
        printf("Halo, %s\n", CKata.TabKata);
        /***** DEKLARASI PLAYER *****/
        Player P1;
        P1 = MakePlayer(CKata);

        /***** DEKLARASI VARIABEL UNIVERSAL *****/
        int day;
        boolean prepPhase;
        boolean mainPhase;
        boolean exit = false;
        day = 1; // Hari ke-day
        prepPhase = true;
        MATRIKS Map1, Map2, Map3, Map4;
        MATRIKS currentMap;

        BacaMATRIKS(&Map1, "FileEksternal/peta1.txt");
        BacaMATRIKS(&Map2, "FileEksternal/peta2.txt");
        BacaMATRIKS(&Map3, "FileEksternal/peta3.txt");
        BacaMATRIKS(&Map4, "FileEksternal/peta4.txt");
        currentMap = Map1;

        while (!exit) { // Loop pergantian day
            /********** PREPERATION PHASE **********/
            JAM currentJam, closingJam, hourRemaining;
            int timeRemaining; 
            currentJam = MakeJAM(9,0);
            closingJam = MakeJAM(21,0);    
            while (prepPhase) {
                char prepInput;
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
                /**
                 *  Name: wangkie kumalasari
                    Money: 1000
                    Current Time: 09.01
                    Closing Time: 21.00
                    Time Remaining: 12 hour(s) */

                printf("Masukkan perintah:\n");
                STARTKATA();

                if (IsKataSama(CKata, main)) { // Execute
                    mainPhase = true;
                    prepPhase = false;
                } 
                /**** PERGERAKAN ****/
                else if (CKata.TabKata[0] == 'w') {
                    Move(&currentMap, 'w');
                } else if (CKata.TabKata[0] == 'a') {
                    Move(&currentMap, 'a');
                } else if (CKata.TabKata[0] == 's') {
                    Move(&currentMap, 's');
                } else if (CKata.TabKata[0] == 'd') {
                    Move(&currentMap, 'd');
                }
                /**
                 * Office
                 * BUILD
                 * UPGRADE
                 * BUY
                 * UNDO
                 * EXEC/MAIN
                 */

                /***** MASUKKAN PERINTAH KE STACK *****/
            }

            /********** MAIN PHASE **********/
            while (mainPhase) {
                /***** MENJALANKAN PERINTAH STACK *****/
                char execInput;
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

                printf("\nMasukkan perintah:\n");
                STARTKATA();

                if (IsKataSama(CKata, udah)) {// Exit
                    mainPhase = false;
                    prepPhase = true;
                } 
                /**** PERGERAKAN ****/
                else if (CKata.TabKata[0] == 'w') {
                    Move(&currentMap, 'w');
                    currentJam = NextNMenit(currentJam, 5);
                } else if (CKata.TabKata[0] == 'a') {
                    Move(&currentMap, 'a');
                    currentJam = NextNMenit(currentJam, 5);
                } else if (CKata.TabKata[0] == 's') {
                    Move(&currentMap, 's');
                    currentJam = NextNMenit(currentJam, 5);
                } else if (CKata.TabKata[0] == 'd') {
                    Move(&currentMap, 'd');
                    currentJam = NextNMenit(currentJam, 5);
                }
            }
            day++;
        }
    }

    return 0;
}