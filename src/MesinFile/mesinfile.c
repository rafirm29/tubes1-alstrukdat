#include "mesinfile.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pitafile;
static int retval;

void STARTFILE(char *namafile) {
/* Mesin siap dioperasikan. Pita dari namafile disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pitafile = fopen(namafile,"r");
	ADVFILE();
}

void ADVFILE() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pitafile,"%c",&CC);
       EOP = (CC == MARK);
       if (EOP) {
              fclose(pitafile);
       }
}