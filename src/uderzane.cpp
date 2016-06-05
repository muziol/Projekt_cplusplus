#include "uderzane.h"
#include <iostream>
#include <fstream>

using namespace std;

Uderzane::Uderzane()
{
    //ctor
}

Uderzane::~Uderzane()
{
    //dtor
}

void Uderzane::set_param(float wag, float cen, int il_szt, string mat, string naz, int il_str, string uderz){
    _waga = wag;
    _cena = cen;
    _il_sztuk = il_szt;
    _material = mat;
    _nazwa = naz;
    _il_strun = il_str;
    _uderzane = uderz;
}

void Uderzane::get_param(){
    string s = "                                        ";
    cout<<s<<"#  Instrument strunowy uderzany:  #"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<<endl;
    cout<<s<<"# -Material: "<<_material<<endl;
    cout<<s<<"# -Ilosc strun: "<<_il_strun<<endl;
    cout<<s<<"# -Uderzane: "<<_uderzane<<endl;
}

void Uderzane::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"1.3;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_il_strun<<";"<<_uderzane<<endl;
    plik.close();
}
