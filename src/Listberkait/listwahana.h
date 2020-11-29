/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressWahana dengan pointer */
/* infotype adalah integer */

#ifndef listwahana_H
#define listwahana_H

#include "../boolean.h"
#include "../Wahana/wahana.h"

#define NilWahana NULL

typedef struct tElmtlist *addressWahana;
typedef struct {
	addressWahana First;
} List;
typedef struct tElmtlist {
	Wahana info;
	addressWahana next;
	List upgradeList;
} ElmtList;


/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressWahana P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressWahananya Last, maka Next(Last)=Nil */

#define InfoLWahana(P) (P)->info
#define NextLWahana(P) (P)->next
#define FirstLWahana(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyWahana (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyWahana (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressWahana AlokasiWahana (Wahana X);
/* Mengirimkan addressWahana hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressWahana tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiWahana (addressWahana *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressWahana P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressWahana SearchWahana (List L, Wahana X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addressWahana elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstWahana (List *L, Wahana X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastWahana (List *L, Wahana X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstWahana (List *L, Wahana *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastWahana (List *L, Wahana *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstWahana (List *L, addressWahana P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressWahana P sebagai elemen pertama */
void InsertAfterWahana (List *L, addressWahana P, addressWahana Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastWahana (List *L, addressWahana P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstWahana (List *L, addressWahana *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPWahana (List *L, Wahana X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressWahana P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastWahana (List *L, addressWahana *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterWahana (List *L, addressWahana *Pdel, addressWahana Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoWahana (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtWahana (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1Wahana (List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif