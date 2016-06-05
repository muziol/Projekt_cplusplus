#include "blaszane.h"
#include <iostream>
#include <fstream>

using namespace std;

Blaszane::Blaszane()
{
    //ctor
}

Blaszane::~Blaszane()
{
    //dtor
}

void Blaszane::set_param(float wag, float cen, int il_szt, string mat, string naz, float dl_rury, string typ_ust, float sr_rozt){
  _waga = wag;
  _cena = cen;
  _il_sztuk = il_szt;
  _material = mat;
  _nazwa = naz;
  _dl_rury = dl_rury;
  _typ_ustnika = typ_ust;
  _sr_roztrabu = sr_rozt;
}

void Blaszane::get_param(){
    string s = "                                        ";
    cout<<s<<"#    Instrument dety blaszany:    #"<< endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<< endl;
    cout<<s<<"# -Material: "<<_material<< endl;
    cout<<s<<"# -Dlugosc rury: "<<_dl_rury<<" [cm]"<<endl;
    cout<<s<<"# -Typ ustnika: "<<_typ_ustnika<<endl;
    cout<<s<<"# -Srednica roztrabu: "<<_sr_roztrabu<<" [cm]"<<endl;
}

void Blaszane::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"2.2;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_dl_rury<<";"<<_typ_ustnika<<";"<<_sr_roztrabu<<endl;
    plik.close();
}
