#ifndef HEADER_H
#define HEADEH_H
#include <>

typdef struct auto{
	char marka[20];
	char karoserija[20];
	char model[30];
	int godinaProizvodnje;
	int snaga;
	int obujam;
	int cijena;
	char boja[12];
	int id;

}AUTO;


typdef struct admin {
	char korisnickoIme[18];
	char lozinka[15];
	int id;

}ADMIN;


void izbornik();
int odabirKorisnika();
void izbornikAdmin();



#endif
