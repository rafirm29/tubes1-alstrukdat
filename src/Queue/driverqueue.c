#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "queue.c"

Queue Q;
pengunjung X;
int Maxel;

int main(){
    //Insert Max Element Q
    printf("Masukkan maksimum antrian : ");
    scanf("%d", &Maxel);
    MakeEmptyQueue(&Q, Maxel);

    int menu,menu2;
    printf("Ingin mencoba driver?\n");
    printf("Jika iya ketik 1\n");
    scanf("%d", &menu);
    while (menu == 1){
        printf("\nDriver Antrian\n");
        printf("1. IsEmpty\n");
        printf("2. IsFull\n");
        printf("3. Banyak Antrian\n");
        printf("4. Add Antrian\n");
        printf("5. Del Antrian\n");
        printf("6. Kurangin Kesabaran Orang\n");
        printf("999. Exit\n");

        scanf("%d", &menu2);

        if(menu2 == 1){
            //Fungsi IsEmpty
            printf("Apakah antrian kosong? "); //jika kosong akan keluar angka 1 jika benar, jika salah keluar angka 0
            printf("%d\n", IsEmpty(Q));
        } else if (menu2 == 2){
            //Fungsi IsFull
            printf("Apakah antrian penuh? "); //jika kosong akan keluar angka 1 jika benar, jika salah keluar angka 0
            printf("%d\n", IsFull(Q));
        } else if (menu2 == 3){
            //Jumlah Antrian
            printf("Banyaknya antrian : ");
            printf("%d\n", NBElmt(Q));
        } else if (menu2 == 4){
            //Add antrian
            EnqueuePrio(&Q);
            PrintAntrian(Q); printf("\n");
        } else if (menu2 == 5){
            //Del antrian
            Dequeue(&Q, &X);
            printf("[%d,%d]\n", JumlahOrang(X), Kesabaran(X));
            PrintAntrian(Q);
        } else if (menu2 == 6){
            //Mengecek apakah kesabaran pengunjung berkurang
            KurangKesabaran(&Q);
            PrintAntrian(Q);
        } else {
            printf("Hanya terdapat 6 menu\n");
        }
    }
    return 0;
}
