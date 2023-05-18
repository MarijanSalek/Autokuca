#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void izbornik() {
	int odabir;
	odabir = odabir_Korisnika ();

	switch (odabir) {
	case 1:
		izbornikAdmin ();            
		break;
	case 2: 
		izbornikKorisnik();
		break;
	
	default:
		printf("\n Kraj programa, stisnite bilo koju tipku za završetak.\n");
		scanf();
		break;
	}
	getch();

}