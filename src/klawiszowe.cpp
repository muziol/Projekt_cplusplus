#include "klawiszowe.h"
#include <iostream>
#include <fstream>

using namespace std;

Klawiszowe::Klawiszowe()
{
    //ctor
}

Klawiszowe::~Klawiszowe()
{
    //dtor
}

void Klawiszowe::set_param(float wag, float cen, int il_szt, string mat, string naz, float dl_rury, int il_klaw){
  _waga = wag;
  _cena = cen;
  _il_sztuk = il_szt;
  _material = mat;
  _nazwa = naz;
  _dl_rury = dl_rury;
  _il_klawiszy = il_klaw;
}

void Klawiszowe::get_param(){
    string s = "                                        ";
    cout<<s<<"#     Instrument dety uderzany:   #"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<< endl;
    cout<<s<<"# -Material: "<<_material<< endl;
    cout<<s<<"# -Dlugosc rury: "<<_dl_rury<<" [cm]"<<endl;
    cout<<s<<"# -Ilosc klawiszy: "<<_il_klawiszy<<endl;
}

void Klawiszowe::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"2.3;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_dl_rury<<";"<<_il_klawiszy<<endl;
    plik.close();
}
