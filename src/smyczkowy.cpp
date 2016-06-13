#include "smyczkowy.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Smyczkowy::Smyczkowy()
{
    //ctor
}

Smyczkowy::~Smyczkowy()
{
    //dtor
}

void Smyczkowy::set_param(float wag, float cen, int il_szt, string mat, string naz, int il_str, string typ_smy){
  _waga = wag;
  _cena = cen;
  _il_sztuk = il_szt;
  _material = mat;
  _nazwa = naz;
  _il_strun = il_str;
  _typ_smyczka = typ_smy;
  }

void Smyczkowy::get_param(){
    string s = "                                        ";
    cout<<s<<"#  Instrument strunowy smyczkowy: #"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<<endl;
    cout<<s<<"# -Material: "<<_material<<endl;
    cout<<s<<"# -Ilosc strun: "<<_il_strun<<endl;
    cout<<s<<"# -Typ smyczka: "<<_typ_smyczka<<endl;
  }

void Smyczkowy::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"1.1;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_il_strun<<";"<<_typ_smyczka<<endl;
    plik.close();
}
