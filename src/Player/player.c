#include <stdio.h>
#include "player.h"

boolean IsEnough(Player P, money N) {
    return (Money(P) >= N);
}
/* Mengembalikan true jika uang player cukup untuk membayar sejumlah N */

boolean IsEnoughMaterial(Player P, Wahana W){
    return (    
        ElmtInventory(P.InvPlayer, 0).Jumlah >= W.wood &&
        ElmtInventory(P.InvPlayer, 1).Jumlah >= W.steel &&
        ElmtInventory(P.InvPlayer, 2).Jumlah >= W.iron
    );
}
/* Mengembalikan true jika material pada inventory player cukup untuk memangun wahana W */

Player MakePlayer(Kata K, char * file) {
    Player P;
    TabInventory I;
    MakeEmptyInventory(&I, 5);
    MakeListInventory(&I, file);
    Name(P) = K;
    Money(P) = 2000;
    InvPlayer(P) = I;

    return P;
}

void AddMoney(Player * P, money N) {
    Money(*P) = Money(*P) + N;
}
/* Menambahkan Money pada player sebanyak N */

void SubstractMoney(Player * P, money N) {
    if (IsEnough(*P, N)) {
        Money(*P) = Money(*P) - N;
    } else { /* Uang tidak menuckupi */
        printf("Uang tidak mencukupi!\n");
    }
}
/* Mengurangi Money pada player sebanyak N */