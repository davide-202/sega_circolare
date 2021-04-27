#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


#include "sega.h"
#include "svg.h"
 
using namespace std;


int main() {

    sega_circolare* arc=new sega_circolare;

    cout<<"inserisci il raggio che desideri \n";
    cin>>arc->raggio;  

    cout<<"inserisci l'altezza che desideri \n";
    cin>>arc->altezza;

    cout<<"inserisci la lunghezza che desideri \n";
    cin>>arc->lunghezza;   
   
    sega_init(arc->raggio,arc->altezza,arc->lunghezza);
    cout<<endl;
    sega_mod(arc->raggio,arc->altezza,arc->lunghezza);

    string s,files,filer;
    s=sega_to_svg(arc);  
    cout<<"in che file vuoi salvare la stringa?\n";
    cin>>files;
    sega_save(files,s);
    cout<<"da che file vuoi attingere i dati?\n";
    cin>>filer;
    sega_load(filer);
    
    delete arc;
    return 0;
}