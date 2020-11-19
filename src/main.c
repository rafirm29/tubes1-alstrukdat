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
// #include "MesinFile/mesinfile.h"
// #include "Point/point.h"
// #include "Queue/prioqueuechar.h"
// #include "Queue/queue.h"
// #include "Stack/stackt.h"
// #include "Tree/tree.h"


int main() {
    /*** DEKLARASI KATA ***/
    Kata new;
    new.Length = 3;
    new.TabKata[0] = 'n';
    new.TabKata[1] = 'e';
    new.TabKata[2] = 'w';

    printf("// Welcome to Willy wangky's fum factory!!//\n");
    printf("// New game / load game / exit? //\n");
    STARTKATA(); // Input pertama

    
    /***** NEW GAME *****/
    if (IsKataSama(CKata, new)) {
        printf("Memulai permainan baru...\n");
        printf("Masukkan nama:\n");
        EndKata = false;
        STARTKATA();
        ADVKATA();
        // char nama[CKata.Length] = CKata.TabKata;
        printf("Halo, %s\n", CKata.TabKata);
        // /***** DEKLARASI VARIABEL UNIVERSAL *****/
        // int day;
        // boolean prepPhase;
        // boolean mainPhase;
        // boolean exit = false;
        // day = 1; // Hari ke-day
        // prepPhase = true;
        // MATRIKS Map1, Map2, Map3, Map4;
        // MATRIKS currentMap;

        // BacaMATRIKS(&Map1, "FileEksternal/peta1.txt");
        // BacaMATRIKS(&Map2, "FileEksternal/peta2.txt");
        // BacaMATRIKS(&Map3, "FileEksternal/peta3.txt");
        // BacaMATRIKS(&Map4, "FileEksternal/peta4.txt");
        // currentMap = Map1;

        // while (!exit) { // Loop pergantian day

        //     /********** PREPERATION PHASE **********/
        //     while (prepPhase) {
        //         char prepInput;
        //         printf("Preperation day %d\n", day);
                
        //         TulisMATRIKS(currentMap);

        //         printf("Masukkan perintah:\n");
        //         STARTKATA();

        //         if (CKata == 'e') { // Execute
        //             mainPhase = true;
        //             prepPhase = false;
        //         } /* elif ... (TBD) */

        //         /***** MASUKKAN PERINTAH KE STACK *****/
        //     }

        //     /********** MAIN PHASE **********/
        //     while (mainPhase) {
        //         char execInput;
        //         printf("Preperation day %d\n", day);
        //         /***
        //          * 
        //          * TAMPIL MATRIKS DAN LEGEND
        //          * 
        //          * */
        //         scanf("Masukkan perintah: %c", &execInput);

        //         if (execInput == 'e') {// Exit
        //             mainPhase = false;
        //             prepPhase = true;
        //         } /* elif ... (TBD) */
        //     }
        //     day++;
        // }
    }

    return 0;
}