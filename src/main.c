/*
13519030
13519038
13519150
13519154
13519162
*/

/**
 * gcc main.c Array/arraydinaction.c Array/Action/action.c Array/arraydinbarang.c Array/Barang/barang.c Array/arraydininventory.c Array/Inventory/inventory.c Matriks/matriks.c Mesin/mesinkata.c Mesin/mesinkar.c Point/point.c Jam/jam.c Player/player.c Queue/queue.c Command/command.c Wahana/wahana.c Tree/bintree.c Listberkait/listwahana.c Listberkait/listlinier.c Graph/graph.c Stack/stackt.c -o main
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "boolean.h"
#include "Array/arraydinaction.h"
#include "Array/arraydinbarang.h"
#include "Array/arraydininventory.h"
// #include "List berkait/listlinier.h"
#include "Matriks/matriks.h"
#include "Mesin/mesinkata.h"
#include "Mesin/mesinkar.h"
#include "Point/point.h"
#include "Jam/jam.h"
#include "Queue/queue.h"
#include "Player/player.h"
#include "Wahana/wahana.h"
#include "Tree/bintree.h"
#include "Command/command.h"
#include "Listberkait/listwahana.h"
#include "Graph/graph.h"
#include "Stack/stackt.h"


int main() {
    /*** DEKLARASI WAHANA ***/
    Wahana W1, W2;
    Wahana W1_1, W1_2;
    MakeWahana(&W1, "Wahana/wahana1.txt");
    MakeWahana(&W1_1, "Wahana/wahana1_1.txt");
    MakeWahana(&W1_2, "Wahana/wahana1_2.txt");
    MakeWahana(&W2, "Wahana/wahana2.txt");

    /*** DEKLARASI LIST WAHANA ***/
    // List wahana yang tersedia pada map
    List listWahana;
    CreateEmptyWahana(&listWahana);

    // List wahana yang dapat dibangun
    List daftarWahana;
    CreateEmptyWahana(&daftarWahana);
    W1.lokasiWahana = MakePOINT(0,0);
    InsVLastWahana(&daftarWahana, W1);
    // InsVLastWahana(&daftarWahana, W2, MakePOINT(0, 0));


    /*** DEKLARASI GRAPH ***/
    Graph G;
    MakeGraph(&G, 4);   // Membuat graph dengan 4 node untuk merepresentasikan zona pada Map
    /* Menghubungkan masing-masing zona Map */
    AddLink(&G, 1, 2);  
    AddLink(&G, 1, 3);
    AddLink(&G, 2, 4);
    AddLink(&G, 3, 4);
    int currentZone = G.First->info;    // Deklarasi zona pertama yaitu pada Map 1

    // printf("**** BREAK POINT ****\n");
    // int xy;
    // scanf("%d", &xy);
    
    /*** DEKLARASI STACK ***/
    Stack StackPerintah;
    CreateEmptyStack(&StackPerintah);

    /*** DEKLARASI UPGRADE TREE ***/
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
    MakeListAction(&TAMain, "Array/Action/actionMain.txt");

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
        Elmt(currentMap, 5, 11) = 'P';


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
                if (IsInOffice(currentMap, PO)) {
                    printf("(Masukkan 'office' untuk mengakses office) ");
                }
                printf(":\n");
                Input(&PerintahPrep, false);


                /* **** EKSEKUSI **** */
                if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 4).Aksi)) {             // Execute
                    Stack S;
                    infoStack X;

                    POINT currentP;
                    currentP = PosisiPlayer(currentMap);

                    /* Membalik stack agar perintah pengguna sesuai dengan urutan */
                    CreateEmptyStack(&S);
                    while (!IsEmptyStack(StackPerintah)) {
                        Pop(&StackPerintah, &X, 0, 0);
                        Push(&S, X, 0, 0);
                    }

                    /* Proses eksekusi perintah dari stack */
                    while (!IsEmptyStack(S)) {
                        Pop(&S, &X, 0, 0);
                        if (X.action == 1) {                                // Buy
                            Buy(&P1, ListBarang, X.idxcode, X.Jumlah);
                        } else if (X.action == 2) {                         // Build
                            /* Pemilihan wahana */
                            addressWahana P;
                            P = FirstLWahana(daftarWahana);
                            for (int i = 0; i < X.idxcode; i++){
                                P = NextLWahana(P);
                            }
                            Wahana WBuild;
                            WBuild = P->info;
                            WBuild.lokasiWahana = X.lokasiBuild;
                            WBuild.zona = X.Jumlah;
                            switch (X.Jumlah)   // Zona
                            {
                            case 1:
                                BuildWahana(WBuild, &P1, &Map1, X.lokasiBuild);
                                break;
                            case 2:
                                BuildWahana(WBuild, &P1, &Map2, X.lokasiBuild);
                                break;
                            case 3:
                                BuildWahana(WBuild, &P1, &Map3, X.lokasiBuild);
                                break;
                            case 4:
                                BuildWahana(WBuild, &P1, &Map4, X.lokasiBuild);
                                break;
                            default:
                                break;
                            }
                            InsVLastWahana(&listWahana, WBuild);
                        } else if (X.action == 3) {                         // Upgrade
                            switch (X.Jumlah)   // Zona
                            {
                            case 1:
                                UpgradeWahana(T1, &P1, &Map1, X.idxcode, X.lokasiBuild, &listWahana);
                                break;
                            case 2:
                                UpgradeWahana(T1, &P1, &Map2, X.idxcode, X.lokasiBuild, &listWahana);
                                break;
                            case 3:
                                UpgradeWahana(T1, &P1, &Map3, X.idxcode, X.lokasiBuild, &listWahana);
                                break;
                            case 4:
                                UpgradeWahana(T1, &P1, &Map4, X.idxcode, X.lokasiBuild, &listWahana);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    switch (currentZone)
                            {
                            case 1:
                                currentMap = Map1;
                                break;
                            case 2:
                                currentMap = Map2;
                                break;
                            case 3:
                                currentMap = Map3;
                                break;
                            case 4:
                                currentMap = Map4;
                                break;
                            default:
                                break;
                            }
        
                    
                    Elmt(currentMap, Ordinat(currentP)+1, Absis(currentP)+1) = 'P';
                    
                    // mainPhase = true;
                    // prepPhase = false;
                } else if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 5).Aksi)) {      // Main
                    PrintInfoWahana(listWahana);
                }
                /* **** PERGERAKAN **** */
                else if (PerintahPrep.Length == 1) {
                    boolean changeZone;
                    int prevZone;
                    if (PerintahPrep.TabKata[0] == 'w') {
                        prevZone = currentZone;
                        Move(&currentMap, 'w', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 1) {                 // Map 3 ke 1
                                CopyMATRIKS(currentMap, &Map3);
                                MoveZone(&currentMap, Map1, '^');
                                PO = PosisiOffice(currentMap);
                            }
                             else if (currentZone == 2) {
                                CopyMATRIKS(currentMap, &Map4);     // Map 4 ke 2
                                MoveZone(&currentMap, Map2, '^');
                                PO = MakePOINT(0, 0);
                            }
                        }
                    } else if (PerintahPrep.TabKata[0] == 'a') {
                        prevZone = currentZone;
                        Move(&currentMap, 'a', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 1) {                 // Map 2 ke 1
                                CopyMATRIKS(currentMap, &Map2);
                                MoveZone(&currentMap, Map1, '<');
                                PO = PosisiOffice(currentMap);
                            }
                            else if (currentZone == 3) {
                                CopyMATRIKS(currentMap, &Map4);     // Map 4 ke 3
                                MoveZone(&currentMap, Map3, '<');
                                PO = MakePOINT(0, 0);
                            }
                        }
                    } else if (PerintahPrep.TabKata[0] == 's') {
                        prevZone = currentZone;
                        Move(&currentMap, 's', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 3) {                 // Map 1 ke 3
                                CopyMATRIKS(currentMap, &Map1);
                                MoveZone(&currentMap, Map3, 'v');
                                PO = MakePOINT(0, 0);
                            }
                            else if (currentZone == 4) {
                                CopyMATRIKS(currentMap, &Map2);     // Map 2 ke 4
                                MoveZone(&currentMap, Map4, 'v');
                                PO = MakePOINT(0, 0);
                            }
                        }
                    } else if (PerintahPrep.TabKata[0] == 'd') {
                        prevZone = currentZone;
                        Move(&currentMap, 'd', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 2) {                 // Map 1 ke 2
                                CopyMATRIKS(currentMap, &Map1);
                                MoveZone(&currentMap, Map2, '>');
                                PO = MakePOINT(0, 0);
                            }
                            else if (currentZone == 4) {
                                CopyMATRIKS(currentMap, &Map3);     // Map 3 ke 4
                                MoveZone(&currentMap, Map4, '>');
                                PO = MakePOINT(0, 0);
                            }
                        }
                    }
                /* **** PERINTAH **** */
                } else if (IsAksiAda(TAPrep, PerintahPrep)) {
                    Kata inputAksi;
                    if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 0).Aksi)) {         // Buy
                        int i, j;
                        TulisIsiTabBarang(ListBarang);
                        while (true) {
                            printf("Beli barang nomor : ");
                            Input(&inputAksi, false);
                            i = atoi(inputAksi.TabKata);
                            if (i >= 1 && i <= NbElmtBarang(ListBarang)) break;
                            printf("Input tidak valid, silakan ulangi.\n");
                        }
                        while (true) {
                            printf("Jumlah : ");
                            Input(&inputAksi, false);
                            j = atoi(inputAksi.TabKata);
                            if (j > 0) break;
                            printf("Input tidak valid, silakan ulangi.\n");
                        }

                        /* Mengecek apakah uang player cukup */
                        int B = j * (ListBarang.TIBarang[i-1].Harga); // Harga barang dikali jumlah barang
                        if (IsEnough(P1, B)) {
                            infoStack X;
                            int D;

                            X.action = 1;
                            X.idxcode = i;
                            X.Jumlah = j;
                            D = ElmtAction(TAPrep, 0).Durasi;
                            Push(&StackPerintah, X, D, B);
                        } else printf("Uang anda tidak mencukupi!\n");

                    } else if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 1).Aksi)) {  // Build
                        POINT currentP;
                        currentP = PosisiPlayer(currentMap);

                        /* Mengecek apakah 1 blok di atas player kosong */
                        if (Elmt(currentMap, Ordinat(currentP), Absis(currentP)+1) != '-') {
                            char C = Elmt(currentMap, Ordinat(currentP), Absis(currentP)+1);
                            printf("Tidak bisa membangun! Ada ");
                            switch (C)
                            {
                            case '*':
                                printf("tembok ");
                                break;
                            case 'O':
                                printf("office ");
                                break;
                            case 'A':
                                printf("antrian ");
                                break;
                            case '^':
                                printf("gerbang ");
                                break;
                            default:
                                printf("wahana ");
                                break;
                            } printf("di atas.\n");
                        } 
                        /* Jika kosong, dijalankan perintah build */
                        else {
                            int i;
                            PrintInfoWahana(daftarWahana);
                                while (true) {
                                printf("Bangun wahana nomor : ");
                                Input(&inputAksi, false);
                                i = atoi(inputAksi.TabKata);
                                if (i >= 1 && i <= NbElmtWahana(daftarWahana)) break;
                                printf("Input tidak valid, silakan ulangi.\n");
                            }
                            // Loop ke index wahana yang dipilih
                            addressWahana P;
                            P = FirstLWahana(daftarWahana);
                            for (int j = 0; j < i-1; j++) {
                                P = NextLWahana(P);
                            }

                            Wahana WBuild;
                            WBuild = P->info;
                            if (IsEnough(P1, WBuild.biayaBuild) && IsEnoughMaterial(P1, WBuild)) {
                                infoStack X;
                                POINT currentP;
                                int B, D;
                                B = WBuild.biayaBuild;
                                D = ElmtAction(TAPrep, 1).Durasi;

                                X.action = 2;
                                X.Jumlah = currentZone;
                                X.idxcode = i-1;
                                currentP = PosisiPlayer(currentMap);
                                X.lokasiBuild = MakePOINT(Absis(currentP), Ordinat(currentP)-1);

                                /***DEBUG***/
                                printf("***DEBUG***\n");

                                Push(&StackPerintah, X, D, B);
                                Elmt(currentMap, Ordinat(currentP), Absis(currentP)+1) = 'W';
                            }
                        }
                        sleep(1);
                    } else if (IsKataSama(PerintahPrep, ElmtAction(TAPrep, 2).Aksi)) {  // Upgrade
                        if (AdaBangunanSekitarPlayer(currentMap, PosisiPlayer(currentMap))) {
                            int i;
                            printf("Upgrade %s menjadi ?\n", Akar(T1).namaWahana.TabKata);
                            printf("\t1. %s (Biaya : %d)\n", Akar(Left(T1)).namaWahana.TabKata, Akar(Left(T1)).biayaUpgrade);
                            printf("\t\tMaterial needed : Wood x%d, Steel x%d, Iron x%d\n", Akar(Left(T1)).wood, Akar(Left(T1)).steel, Akar(Left(T1)).iron);
                            printf("\t2. %s (Biaya : %d)\n", Akar(Right(T1)).namaWahana.TabKata, Akar(Right(T1)).biayaUpgrade);
                            printf("\t\tMaterial needed : Wood x%d, Steel x%d, Iron x%d\n", Akar(Right(T1)).wood, Akar(Right(T1)).steel, Akar(Right(T1)).iron);
                            while (true) {
                                printf("Input: ");
                                Input(&inputAksi, false);
                                i = atoi(inputAksi.TabKata);
                                if (i == 1 || i == 2) break;
                                printf("Input invalid! Silakan input kembali.\n");
                            }
                            // Mengecek biaya upgrade dan wahana tujuan upgrade
                            int B;
                            Wahana WUp;
                            switch (i)
                            {
                            case 1:
                                WUp = Akar(Left(T1));
                                B = Akar(Left(T1)).biayaUpgrade;
                                break;
                            case 2:
                                WUp = Akar(Right(T1));
                                B = Akar(Right(T1)).biayaUpgrade;
                                break;
                            default:
                                break;
                            }

                            if (IsEnough(P1, B) && IsEnoughMaterial(P1, WUp)) {
                                infoStack X;
                                int D;

                                X.action = 3;
                                X.Jumlah = currentZone;
                                switch (currentZone)
                                {
                                case 1:
                                    X.matriks = Map1; 
                                    break;
                                case 2:
                                    X.matriks = Map2; 
                                    break;
                                case 3:
                                    X.matriks = Map3; 
                                    break;
                                case 4:
                                    X.matriks = Map4; 
                                    break;
                                default:
                                    break;
                                }
                                X.idxcode = i;
                                X.lokasiBuild = BangunanSekitarPlayer(currentMap, PosisiPlayer(currentMap));
                                D = ElmtAction(TAPrep, 2).Durasi;
                    
                                Push(&StackPerintah, X, D, B);
                            }

                            if (!IsEnough(P1, B)) {
                                printf("Uang anda tidak mencukupi!\n");
                            }
                            if (!IsEnoughMaterial(P1, WUp)) {
                                printf("Material anda tidak mencukupi!\n");
                            }
                        } else {
                            printf("Tidak ada wahana sekitar player.\n");
                        }
                        sleep(1);
                    }
                    sleep(1);
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
                    EnqueuePrio(&Q, listWahana);
                }
                PrintAntrian(Q);

                printf("Masukkan perintah ");
                if (IsInOffice(currentMap, PO)) {
                    printf("(Masukkan 'office' untuk mengakses office) ");
                }
                printf(":\n");
                Input(&PerintahMain, false);

                if (IsKataSama(PerintahMain, udah)) {// Exit
                    mainPhase = false;
                    prepPhase = true;
                }
                /**** PERGERAKAN ****/
                else if (PerintahPrep.Length == 1) {
                    boolean changeZone;
                    int prevZone;
                    if (PerintahPrep.TabKata[0] == 'w') {
                        prevZone = currentZone;
                        Move(&currentMap, 'w', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 1) {                 // Map 3 ke 1
                                CopyMATRIKS(currentMap, &Map3);
                                MoveZone(&currentMap, Map1, '^');
                                PO = PosisiOffice(currentMap);
                            }
                             else if (currentZone == 2) {
                                CopyMATRIKS(currentMap, &Map4);     // Map 4 ke 2
                                MoveZone(&currentMap, Map2, '^');
                                PO = MakePOINT(0, 0);
                            }
                        }
                        currentJam = NextNMenit(currentJam, 1);
                    } else if (PerintahPrep.TabKata[0] == 'a') {
                        prevZone = currentZone;
                        Move(&currentMap, 'a', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 1) {                 // Map 2 ke 1
                                CopyMATRIKS(currentMap, &Map2);
                                MoveZone(&currentMap, Map1, '<');
                                PO = PosisiOffice(currentMap);
                            }
                            else if (currentZone == 3) {
                                CopyMATRIKS(currentMap, &Map4);     // Map 4 ke 3
                                MoveZone(&currentMap, Map3, '<');
                                PO = MakePOINT(0, 0);
                            }
                        }
                        currentJam = NextNMenit(currentJam, 1);
                    } else if (PerintahPrep.TabKata[0] == 's') {
                        prevZone = currentZone;
                        Move(&currentMap, 's', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 3) {                 // Map 1 ke 3
                                CopyMATRIKS(currentMap, &Map1);
                                MoveZone(&currentMap, Map3, 'v');
                                PO = MakePOINT(0, 0);
                            }
                            else if (currentZone == 4) {
                                CopyMATRIKS(currentMap, &Map2);     // Map 2 ke 4
                                MoveZone(&currentMap, Map4, 'v');
                                PO = MakePOINT(0, 0);
                            }
                        }
                        currentJam = NextNMenit(currentJam, 1);
                    } else if (PerintahPrep.TabKata[0] == 'd') {
                        prevZone = currentZone;
                        Move(&currentMap, 'd', PO, &currentZone);
                        changeZone = prevZone == currentZone;
                        if (!changeZone) {
                            if (currentZone == 2) {                 // Map 1 ke 2
                                CopyMATRIKS(currentMap, &Map1);
                                MoveZone(&currentMap, Map2, '>');
                                PO = MakePOINT(0, 0);
                            }
                            else if (currentZone == 4) {
                                CopyMATRIKS(currentMap, &Map3);     // Map 3 ke 4
                                MoveZone(&currentMap, Map4, '>');
                                PO = MakePOINT(0, 0);
                            }
                        }
                        currentJam = NextNMenit(currentJam, 1);
                    }
                /**** PERINTAH ****/
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
