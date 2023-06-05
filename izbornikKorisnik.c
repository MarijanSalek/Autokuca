#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"


void izbornikKorisnik() {
	int odabir;
	int i, j;
	int flag = 0;
	int brojAuta = ucitavanjeBrojaAuta();
	AUTO* automobil = NULL;
	AUTO temp;
	automobil = ucitavanjeAuta(automobil);
	FILE* datoteka;
	char* imeDat = "katalog.txt";

	do {

		system("cls");
		printf("Unesite koju radnju želite izvršiti:\n");
		printf("\n 1) Ispis automobila");
		printf("\n 2) Ispis automobila sortiranih po cijeni - od manje prema veæoj");
		printf("\n 3) Ispis automobila sortiranih po cijeni - od veæe prema manjoj");
		printf("\n 4) Ispis automobila sortiranih po godini proizvodnje - od starijeg prema novijem");
		printf("\n 5) Ispis automobila sortiranih po godini proizvodnje - od novijeg prema starijem");
		printf("\n 6) Unos minimalne snage motora");
		printf("\n 7) Pretraga auta po brendu");
		printf("\n 8) Pretraga auta po karoseriji");
		printf("\n 9) Pretraga auta po modelu");
		printf("\n 10) Kupnja automobila");
		printf("\n 0) Izlaz iz programa\n");
		printf("Odaberite broj ispred radnje koju zelite:  ");

		scanf("%d", &odabir);

		system("cls");

		switch (odabir) {
		case 1:
			ispisAuta();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 2:
			ispisAutaSortiranoPoCijeniRastuce();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 3:
			ispisAutaSortiranoPoCijeniOpadajuce();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 4:
			ispisAutaSortiranoPoGodiniRastuce();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 5:
			ispisAutaSortiranoPoGodiniOpadajuce();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 6:
			printf("Unesite minimalnu snagu motora koju trazite.\n");
			scanf("%d", &temp.snaga);
			printf("\n");
			for (i = 0; i < brojAuta; i++) {
				if ((automobil + i)->snaga >= temp.snaga) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
					printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0 && i == brojAuta - 1) {
				printf("Trenutno nema automobila zadane ili vece snage motora\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;


		case 7:
			printf("Unesite brend automobila kojeg trazite.\n");
			scanf(" %29s", &temp.marka);
			for (i = 0; i < brojAuta; i++) {
				if (strcmp((temp.marka), (automobil + i)->marka) == 0) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
					printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0) {
				printf("Trenutacno nema auta tog brenda\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;


		case 8:
			printf("Unesite karoseriju automobila kojeg trazite.\n");
			scanf(" %29s", &temp.karoserija);
			for (i = 0; i < brojAuta; i++) {
				if (strcmp((temp.karoserija), (automobil + i)->karoserija) == 0) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
					printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0) {
				printf("Trenutacno nema auta te karoserije\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 9:
			printf("Unesite modela automobila kojeg trazite.\n");
			scanf(" %29s", &temp.model);
			for (i = 0; i < brojAuta; i++) {
				if (strcmp((temp.model), (automobil + i)->model) == 0) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
					printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0) {
				printf("Trenutacno nema auta tog modela\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 10:
			kupnjaAuta();
			automobil = ucitavanjeAuta(automobil);
			brojAuta = ucitavanjeBrojaAuta();
			break;


		case 0:
			odabir = krajPrograma();
			if (odabir == 0) {
				system("cls");
				printf("Kraj programa, stisnite bilo koju tipku za zavrsetak\n");
				_getch();
				system("cls");
				exit(EXIT_SUCCESS);
			}
			else {
				printf("Pritisnite bilo koju tipku za nastavak programa\n");
			}
			break;
		}

	} while (odabir != 0);
}