#include "samobrzmiace.h"
#include <iostream>
#include <fstream>

using namespace std;

Samobrzmiace::Samobrzmiace()
{
    //ctor
}

Samobrzmiace::~Samobrzmiace()
{
    //dtor
}

void Samobrzmiace::set_param(float wag, float cen, int il_szt, string mat, string naz, string pal, string ksz_wib){
  _waga = wag;
  _cena = cen;
  _il_sztuk = il_szt;
  _material = mat;
  _nazwa = naz;
  _paleczki = pal;
  _ksztalt_wibratora = ksz_wib;
}

void Samobrzmiace::get_param(){
    string s = "                                        ";
    cout<<s<<"# Instr. perkusyjny samobrzmiacy: #"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<<endl;
    cout<<s<<"# -Material: "<<_material<<endl;
    cout<<s<<"# -Paleczki: "<<_paleczki<<endl;
    cout<<s<<"# -Ksztalt wibratora: "<<_ksztalt_wibratora<<endl;
}

void Samobrzmiace::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"3.1;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_paleczki<<";"<<_ksztalt_wibratora<<endl;
    plik.close();
}
