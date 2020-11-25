#ifndef player_H
#define player_H

#include "../Mesin/mesinkata.h"
#include "../Array/arraydininventory.h"
#include "../boolean.h"

/* Definisi elemen */
typedef Kata name;
typedef int money;

typedef struct { 
  name Name;
  money Money;
  TabInventory InvPlayer;
} Player;

/* ********* AKSES (Selektor) ********* */
/* Jika P adalah Player, maka akses elemen : */
#define Name(P) (P).Name
#define Money(P) (P).Money
#define InvPlayer(P) (P).InvPlayer

/*** Test keadaan uang ***/
boolean IsEnough(Player P, money N);
/* Mengembalikan true jika uang player cukup untuk membayar sejumlah N */

/*** Konstruktor ***/
Player MakePlayer(Kata K, char * file);
/* Membuat player berdasarkan input namanya */

/*** Operasi terhadap money ***/
void AddMoney(Player * P, money N);
/* Menambahkan Money pada player sebanyak N */

void SubstractMoney(Player * P, money N);
/* Mengurangi Money pada player sebanyak N */

#endif