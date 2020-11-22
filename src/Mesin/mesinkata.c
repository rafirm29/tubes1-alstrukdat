/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include <stdio.h>
#include "../boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
  while (CC== BLANK){
     ADV();
  }
}
void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
   START();
   IgnoreBlank();
   if (CC == MARK) {
      EndKata = true;
   }
   else{
      EndKata = false;
      SalinKata();
   }
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   if (CC == MARK) {
      EndKata = true;
   }
   else {
      SalinKata();
      IgnoreBlank();
   }
}
void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   int i;
   i = 0;
   while ((CC != MARK) && (i < NMax)) {
      CKata.TabKata[i] = CC;
      i++;
      ADV();
   }
   CKata.Length = i;
}

void writefromMatriks (FILE* f, char strmatriks[10][20]){
/* Membaca file peta dalam bentuk matriks
    ********************
    *A-----W-----------*
    *------------------>
    *------------------*
    *---------PW-------*
    *------------------*
    *---W--------------*
    *--------------O---*
    *------------------* */
	for(int i=0; i<10; i++) {
		for(int j=0; j<20; j++){
		    fprintf(f,"%c", strmatriks[i][j]);
		}
		fprintf(f,";\n");
    }
}

boolean IsKataSama(Kata K1, Kata K2){
    boolean isEq = K1.Length == K2.Length;
    if (isEq) {
        int i;
        for (i = 0; i < K1.Length; i++) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                isEq = false;
                break;
            }
        }
    }

    return isEq;
}