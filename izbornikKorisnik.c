#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void izbornikKorisnik() {
	int odabir;
	int i, j;
	int flag = 0;
	int brojAuta = ucitavanjeBrojaAuta();
	AUTO* auto = NULL;
	auto = ucitavanjeAuta(auto);
	FILE* datoteka
		char* imeDat = "katalog.txt";

	do {

		system("cls");
		printf("Unesite koju radnju želite izvršiti:\n");
		printf("\n Ispis automobila:");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n 1) Kupnja automobila");
		printf("\n 0) Izlaz iz programa");

		scanf("%d", &odabir);

		system("cls");

		switch (odabir) {		//upisujem opcije koje cu navesti gore
		case 1:

		case 2:

		case 3:

		case 4:

		case 5:

		case 0:
			odabir = krajPrograma();		//program zavrsava
			break;

		}

	} while (odabir != 0);
}