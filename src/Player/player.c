#include <stdio.h>
#include "player.h"

boolean IsEnough(Player P, money N) {
    return (Money(P) >= N);
}
/* Mengembalikan true jika uang player cukup untuk membayar sejumlah N */

Player MakePlayer(Kata K) {
    Player P;
    Name(P) = K;
    Money(P) = 1000;

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