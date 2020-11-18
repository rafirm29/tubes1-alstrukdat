#include "matriks.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	MATRIKS m;
	POINT P, P1, P2;

	BacaMATRIKS(&m, "../FileEksternal/peta1.txt");
	TulisMATRIKS(m);
	printf("\n");

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
	Move(&m,'d');
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'a');
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'s');
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'a');
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'d');
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'s');
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'s');
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'s');
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'s');
	TulisMATRIKS(m);
	printf("\n");
	printf("\n");

	printf("\n");
	Move(&m,'s');
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");
	
	printf("\n");
	Move(&m,'s');
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'w');
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");

	printf("\n");
	Move(&m,'w');
	printf("\n");
	TulisMATRIKS(m);
	printf("\n");
}