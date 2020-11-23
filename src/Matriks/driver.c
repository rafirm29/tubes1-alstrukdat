#include "matriks.h"
#include <stdlib.h>
#include <stdio.h>
#include "../Mesin/mesinkar.h"
#include "../Mesin/mesinkata.h"

int main(){
	MATRIKS m, n;
	POINT P, P1, P2;

	BacaMATRIKS(&m, "../FileEksternal/peta1.txt");
	TulisMATRIKS(m);
	printf("\n");

	CopyMATRIKS(m,&n);

	printf("\nPosisi player di koordinat: ");
	P = PosisiPlayer(m);
	TulisPOINT(P);
	printf("\n");

	printf("\n");
	P1 = BangunanSekitarPlayer(m,P);
	printf("Bangunan di sekitar player: ");
	TulisPOINT(P1);
	printf("\n");

	printf("\n");
	Move(&m,'s', &n);
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'s', &n);
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'s', &n);
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");
	
	printf("\n");
	Move(&m,'d', &n);
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'d', &n);
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");
}