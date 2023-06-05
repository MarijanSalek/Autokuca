#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void kreiranjeDatoteke() {
	FILE* datAuti = NULL;
	char* imeDat = "automobili.bin";
	datAuti = fopen(imeDat, "rb");
	if (datAuti == NULL) {
		datAuti = fopen(imeDat, "wb");
		if (datAuti == NULL) {
			printf("Nije moguce kreirati datoteku automobili.bin\n ");
			printf("\nKraj programa\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("Uspjesno ste kreirali datoteku automobili.bin\n");
			fclose(datAuti);
		}
	}
	else {
		fclose(datAuti);
	}
}

AUTO* ucitavanjeAuta(AUTO* automobil) {
	FILE* datoteka = NULL;
	char* imeDat = "automobili.bin";
	int brojProizvoda = ucitavanjeBrojaAuta();
	automobil = (AUTO*)calloc(brojProizvoda, sizeof(AUTO));
	if (automobil != NULL) {
		datoteka = fopen(imeDat, "rb");
		if (datoteka == NULL) {
			printf("Neuspjesno otvaranje datoteke za citanje\n");
		}
		else {
			rewind(datoteka);
			fseek(datoteka, 4, SEEK_SET);
			fread(automobil, sizeof(AUTO), brojProizvoda, datoteka);
			fclose(datoteka);
		}
	}
	return automobil;
}


int ucitavanjeBrojaAuta() {
	int brojAuta = 0;
	FILE* datoteka = NULL;
	char* imeDat = "automobili.bin";
	datoteka = fopen(imeDat, "rb");
	if (datoteka != NULL) {
		rewind(datoteka);
		fread(&brojAuta, sizeof(int), 1, datoteka);
		fclose(datoteka);
	}
	else {
		printf("Nije moguce saznati koliki je broj auta u datoteci\n");
		printf("\nKraj programa\n");
		exit(EXIT_FAILURE);
	}
	return brojAuta;
}

void unosNovog() {
	AUTO noviAuto = { 0 };
	AUTO* sviAuti = NULL;
	FILE* datoteka = NULL;
	int flag = 1;
	int i = 0;
	char* imeDat = "automobili.bin";
	int brAuta = ucitavanjeBrojaAuta();
	if (brAuta == 0) {
		datoteka = fopen(imeDat, "rb+");
		if (datoteka != NULL) {
			if (datoteka == NULL) {
				printf("Nije moguce kreirati datoteku automobili.bin\n ");
				printf("\nKraj programa\n");
				exit(EXIT_FAILURE);
			}
			else {
				printf("Unesite ime brenda automobila\n");
				getchar();
				scanf("%20[^\n]", &noviAuto.marka);
				
				printf("Unesite karoseriju automobila\n");
				getchar();
				scanf("%12[^\n]", &noviAuto.karoserija);
				
				printf("Unesite model automobila\n");
				getchar();
				scanf("%12[^\n]", &noviAuto.model);

				printf("Unesite godinu proizvodnje\n");
				scanf(" %d", &noviAuto.godinaProizvodnje);

				printf("Unesite snagu motora automobila (KW)\n");
				scanf(" %d", &noviAuto.snaga);

				printf("Unesite obujam motora automobila (cm3)\n");
				scanf(" %d", &noviAuto.obujam);

				printf("Unesite cijenu auta (EUR)\n");
				scanf(" %d", &noviAuto.cijena);

				printf("Unesite boju automobila\n");
				getchar();
				scanf("%12[^\n]", &noviAuto.boja);

				printf("Unesite nepostojeci ID automobila:\n");
				scanf(" %d", &noviAuto.id);

				brAuta += 1;
				fwrite(&brAuta, sizeof(int), 1, datoteka);
				rewind(datoteka);
				fseek(datoteka, 0, SEEK_END);
				fwrite(&noviAuto, sizeof(AUTO), 1, datoteka);
				fclose(datoteka);
			}
		}
	}
	else {
		sviAuti = ucitavanjeAuta(sviAuti);
		if (sviAuti == NULL) {
			printf("Nije moguce zauzeti memoriju\n ");
			printf("\nKraj programa\n");
			exit(EXIT_FAILURE);
		}
		else {
			datoteka = fopen(imeDat, "rb+");
			if (datoteka == NULL) {
				printf("Nije moguce otvoriti datoteku auti.bin\n ");
				printf("\nKraj programa\n");
				exit(EXIT_FAILURE);
			}
			else {
				printf("Unesite ime brenda automobila\n");
				getchar();
				scanf("%20[^\n]", &noviAuto.marka);

				printf("Unesite karoseriju automobila\n");
				getchar();
				scanf("%12[^\n]", &noviAuto.karoserija);

				printf("Unesite model automobila\n");
				getchar();
				scanf("%12[^\n]", &noviAuto.model);

				printf("Unesite godinu proizvodnje\n");
				scanf(" %d", &noviAuto.godinaProizvodnje);

				printf("Unesite snagu motora automobila (KW)\n");
				scanf(" %d", &noviAuto.snaga);

				printf("Unesite obujam motora automobila (cm3)\n");
				scanf(" %d", &noviAuto.obujam);

				printf("Unesite cijenu auta (EUR)\n");
				scanf(" %d", &noviAuto.cijena);

				printf("Unesite boju automobila\n");
				getchar();
				scanf("%12[^\n]", &noviAuto.boja);

				
				do {
					flag = 1;
					printf("Unesite ID koji je razlicit od ostalih:\n");
					scanf(" %d", &noviAuto.id);
					for (i = 0; i < brAuta; i++) {
						if (noviAuto.id == sviAuti[i].id) {
							flag = 0;
							break;
						}
					}
					i = 0;
				} while (flag == 0);
			}
		}
		brAuta += 1;
		fwrite(&brAuta, sizeof(int), 1, datoteka);
		rewind(datoteka);
		fseek(datoteka, 0, SEEK_END);
		fwrite(&noviAuto, sizeof(AUTO), 1, datoteka);
		fclose(datoteka);
	}
	free(sviAuti);
	printf("\nUspjesno unesen automobil, stisnite bilo koju tipku za povratak u izbornik\n");
	_getch();
	system("cls");
}

