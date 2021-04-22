#include <iostream>

using namespace std;

void sega_dati(double *r, double *h, double *l){
      
      cout<<"inserisci il raggio che desideri ";
      cin>>r;  

      cout<<"inserisci l'altezza che desideri ";
      cin>>h;

      cout<<"inserisci la lunghezza che desideri ";
      cin>>l;    
}

void sega_check(double *r, double *h, double *l){
   
      if(r<0 || h<0 || l<0){
            cout<<"i dati inseriti non hanno senso, devono essere maggiori di 0";
            sega_mod(r,h,l);
      }
      else if((2*r)>h || (2*r)>l){
            cout<<"base e altezza del supporto dovrebbero essere maggiori al doppio del raggio della ruota";
            sega_mod(r,h,l);
      }
      else if(h>l){
            cout<<"se l'altezza è maggiore della lunghezza il pezzo è poco stabile";
            sega_mod(r,h,l);
      }
}

void sega_mod(double *r, double *h, double *l){
//riacquisire i dati sbagliati
  cout<<"inserisci un raggio adeguato ";
      cin>>r;  

      cout<<"inserisci un altezza ";
      cin>>h;

      cout<<"inserisci una lunchezza ";
      cin>>l;  
}

struct sega_circolare{
  double raggio;
  double pos[2];
  double altezza;
  double lunghezza;
};


main(){

ruota* arc=new ruota;


double a=2;
double b=5;
get_posizione(b,a,arc->pos);
cout<<"vettore di 1 "<<arc->pos[1]<<" vettore di 2 "<<arc->pos[2];



 cout<<"\n";  
   return 0;
}