#ifndef JAM_H
#define JAM_H

#include "../boolean.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M);
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM);
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J);
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */

void TulisJAM (JAM J);
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JAMToMenit (JAM J);
// konversi dari jam ke menit

JAM MenitToJAM (int N);
// konversi dari menit ke jam

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2);
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2);
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2);
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2);
/* Mengirimkan true jika J1>J2, false jika tidak */

/* *** Operator aritmatika JAM *** */
JAM NextMenit (JAM J);
/* Mengirim 1 menit setelah J dalam bentuk JAM */
JAM NextNMenit (JAM J, int N);
/* Mengirim N meint setelah J dalam bentuk JAM */
JAM PrevMenit (JAM J);
/* Mengirim 1 meint sebelum J dalam bentuk JAM */
JAM PrevNMenit (JAM J, int N);
/* Mengirim N menit sebelum J dalam bentuk JAM */

/* *** Kelompok Operator Aritmetika *** */
int Durasi (JAM JAw, JAM JAkh);
/* Mengirim JAkh-JAw dlm menit, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */

#endif