void ispisAuta() {
	AUTO* automobil = NULL;
	int brojAuta = ucitavanjeBrojaAuta();
	automobil = ucitavanjeAuta(automobil);

	if (brojAuta == 0) {
		printf("Trenutno nema auta za ispis.\n");
	}
	else {
		for (int i = 0; i < brojAuta; i++) {
			printf("Brend: %s\nKaroserija: %s\nModel: %s ", (automobil + i)->marka, (automobil + i)->karoserija, (automobil + i)->model);
			printf("\nGodina proizvodnje: %d \nSnaga: %d kW\nObujam: %d cm3", (automobil + i)->godinaProizvodnje, (automobil + i)->snaga, (automobil + i)->obujam);
			printf("\nCijena: %d EUR\nBoja: %s \nID: %d", (automobil + i)->cijena, (automobil + i)->boja, (automobil + i)->id);
			printf("\n\n");
		}
	}
}

bool uredivanjeAuta(int tempId) {
    FILE* fajl = NULL;

    AUTO* sviAutomobili = NULL;
    AUTO* tempAutomobili = NULL;
    sviAutomobili = ucitavanjeAuta(sviAutomobili);

    if (sviAutomobili == NULL) {
        return false;
    }
    else {
        AUTO* tempAuto = NULL;
        int brElem = ucitavanjeBrojaAuta();

        for (int i = 0; i < brElem; i++) {
            int tmpId = sviAutomobili[i].id;
            if (tempId == tmpId) {
                tempAuto = &sviAutomobili[i];
                printf("Pronadjen automobil sa ID-om: %d\n", tempId);
                printf("Brend i model pronadjenog automobila: %s %s\n", tempAuto->marka, tempAuto->model);
                break;
            }
        }

        if (tempAuto != NULL) {
            printf("\nPrethodna godina proizvodnje: %d", tempAuto->godinaProizvodnje);
            printf("\nUnesite novu godinu proizvodnje: ");
            scanf("%d", &tempAuto->godinaProizvodnje);
            getchar();
            printf("Nova godina proizvodnje je: %d\n", tempAuto->godinaProizvodnje);

            printf("\nPrethodna snaga motora: %d", tempAuto->snaga);
            printf("\nUnesite novu snagu motora: ");
            scanf("%d", &tempAuto->snaga);
            getchar();
            printf("Nova snaga motora je: %d\n", tempAuto->snaga);

            printf("\nPrethodni obujam motora: %d", tempAuto->obujam);
            printf("\nUnesite novi obujam motora: ");
            scanf("%d", &tempAuto->obujam);
            getchar();
            printf("Novi obujam motora je: %d\n", tempAuto->obujam);

            printf("\nPrethodna cijena automobila: %d", tempAuto->cijena);
            printf("\nUnesite novu cijenu automobila: ");
            scanf("%d", &tempAuto->cijena);
            getchar();
            printf("Nova cijena automobila je: %d\n", tempAuto->cijena);

            printf("\nPrethodna boja automobila: %s", tempAuto->boja);
            printf("\nUnesite novu boju automobila: ");
            scanf(" %[^\n]%*c", tempAuto->boja);
            printf("Nova boja automobila je: %s\n", tempAuto->boja);

            fajl = fopen("automobil.bin", "r+b");

            if (fajl != NULL) {
                tempAutomobili = (AUTO*)calloc(brElem, sizeof(AUTO));

                if (tempAutomobili != NULL) {
                    for (int i = 0; i < brElem; i++) {
                        strcpy(tempAutomobili[i].marka, sviAutomobili[i].marka);
                        strcpy(tempAutomobili[i].karoserija, sviAutomobili[i].karoserija);
                        strcpy(tempAutomobili[i].model, sviAutomobili[i].model);
                        tempAutomobili[i].godinaProizvodnje = sviAutomobili[i].godinaProizvodnje;
                        tempAutomobili[i].snaga = sviAutomobili[i].snaga;
                        tempAutomobili[i].obujam = sviAutomobili[i].obujam;
                        tempAutomobili[i].cijena = sviAutomobili[i].cijena;
                        strcpy(tempAutomobili[i].boja, sviAutomobili[i].boja);
                        tempAutomobili[i].id = sviAutomobili[i].id;
                    }
                }

                fwrite(&brElem, sizeof(int), 1, fajl);
                fseek(fajl, sizeof(int), SEEK_SET);
                fwrite(tempAutomobili, sizeof(AUTO), brElem, fajl);
                fclose(fajl);

                free(sviAutomobili);
                free(tempAutomobili);
            }
        }
        else {
            return false;
        }
    }
    return true;
}



