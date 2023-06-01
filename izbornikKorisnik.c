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
	AUTO temp;
	auto = ucitavanjeAuta(auto);
	FILE* datoteka
		char* imeDat = "katalog.txt";

	do {

		system("cls");
		printf("Unesite koju radnju zelite izvrsiti:\n");
		printf("\n 1)Ispis automobila:");
		printf("\n 2)Ispis automobila sortiranih po cijeni - od manje prema vecoj\n");
		printf("\n 3)Ispis automobila sortiranih po cijeni - od vece prema manjoj\n");
		printf("\n 4)Ispis automobila sortiranih po godini proizvodnje - od starijeg prema novijem\n");
		printf("\n 5)Ispis automobila sortiranih po godini proizvodnje - od novijeg prema starijem\n");
		printf("\n 6)Unos minimalne snage motora");
		printf("\n 7)Pretraga auta po brendu\n");
		printf("\n 8)Pretraga auta po karoseriji\n");
		printf("\n 9)Pretraga auta po modelu\n");
		printf("\n 10) Kupnja automobila\n");
		printf("\n 0) Izlaz iz programa");

		scanf("%d", &odabir);

		system("cls");

		switch (odabir) {		//upisujem opcije koje cu navesti gore
		case 1:

			ispisAuta();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 2:

			for (i = 0; i < brojAuta - 1; i++) {
				for (j = 0; j < brojAuta - 1 - i; j++) {
					if ((auto + j + 1)->cijena < (auto + j)->cijena) {
						strcpy(temp.marka, (auto + j)->marka);
						strcpy(temp.karoserija, (auto + j)->karoserija);
						strcpy(temp.model, (auto + j)->model);
						temp.godinaProizvodnje = (auto + j)->godinaProizvodnje;
						temp.snaga = (auto + j)->snaga;
						temp.obujam = (auto + j)->obujam;
						temp.cijena = (auto + j)->cijena;
						strcpy(temp.boja, (auto + j)->boja);
						temp.id = (auto + j)->id;

						strcpy((auto+ j)->marka, (auto + j + 1)->marka);
						strcpy((auto + j)->karoserija, (auto + j + 1)->karoserija);
						strcpy((auto + j)->model, (auto + j + 1)->model);
						(auto + j)->godinaProizvodnje = (auto + j + 1)->godinaProizvodnje;
						(auto + j)->snaga = (auto + j + 1)->snaga;
						(auto + j)->obujam = (auto + j + 1)->obujam;
						(auto + j)->cijena = (auto + j + 1)->cijena;
						strcpy((auto + j)->boja, (auto + j + 1)->boja);
						(auto + j)->id = (auto + j + 1)->id;

						strcpy((auto + j + 1)->marka, temp.marka);
						strcpy((auto + j + 1)->karoserija, temp.karoserija);
						strcpy((auto + j + 1)->model, temp.model);
						(auto + j + 1)->godinaProizvodnje = temp.godinaProizvodnje;
						(auto + j + 1)->snaga = temp.snaga;
						(auto + j + 1)->obujam = temp.obujam;
						(auto + j + 1)->cijena = temp.cijena;
						strcpy((auto + j + 1)->boja, temp.boja);
						(auto + j + 1)->id = temp.id;
					}
				}
			}
			printf("Automobili od manje cijene prema vecoj:\n\n");
			for (i = 0; i < brojAuta; i++) {
				printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
				printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
				printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
				printf("\n\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 3:

			for (i = 0; i < brojAuta - 1; i++) {
				for (j = 0; j < brojAuta - 1 - i; j++) {
					if ((auto + j + 1)->cijena < (auto + j)->cijena) {
						strcpy(temp.marka, (auto + j)->marka);
						strcpy(temp.karoserija, (auto + j)->karoserija);
						strcpy(temp.model, (auto + j)->model);
						temp.godinaProizvodnje = (auto + j)->godinaProizvodnje;
						temp.snaga = (auto + j)->snaga;
						temp.obujam = (auto + j)->obujam;
						temp.cijena = (auto + j)->cijena;
						strcpy(temp.boja, (auto + j)->boja);
						temp.id = (auto + j)->id;

						strcpy((auto + j)->marka, (auto + j + 1)->marka);
						strcpy((auto + j)->karoserija, (auto + j + 1)->karoserija);
						strcpy((auto + j)->model, (auto + j + 1)->model);
						(auto + j)->godinaProizvodnje = (auto + j + 1)->godinaProizvodnje;
						(auto + j)->snaga = (auto + j + 1)->snaga;
						(auto + j)->obujam = (auto + j + 1)->obujam;
						(auto + j)->cijena = (auto + j + 1)->cijena;
						strcpy((auto + j)->boja, (auto + j + 1)->boja);
						(auto + j)->id = (auto + j + 1)->id;

						strcpy((auto + j + 1)->marka, temp.marka);
						strcpy((auto + j + 1)->karoserija, temp.karoserija);
						strcpy((auto + j + 1)->model, temp.model);
						(auto + j + 1)->godinaProizvodnje = temp.godinaProizvodnje;
						(auto + j + 1)->snaga = temp.snaga;
						(auto + j + 1)->obujam = temp.obujam;
						(auto + j + 1)->cijena = temp.cijena;
						strcpy((auto + j + 1)->boja, temp.boja);
						(auto + j + 1)->id = temp.id;
					}
				}
			}
			printf("Automobili od vece cijene prema manjoj:\n\n");
			for (i = brojaAuta; i > 0; i--) {
				printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
				printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
				printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
				printf("\n\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 4:

			for (i = 0; i < brojAuta - 1; i++) {
				for (j = 0; j < brojAuta - 1 - i; j++) {
					if ((auto + j + 1)->godinaProizvodnje < (auto + j)->godinaProizvodnje) {
						strcpy(temp.marka, (auto + j)->marka);
						strcpy(temp.karoserija, (auto + j)->karoserija);
						strcpy(temp.model, (auto + j)->model);
						temp.godinaProizvodnje = (auto + j)->godinaProizvodnje;
						temp.snaga = (auto + j)->snaga;
						temp.obujam = (auto + j)->obujam;
						temp.cijena = (auto + j)->cijena;
						strcpy(temp.boja, (auto + j)->boja);
						temp.id = (auto + j)->id;

						strcpy((auto + j)->marka, (auto + j + 1)->marka);
						strcpy((auto + j)->karoserija, (auto + j + 1)->karoserija);
						strcpy((auto + j)->model, (auto + j + 1)->model);
						(auto + j)->godinaProizvodnje = (auto + j + 1)->godinaProizvodnje;
						(auto + j)->snaga = (auto + j + 1)->snaga;
						(auto + j)->obujam = (auto + j + 1)->obujam;
						(auto + j)->cijena = (auto + j + 1)->cijena;
						strcpy((auto + j)->boja, (auto + j + 1)->boja);
						(auto + j)->id = (auto + j + 1)->id;

						strcpy((auto + j + 1)->marka, temp.marka);
						strcpy((auto + j + 1)->karoserija, temp.karoserija);
						strcpy((auto + j + 1)->model, temp.model);
						(auto + j + 1)->godinaProizvodnje = temp.godinaProizvodnje;
						(auto + j + 1)->snaga = temp.snaga;
						(auto + j + 1)->obujam = temp.obujam;
						(auto + j + 1)->cijena = temp.cijena;
						strcpy((auto + j + 1)->boja, temp.boja);
						(auto + j + 1)->id = temp.id;
					}
				}
			}
			printf("Automobili stariji  prema mladoj:\n\n");
			for (i = 0; i < brojAuta; i++) {
				printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
				printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
				printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
				printf("\n\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;


		case 5:


			for (i = 0; i < brojAuta - 1; i++) {
				for (j = 0; j < brojAuta - 1 - i; j++) {
					if ((auto + j + 1)->godinaProizvodnje < (auto + j)->godinaProizvodnje) {
						strcpy(temp.marka, (auto + j)->marka);
						strcpy(temp.karoserija, (auto + j)->karoserija);
						strcpy(temp.model, (auto + j)->model);
						temp.godinaProizvodnje = (auto + j)->godinaProizvodnje;
						temp.snaga = (auto + j)->snaga;
						temp.obujam = (auto + j)->obujam;
						temp.cijena = (auto + j)->cijena;
						strcpy(temp.boja, (auto + j)->boja);
						temp.id = (auto + j)->id;

						strcpy((auto + j)->marka, (auto + j + 1)->marka);
						strcpy((auto + j)->karoserija, (auto + j + 1)->karoserija);
						strcpy((auto + j)->model, (auto + j + 1)->model);
						(auto + j)->godinaProizvodnje = (auto + j + 1)->godinaProizvodnje;
						(auto + j)->snaga = (auto + j + 1)->snaga;
						(auto + j)->obujam = (auto + j + 1)->obujam;
						(auto + j)->cijena = (auto + j + 1)->cijena;
						strcpy((auto + j)->boja, (auto + j + 1)->boja);
						(auto + j)->id = (auto + j + 1)->id;

						strcpy((auto + j + 1)->marka, temp.marka);
						strcpy((auto + j + 1)->karoserija, temp.karoserija);
						strcpy((auto + j + 1)->model, temp.model);
						(auto + j + 1)->godinaProizvodnje = temp.godinaProizvodnje;
						(auto + j + 1)->snaga = temp.snaga;
						(auto + j + 1)->obujam = temp.obujam;
						(auto + j + 1)->cijena = temp.cijena;
						strcpy((auto + j + 1)->boja, temp.boja);
						(auto + j + 1)->id = temp.id;
					}
				}
			}
			printf("Automobili noviji prema starijima:\n\n");
			for (i = brojAuta; i > 0; i--) {
				printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
				printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
				printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
				printf("\n\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;


		case 6:
			printf("Unesite minimalnu snagu motora koju trazite.\n");
			scanf("%d", &temp.snaga);
			printf("\n");
			for (i = 0; i < brojAuta; i++) {
				if ((auto + i)->snaga > temp.snaga) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
					printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
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
				if (strcmp((temp.marka), (auto + i)->marka) == 0) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
					printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
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
				if (strcmp((temp.karoserija), (auto + i)->karoserija) == 0) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
					printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
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
				if (strcmp((temp.model), (auto + i)->model) == 0) {
					printf("Brend: %s\nKaroserija: %s\nModel: %s ", (auto + i)->marka, (auto + i)->karoserija, (auto + i)->model);
					printf("\nGodina proizvodnje: %d \nSnaga: %d \nObujam: %d", (auto + i)->godinaProizvodnje, (auto + i)->snaga, (auto + i)->obujam);
					printf("\nCijena: %d \nBoja: %s \nID: %d", (auto + i)->cijena, (auto + i)->boja, (auto + i)->id);
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
			auto = ucitavanjeAuta(auto);
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