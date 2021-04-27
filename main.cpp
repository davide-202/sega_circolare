#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

/*
#include "sega.h"
#include "svg.h"
 */
using namespace std;

int sega_init(double r, double h, double l){
      if(r<0 || h<0 || l<0){
            cout<<"i dati inseriti non hanno senso, devono essere maggiori di 0 \n";
            return 1;
      }
      else if((2*r)>h || (2*r)>l){
            cout<<"base e altezza del supporto dovrebbero essere maggiori al doppio del raggio della ruota \n";
            return 1;
      }
      else if(h>l){
            cout<<"se l'altezza è maggiore della lunghezza il pezzo è poco stabile \n";
            return 1;
      }
      else if(r>100 || h>200 || l>400){
            cout<<"raggio altezza e lunghezza non devono essere troppo grandi (100,200,400) \n";
            return 1;
      }
      else 
      return 0;
}

void sega_mod(double r, double h, double l){
        int a,b;
        a=0;
        do{
            cout<<"per modificare il raggio premi 1, per modificare l'altezza premere 2, per modificare la lunghezza premere 3. se non vuoi modificare nulla premere 4 \n";
            cin>>b;  
            if(b==1){
                  cout<<"inserisci un nuovo raggio ";
                  cin>>r;
                  cout<<"se vuoi modificare un altro parametro premere 0, altrimenti premere un altro numero \n";
                  cin>>a;
            }
            else if(b==2){
                  cout<<"inserisci una nuova altezza ";
                  cin>>h;
                  cout<<"se vuoi modificare un altro parametro premere 0, altrimenti premere un altro numero \n";
                  cin>>a;
            }
            else if(b==3){
                  cout<<"inserisci una nuova lunghezza ";
                  cin>>l;
                  cout<<"se vuoi modificare un altro parametro premere 1, altrimenti premere un altro numero \n";
                  cin>>a;
            } 
            else if(b==4)
                  a=0;
        a=sega_init(r,h,l);
        }while(a==1);
}

struct sega_circolare{
  double raggio;
  double altezza;
  double lunghezza;
};


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
/*
    ifstream t(filename);
    stringstream buffer;

    buffer << t.rdbuf();
    string s = buffer.str();
*/   
}

sega_circolare* sega_parse(string svg){
    sega_circolare* sega2;
/*
* funzione parse
*/

    return sega2;
}


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