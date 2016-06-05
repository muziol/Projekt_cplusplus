#include "szarpane.h"
#include <iostream>
#include <fstream>

using namespace std;

Szarpane::Szarpane()
{
    //ctor
}

Szarpane::~Szarpane()
{
    //dtor
}

void Szarpane::set_param(float wag, float cen, int il_szt, string mat, string naz, int il_str, string wz_drg){
    _waga = wag;
    _cena = cen;
    _il_sztuk = il_szt;
    _material = mat;
    _nazwa = naz;
    _il_strun = il_str;
    _wzbudzanie_drgan = wz_drg;
}

void Szarpane::get_param(){
    string s = "                                        ";
    cout<<s<<"#  Instrument strunowy szarpany:  #"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<<endl;
    cout<<s<<"# -Material: "<<_material<<endl;
    cout<<s<<"# -Ilosc strun: "<<_il_strun<<endl;
    cout<<s<<"# -Wzbudzanie drgan: "<<_wzbudzanie_drgan<<endl;
}

void Szarpane::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"1.2;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_il_strun<<";"<<_wzbudzanie_drgan<<endl;
    plik.close();
}
