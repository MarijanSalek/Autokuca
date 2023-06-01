#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void izbornik() {
	int odabir;
	odabir = izborKorisnik();

	switch (odabir) {

	case 1:
		izbornikKorisnik();
		break;

	case 2:
		izbornikAdmin();
		break;

	default:
		printf("\nKraj programa, stisnite bilo koju tipku za kraj programa.\n");
		_getch();
		break;
	}
	getch();

}