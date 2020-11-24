/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = stdin;
       EOP = false;
	ADV();
}

void STARTFILE(char * namafile) {
       pita = fopen(namafile,"r");
       EOP = false;
	ADVFILE();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
       if (retval == '\n') {
              EOP = true;
              fclose(pita);
       }
}

void ADVFILE() {
       retval = fscanf(pita,"%c",&CC);
       if (retval == EOF || CC == '.') {
              EOP = true;
              fclose(pita);
       }
}