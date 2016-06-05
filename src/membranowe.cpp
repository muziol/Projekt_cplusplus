#include "membranowe.h"
#include <iostream>
#include <fstream>

using namespace std;

Membranowe::Membranowe()
{
    //ctor
}

Membranowe::~Membranowe()
{
    //dtor
}

void Membranowe::set_param(float wag, float cen, int il_szt, string mat, string naz, string pal, string wl_aku, float sr_memb){
  _waga = wag;
  _cena = cen;
  _il_sztuk = il_szt;
  _material = mat;
  _nazwa = naz;
  _paleczki = pal;
  _wl_akustyczne = wl_aku;
  _sr_membrany = sr_memb;
}

void Membranowe::get_param(){
    string s = "                                        ";
    cout<<s<<"#   To jest instrument blaszany   #" << endl;
    cout<<s<<"#Instrument perkusyjny membranowy:#"<<endl;
    cout<<s<<"# -Nazwa: "<<_nazwa<<endl;
    cout<<s<<"# -Waga: "<< _waga <<" [kg]"<<endl;
    cout<<s<<"# -Cena: "<<_cena<<" [pln]"<<endl;
    cout<<s<<"# -Ilosc sztuk: "<<_il_sztuk<<endl;
    cout<<s<<"# -Material: "<<_material<<endl;
    cout<<s<<"# -Paleczki: "<<_paleczki<<endl;
    cout<<s<<"# -Wlasciwosci akustyczne: "<<_wl_akustyczne<<endl;
    cout<<s<<"# -Srednica membrany: "<<_sr_membrany<<" [cm]"<<endl;
}

void Membranowe::zapisz(){
    ofstream plik;
    plik.open("data.txt" , ofstream::out | ofstream::app);
    plik <<"3.2;"<<_waga<<";"<<_cena<<";"<<_il_sztuk<<";"<<_material<<";"<<_nazwa<<";"<<_paleczki<<";"<<_wl_akustyczne<<";"<<_sr_membrany<<endl;
    plik.close();
}
