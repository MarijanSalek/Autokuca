#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>

typedef struct automobil{
    char marka[20];
    char karoserija[20];
    char model[30];
    int godinaProizvodnje;
    int snaga;
    int obujam;
    int cijena;
    char boja[12];
    int id;
} AUTO;

typedef struct admin {
    char korisnickoIme[18];
    char lozinka[15];
    int id;
} ADMIN;

void izbornik();
void izbornikAdmin();
void kreiranjeDatoteke();
void ispisAuta();
void unosNovog();
void izbornikKorisnik();
void kupnjaAuta();
void ispisAutaSortiranoPoGodiniRastuce();
void ispisAutaSortiranoPoGodiniPadajuce();
void ispisAutaSortiranoPoCijeniRastuce();
void ispisAutaSortiranoPoCijeniPadajuce();
int izborKorisnik();
int ucitavanjeBrojaAuta();
int krajPrograma(void);
int brisanjeAuta(int id);
bool adminPrijava(ADMIN* adminPok);
AUTO* ucitavanjeAuta(AUTO* automobil);

#endif  // HEADER_H
