#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void izbornikAdmin() {


}do {
	int flag = 0;
	int odabir;
	int id;
	int idUre?enje;
	bool ure?enjeUspješno;

	system("cls");
	printf("Unesite koju radnju želite izvršiti:\n");
	printf("\n 1) Dodavanje automobila:");
	printf("\n 2) Uklanjanje automobila");
	printf("\n 3) Ispis svih automobila");
	printf("\n 4) Uredjivanje automobila u katalogu");
	printf("\n 0) Izlaz iz programa");

	scanf("%d", &odabir);

	system("cls");

	switch (odabir) {		//upisujem opcije koje su navedene gore
	case 1:

	case 2:

	case 3:

	case 4:

	case 0:
		odabir = krajPrograma();		//program zavrsava
		break;

	}

} while (odabir != 0);
