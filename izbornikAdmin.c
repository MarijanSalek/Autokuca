#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void izbornikAdmin() {

	int flag = 0;
	int odabir;
	int id;
	int idUredenje;
	bool uredenjeUspjesno;

	while (adminPrijava(&admin) == false && flag < 4) {
		flag++;
		if (flag == 3) {
			printf("Neuspjesno logiranje, iskoristili ste sve pokusaje!");
			return;
		}
		system("cls");
		printf("Pogresno ste unjeli korisnicko ime ili lozinka. \n");
		printf("Pokusaj ponovno: \n");
	}
	system("cls");
	printf("Uspjesna prijava.\n");


}do {
	system("cls");
	printf("Unesite koju radnju želite izvrsiti:\n");
	printf("\n 1) Dodavanje automobila:");
	printf("\n 2) Uklanjanje automobila");
	printf("\n 3) Ispis automobila");
	printf("\n 4) Uredjivanje automobila u katalogu");
	printf("\n 0) Izlaz iz programa");

	scanf("%d", &odabir);

	system("cls");

	switch (odabir) {		//upisujem opcije koje su navedene gore

	case 1:
		system("cls");
		unosNovog();
		break;

	case 2:
		system("cls");
		printf("Unesite ID automobila kojeg zelite obrisati: \n");
		scanf(" %d", &id);
		int stanje = brisanjeAuta(id);
		if (stanje == 1) {
			printf("Uspjesno izbrisan trazeni proizvod\n");
		}
		if (stanje == 0) {
			printf("Neuspjesno obrisan proizvod");
		}
		printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
		_getch();
		break;

	case 3:
		system("cls");
		ispisAuta();
		printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
		_getch();
		break;

	case 4:
		system("cls");
		printf("Unesite ID automobila za uredjivanje: ");
		scanf(" %d", &idUredenje);

		uredenjeUspjesno = uredivanjeAuta(idUredenje);
		if (uredenjeUspjesno == true) {
			printf("Automobil (ID: %d) uspjesno uredjen", idUredenje);
		}
		else {
			printf("Ne postoji automobil sa trazenim ID-om");
		}

		_getch();
		break;

	case 0:

		odabir = krajPrograma();
		if (odabir == 0) {
			system("cls");
			printf("Kraj programa, stisnite bilo koju tipku za zavrsetak\n");
			_getch();
			exit(EXIT_SUCCESS);
		}
		else {
			printf("Pritisnite bilo koju tipku za nastavak programa\n");
		}
		break;
	}

} while (odabir != 0);