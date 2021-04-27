#ifndef SVG_H
#define SVG_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sega_to_svg(sega_circolare* sega);
/*
* questa funzione prende i dati del componente e ne crea
* una stringa che può essere visualizzata come svg
*/

void sega_save(string filename, string s);
/*
* questa funzione serve per salvare la stringa in un file
*/

string sega_load(string filename);
/*
* questa funzione legge la stringa da un file
*/

sega_circolare* sega_parse(string svg);
/*
* questa funzione deve leggere una stringa e costruire
* la struct originale
*/

#endif