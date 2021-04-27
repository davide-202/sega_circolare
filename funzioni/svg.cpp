#include "sega.h"
#include "svg.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

string sega_to_svg(sega_circolare* sega){
    string s;
    string header;
    /*
    *per far bene così da non scrivere l'header quando saranno
    *uniti più device, si può mettere un controllo.
    *per ora essendo 1 device singolo faccio senza.
    */
    header="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?> \n <svg xmlns=\"http://www.w3.org/2000/svg\" width= \"500\" height=\"500\" style=\"background-color:white\" >\n";
    s=header+ "<circle cx=\""+to_string((sega->lunghezza)/2+5) + "\" cy=\""+to_string(sega->raggio+10)+"\" r=\""+to_string(sega->raggio)+"\" stroke=\"black\" stroke-width=\"4\" fill=\"white\" />\n";
    s=s+" <rect x=\""+to_string(5)+"\" y=\""+to_string(sega->raggio+10)+"\" width=\""+to_string(sega->lunghezza)+"\" height=\""+to_string(sega->altezza)+"\" style=\"fill:white;stroke-width:4;stroke:rgb(0,0,0)\" />\n";
    s=s+"  <line x1=\""+to_string((sega->lunghezza)/2+5)+"\" y1=\""+to_string(sega->raggio+10)+"\" x2=\""+to_string((sega->lunghezza)/2+5-(sega->raggio/sqrt(2)))+"\" y2=\""+to_string(sega->raggio+10-(sega->raggio/sqrt(2)))+"\" style=\"stroke:grey;stroke-width:4\" />\n";
    s=s+"   <line x1=\""+to_string((sega->lunghezza)/2+5)+"\" y1=\""+to_string(sega->raggio+10)+"\" x2=\""+to_string((sega->lunghezza)/2+5)+"\" y2=\""+to_string(10)+"\" style=\"stroke:grey;stroke-width:4\" />\n";
    s=s+"    <line x1=\""+to_string((sega->lunghezza)/2+5)+"\" y1=\""+to_string(sega->raggio+10)+"\" x2=\""+to_string((sega->lunghezza)/2+5+(sega->raggio/sqrt(2)))+"\" y2=\""+to_string(sega->raggio+10-(sega->raggio/sqrt(2)))+"\" style=\"stroke:grey;stroke-width:4\" />\n";
    s=s+"   <line x1=\""+to_string(3)+"\" y1=\""+to_string(sega->altezza+sega->raggio+20)+"\" x2=\""+to_string(sega->lunghezza+7)+"\" y2=\""+to_string(sega->altezza+sega->raggio+20)+"\" style=\"stroke:black;stroke-width:2\" />\n";
    s=s+"  <line x1=\""+to_string(sega->lunghezza+15)+"\" y1=\""+to_string(sega->altezza+sega->raggio+12)+"\" x2=\""+to_string(sega->lunghezza+15)+"\" y2=\""+to_string(8)+"\" style=\"stroke:black;stroke-width:2\" />\n";
    s=s+" <line x1=\""+to_string(sega->lunghezza+10)+"\" y1=\""+to_string(sega->raggio+12)+"\" x2=\""+to_string(sega->lunghezza+20)+"\" y2=\""+to_string(sega->raggio+12)+"\" style=\"stroke:black;stroke-width:2\" />\n";
    s=s+"<text x=\""+to_string(sega->lunghezza+20)+"\" y=\""+to_string((sega->raggio+20)/2)+"\" fill=\"black\" >"+to_string(sega->raggio)+"(cm)</text>\n";
    s=s+"<text x=\""+to_string((sega->lunghezza)/4)+"\" y=\""+to_string(sega->raggio+33+sega->altezza)+"\" fill=\"black\" >"+to_string(sega->lunghezza)+"(cm)</text>\n";
    s=s+"<text x=\""+to_string(sega->lunghezza+20)+"\" y=\""+to_string(sega->raggio+10+(sega->altezza)/2)+"\" fill=\"black\" >"+to_string(sega->altezza)+"(cm)</text>\n";
    s=s+"</svg>\n";
    return s;
}

void sega_save(string filename, string s){

    ofstream file(filename);
    file << s;
    file.close();
}

string sega_load(string filename){

    string s,str;
    ifstream file(filename);
    if(file.is_open()){
      while(getline(file,s)){
        str=str+s;
      }
      file.close();
      cout<<"Il file "<<filename<<" e` stato letto"<<endl;
      cout<<str<<endl;
      return str;
    }

    else
    cout<<"il file non esiste\n";   
}

sega_circolare* sega_parse(string svg){
    sega_circolare* sega2;
/*
* funzione parse
*/

    return sega2;
}