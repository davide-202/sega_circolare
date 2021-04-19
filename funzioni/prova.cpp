#include <iostream>

using namespace std;

double get_raggio(){
    double r;
    do{
      cout<<"inserisci il raggio che desideri (>0)";
      cin>>r;
    }
    while(r<=0);
    return r;
}

double get_spessore(){
    double s;
    do{
      cout<<"inserisci lo spessore del bordo (>0)";
      cin>>s;
    }
    while(s<=0);
    return s;
}

void get_posizione(double r, double s, double pos[]){
    do{
      cout<<"dove vuoi posizionare la ruota? \n val_x (>raggio+spessore)";
      cin>>pos[1];
      cout<<"\n val_y (>raggio+spessore)";
      cin>>pos[2];
    }
    while(pos[1]<=r+s || pos[2]<=r+s);
}

struct ruota{
  double raggio;
  double spessore;
  double pos[2];
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