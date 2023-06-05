#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <stdbool.h>
#include <string.h>

bool adminPrijava(ADMIN* adminPok) {
    ADMIN unos;
    printf("Unesite korisnicko ime:\n  ");
    scanf("%s", unos.korisnickoIme);
    printf("Unesite lozinku:\n  ");
    scanf("%s", unos.lozinka);
    if (strcmp(adminPok->korisnickoIme, unos.korisnickoIme) == 0 && strcmp(adminPok->lozinka, unos.lozinka) == 0)
        return true;
    else
        return false;
}

