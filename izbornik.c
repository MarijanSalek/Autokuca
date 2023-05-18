#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void izbornik() {
	int odabir;
	odabir = odabir_Korisnika ();

	switch (odabir) {
	case 1: 
		izbornik_Korisnika();
		break;
	case 2: 
		izbornik_Korisnika();
		break;
	case 3:
		izbornik_Korisnika();
		break;
	case 4:
		izbornik_Korisnika();
		break;
	default:
		printf("\n Kraj programa, stisnite bilo koju tipku za završetak.\n");
		scanf();
		break;
	}
	getch();

}