int brisanjeAuta(int id) {
	AUTO* automobil = NULL;
	int brojAuta = ucitavanjeBrojaAuta();
	int i = 0;
	int j = 0;
	int flag = 0;
	AUTO brisanje = { 0 };
	AUTO temp;
	FILE* datoteka = NULL;
	char* datIme = "automobili.bin";
	AUTO* Pomoc;

	brisanje.id = id;

	if (brojAuta == 0) {
		printf("Ne postoji niti jedan automobil u datoteci, ova funkcija se ne moze izvrsiti.\n");
		return 0;
	}
	else {
		automobil = ucitavanjeAuta(automobil);
		if (automobil == NULL) {
			printf("Nije moguce procitati proizvode iz datoteke.\n");
			_getch();
			exit(EXIT_FAILURE);
		}
		else {
			if (brisanje.id == (automobil + i)->id) {
				for (i = 0; i < brojAuta; i++) {
					if (brisanje.id == (automobil + i)->id) {
						flag = 1;
						for (j = i; j < brojAuta; j++) {
							if (j + 1 == brojAuta) {
								break;
							}

							strcpy(temp.marka, (automobil + j)->marka);
							strcpy(temp.karoserija, (automobil + j)->karoserija);
							strcpy(temp.model, (automobil + j)->model);
							temp.godinaProizvodnje = (automobil + j)->godinaProizvodnje;
							temp.snaga = (automobil + j)->snaga;
							temp.obujam = (automobil + j)->obujam;
							temp.cijena = (automobil + j)->cijena;
							strcpy(temp.boja, (automobil + j)->boja);
							temp.id = (automobil + j)->id;

							strcpy((automobil + j)->marka, (automobil + j + 1)->marka);
							strcpy((automobil + j)->karoserija, (automobil + j + 1)->karoserija);
							strcpy((automobil + j)->model, (automobil + j + 1)->model);
							(automobil + j)->godinaProizvodnje = (automobil + j + 1)->godinaProizvodnje;
							(automobil + j)->snaga = (automobil + j + 1)->snaga;
							(automobil + j)->obujam = (automobil + j + 1)->obujam;
							(automobil + j)->cijena = (automobil + j + 1)->cijena;
							strcpy((automobil + j)->boja, (automobil + j + 1)->boja);
							(automobil + j)->id = (automobil + j + 1)->id;

							strcpy((automobil + j + 1)->marka, temp.marka);
							strcpy((automobil + j + 1)->karoserija, temp.karoserija);
							strcpy((automobil + j + 1)->karoserija, temp.karoserija);
							(automobil + j + 1)->godinaProizvodnje = temp.godinaProizvodnje;
							(automobil + j + 1)->snaga = temp.snaga;
							(automobil + j + 1)->obujam = temp.obujam;
							(automobil + j + 1)->cijena = temp.cijena;
							strcpy((automobil + j + 1)->boja, temp.boja);
							(automobil + j + 1)->id = temp.id;

						}
					}
				}
				Pomoc = (AUTO*)calloc(brojAuta - 1, sizeof(AUTO));
				if (Pomoc != NULL) {
					for (i = 0; i < brojAuta - 1; i++) {
						strcpy((Pomoc + i)->marka, (automobil + i)->marka);
						strcpy((Pomoc + i)->karoserija, (automobil + i)->karoserija);
						strcpy((Pomoc + i)->model, (automobil + i)->model);
						(Pomoc + i)->godinaProizvodnje = (automobil + i)->godinaProizvodnje;
						(Pomoc + i)->snaga = (automobil + i)->snaga;
						(Pomoc + i)->obujam = (automobil + i)->obujam;
						strcpy((Pomoc + i)->boja, (automobil + i)->boja);
						(Pomoc + i)->cijena = (automobil + i)->cijena;
						(Pomoc + i)->id = (automobil + i)->id;
					}
				}
				else {
					flag = 0;
					exit(EXIT_FAILURE);
				}
				if (flag == 1) {
					datoteka = fopen(datIme, "w");
					if (datoteka != NULL) {
						brojAuta = brojAuta - 1;
						fwrite(&brojAuta, sizeof(int), 1, datoteka);
						rewind(datoteka);
						fseek(datoteka, 4, SEEK_SET);
						fwrite(Pomoc, sizeof(AUTO), brojAuta, datoteka);
						fclose(datoteka);
					}
				}
				free(Pomoc);
				free(automobil);
				getchar
				();
			}
		}
		return flag;
	}
}