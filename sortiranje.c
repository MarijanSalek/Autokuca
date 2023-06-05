#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int usporediPoCijeniRastuce(const void* a, const void* b) {
	const AUTO* auto1 = (const AUTO*)a;
	const AUTO* auto2 = (const AUTO*)b;

	if (auto1->cijena < auto2->cijena) {
		return -1;  // auto1 je manji od auto2
	}
	else if (auto1->cijena > auto2->cijena) {
		return 1;  // auto1 je veæi od auto2
	}
	else {
		return 0;  // auto1 je jednak auto2
	}
}

void ispisAutaSortiranoPoCijeniRastuce() {
	AUTO* automobil = NULL;
	int brojAuta = ucitavanjeBrojaAuta();
	automobil = ucitavanjeAuta(automobil);

	if (brojAuta == 0) {
		printf("Trenutno nema auta za ispis.\n");
	}
	else {
		// Sortiranje automobila po cijeni od manje prema veæoj
		qsort(automobil, brojAuta, sizeof(AUTO), usporediPoCijeniRastuce);

		printf("Automobili sortirani po cijeni (od manje prema veæoj):\n");
		for (int i = 0; i < brojAuta; i++) {
			printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
			printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
			printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
			printf("\n\n");
		}
	}
}

int usporediPoCijeniOpadajuce(const void* a, const void* b) {
	const AUTO* auto1 = (const AUTO*)a;
	const AUTO* auto2 = (const AUTO*)b;

	if (auto1->cijena > auto2->cijena) {
		return -1;  // auto1 je veæi od auto2
	}
	else if (auto1->cijena < auto2->cijena) {
		return 1;  // auto1 je manji od auto2
	}
	else {
		return 0;  // auto1 je jednak auto2
	}
}

void ispisAutaSortiranoPoCijeniOpadajuce() {
	AUTO* automobil = NULL;
	int brojAuta = ucitavanjeBrojaAuta();
	automobil = ucitavanjeAuta(automobil);

	if (brojAuta == 0) {
		printf("Trenutno nema auta za ispis.\n");
	}
	else {
		// Sortiranje automobila po cijeni od veæe prema manjoj
		qsort(automobil, brojAuta, sizeof(AUTO), usporediPoCijeniOpadajuce);

		printf("Automobili sortirani po cijeni (od veæe prema manjoj):\n");
		for (int i = 0; i < brojAuta; i++) {
			printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
			printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
			printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
			printf("\n\n");
		}
	}
}

int usporediPoGodiniRastuce(const void* a, const void* b) {
	const AUTO* auto1 = (const AUTO*)a;
	const AUTO* auto2 = (const AUTO*)b;

	if (auto1->godinaProizvodnje < auto2->godinaProizvodnje) {
		return -1;  // auto1 je stariji od auto2
	}
	else if (auto1->godinaProizvodnje > auto2->godinaProizvodnje) {
		return 1;  // auto1 je noviji od auto2
	}
	else {
		return 0;  // auto1 je jednak auto2
	}
}

void ispisAutaSortiranoPoGodiniRastuce() {
	AUTO* automobil = NULL;
	int brojAuta = ucitavanjeBrojaAuta();
	automobil = ucitavanjeAuta(automobil);

	if (brojAuta == 0) {
		printf("Trenutno nema auta za ispis.\n");
	}
	else {
		// Sortiranje automobila po godini proizvodnje od manje prema veæoj
		qsort(automobil, brojAuta, sizeof(AUTO), usporediPoGodiniRastuce);

		printf("Automobili sortirani po godini proizvodnje (od starijeg prema novijem):\n");
		for (int i = 0; i < brojAuta; i++) {
			printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
			printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
			printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
			printf("\n\n");
		}
	}
}

int usporediPoGodiniOpadajuce(const void* a, const void* b) {
	const AUTO* auto1 = (const AUTO*)a;
	const AUTO* auto2 = (const AUTO*)b;

	if (auto1->godinaProizvodnje < auto2->godinaProizvodnje) {
		return 1;  // auto1 je stariji od auto2
	}
	else if (auto1->godinaProizvodnje > auto2->godinaProizvodnje) {
		return -1;  // auto1 je noviji od auto2
	}
	else {
		return 0;  // auto1 je jednak auto2
	}
}

void ispisAutaSortiranoPoGodiniOpadajuce() {
	AUTO* automobil = NULL;
	int brojAuta = ucitavanjeBrojaAuta();
	automobil = ucitavanjeAuta(automobil);

	if (brojAuta == 0) {
		printf("Trenutno nema auta za ispis.\n");
	}
	else {
		// Sortiranje automobila po godini proizvodnje od veæe prema manjoj
		qsort(automobil, brojAuta, sizeof(AUTO), usporediPoGodiniOpadajuce);

		printf("Automobili sortirani po godini proizvodnje (od novijeg prema starijem):\n");
		for (int i = 0; i < brojAuta; i++) {
			printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
			printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
			printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
			printf("\n\n");
		}
	}
}