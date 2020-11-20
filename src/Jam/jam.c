// implementasi jam.h
// file jam.c

#include <stdio.h>
#include <math.h>
#include "jam.h"

/* DEFINISI PRIMITIF*/
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M){
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
   return ((H >= 0 && H < 24) && (M >= 0 && M < 60));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM){
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
   JAM J;
   (J).HH = HH;
   (J).MM = MM;
   return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
   // membaca jam dengan format "jam menit"
   int h, m;
   do {
        scanf("%d %d",&h,&m);
        if (!IsJAMValid(h,m)) {
            printf("Jam tidak valid\n");
        }    
    } while (!IsJAMValid(h,m));
    *J = MakeJAM(h,m);
}

void TulisJAM (JAM J){
   // menulis jam dalam format JJ:MM
   printf("%02d:%02d\n", (J).HH, (J).MM);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JAMToMenit (JAM J){
   // konversi jam ke menit
   return ((J).HH * 60 + (J).MM);
}

JAM MenitToJAM (int N){
/* Mengirim  konversi menit ke JAM */
   int h, m;
   h = floor(N / 60);
   m = N - (h * 60);
   return MakeJAM(h,m);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
/* Mengirimkan true jika J1=J2, false jika tidak */
   return (JAMToMenit(J1) == JAMToMenit(J2));
}

boolean JNEQ (JAM J1, JAM J2){
/* Mengirimkan true jika J1 tidak sama dengan J2 */
   return(JAMToMenit(J1) != JAMToMenit(J2));
}

boolean JLT (JAM J1, JAM J2){
/* Mengirimkan true jika J1<J2, false jika tidak */
   return(JAMToMenit(J1) < JAMToMenit(J2));
}

boolean JGT (JAM J1, JAM J2){
/* Mengirimkan true jika J1>J2, false jika tidak */
   return(JAMToMenit(J1) > JAMToMenit(J2));
}

/* *** Operator aritmatika JAM *** */
JAM NextMenit (JAM J){
/* Mengirim 1 menit setelah J dalam bentuk JAM */
   int N = JAMToMenit(J) + 1;
   JAM J1 = MenitToJAM(N);
   return (J1);
}

JAM NextNMenit (JAM J, int N){
/* Mengirim N menit setelah J dalam bentuk JAM */
   int N1 = JAMToMenit(J) + N;
   JAM J1 = MenitToJAM(N1);
   return (J1);
}

JAM PrevMenit (JAM J){
/* Mengirim 1 menit sebelum J dalam bentuk JAM */
   int N = JAMToMenit(J) - 1;
   JAM J1 = MenitToJAM(N);
   return (J1);
}

JAM PrevNMenit (JAM J, int N){
/* Mengirim N menit sebelum J dalam bentuk JAM */
   int N1 = JAMToMenit(J) - N;
   JAM J1 = MenitToJAM(N1);
   return (J1);
}

/* *** Kelompok Operator Aritmetika *** */
int Durasi (JAM JAw, JAM JAkh){
   // durasi dalam menit
   int N;
   int menitakh = JAMToMenit(JAkh);
   int menitaw = JAMToMenit(JAw);
   if (menitaw > menitakh)
   {
      N = menitakh + (24*60) - menitaw;
   }
   else
   {
      N = menitakh - menitaw;
   }
   return N;
}