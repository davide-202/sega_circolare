#include "sega.h"
#include "svg.h"
#include <iostream>


using namespace std;

void sega_init(double r, double h, double l){
      if(r<0 || h<0 || l<0){
            cout<<"i dati inseriti non hanno senso, devono essere maggiori di 0 \n";
      }
      else if((2*r)>h || (2*r)>l){
            cout<<"base e altezza del supporto dovrebbero essere maggiori al doppio del raggio della ruota \n";
      }
      else if(h>l){
            cout<<"se l'altezza è maggiore della lunghezza il pezzo è poco stabile \n";
      }
      else if(r>100 || h>200 || l>400){
            cout<<"raggio altezza e lunghezza non devono essere troppo grandi (100,200,400) \n";
      }
}

void sega_mod(double r, double h, double l){
        int a,b;
        a=0;
        do{
            cout<<"per modificare il raggio premi 1, per modificare l'altezza premere 2, per modificare la lunchezza premere 3. se non vuoi modificare nulla premere 4 \n ";
            cin>>b;  
            if(b==1){
                  cout<<"inserisci un nuovo raggio";
                  cin>>r;
                  cout<<"se vuoi modificare un altro parametro premere 0, altrimenti premere un altro numero \n";
                  cin>>a;
            }
            else if(b==2){
                  cout<<"inserisci una nuova altezza";
                  cin>>h;
                  cout<<"se vuoi modificare un altro parametro premere 0, altrimenti premere un altro numero \n";
                  cin>>a;
            }
            else if(b==3){
                  cout<<"inserisci una nuova lunghezza";
                  cin>>l;
                  cout<<"se vuoi modificare un altro parametro premere 0, altrimenti premere un altro numero \n";
                  cin>>a;
            } 
            else if(b==4)
                  a=1;
        }while(a==0);
}