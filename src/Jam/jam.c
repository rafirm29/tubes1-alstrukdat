// implementasi jam.h
// file jam.c

#include <stdio.h>
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
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
   JAM J;
   (J).HH = HH;
   (J).MM = MM;
   return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3
   Jam tidak valid
   1 3
   --> akan terbentuk JAM <1,3> */
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
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
   printf("%d:%d", (J).HH, (J).MM);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToMenit (JAM J){
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
   return ((J).HH * 60 + (J).MM);
}

JAM MenitToJAM (long N){
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
   int h, int m;
   h = N % 60;
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
/* Mengirim 1 detik setelah J dalam bentuk JAM */
   long N = JAMToMenit(J) + 1;
   JAM J1 = MenitToJAM(N);
   return (J1);
}

JAM NextNMenit (JAM J, int N){
/* Mengirim N detik setelah J dalam bentuk JAM */
   long N1 = JAMToMenit(J) + N;
   JAM J1 = MenitToJAM(N1);
   return (J1);
}

JAM PrevMenit (JAM J){
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
   long N = JAMToMenit(J) - 1;
   JAM J1 = MenitToJAM(N);
   return (J1);
}

JAM PrevNMenit (JAM J, int N){
/* Mengirim N detik sebelum J dalam bentuk JAM */
   long N1 = JAMToMenit(J) - N;
   JAM J1 = MenitToJAM(N1);
   return (J1);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
   long N;
   long menitakh = JAMToMenit(JAkh);
   long menitaw = JAMToMenit(JAw);
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