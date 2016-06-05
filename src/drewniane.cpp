#include "drewniane.h"
#include <iostream>
#include <fstream>

using namespace std;

Drewniane::Drewniane()
{
    //ctor
}

Drewniane::~Drewniane()
{
    //dtor
}

void Drewniane::set_param(float wag, float cen, int il_szt, string mat, string naz, float dl_rury, string typ_wib, int il_otw){
  _waga = wag;
  _cena = cen;
  _il_sztuk = il_szt;
  _material = mat;
  _nazwa = naz;
  _dl_rury = dl_rury;
  _typ_wibratora = typ_wib;
  _il_otworow = il_otw;
}
void Drewniane::get_param(){
    string s = "                                        ";
    cout<<s<<"#   Instrument dety drewniany:    #"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<<endl;
    cout<<s<<"# -Material: "<<_material<<endl;
    cout<<s<<"# -Dlugosc rury: "<<_dl_rury<<" [cm]"<<endl;
    cout<<s<<"# -Typ wibratora: "<<_typ_wibratora<<endl;
}

void Drewniane::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"2.1;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_dl_rury<<";"<<_typ_wibratora<<";"<<_il_otworow<<endl;
    plik.close();
}
