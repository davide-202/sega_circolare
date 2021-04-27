#ifndef SEGA_H
#define SEGA_H


int sega_init(double r, double h, double l);
/*
* questa funziona esegue un controllo sui dati
*/

void sega_mod(double r, double h, double l);
/*
* questa funzione permette di modificare i dati e
* include anche una verifica
*/

struct sega_circolare{
  double raggio;
  double altezza;
  double lunghezza;
};

#endif
