#include "okno.h"
#include <iostream>

using namespace std;

Okno::Okno(){
    s = "                                        ";
    l = "###################################";
}

Okno::~Okno(){ }

void Okno::ramka(int w, string a){
    string b = s;
    if (w == -1 || w == 1 || w == 4) cout<<s<<l<<endl;
    b += "#";
    int dl = a.length();
    for (int i=0; i < ((33-dl) /2); i++){
        b += " ";
    }
    b += a;
    for (int i=0; i<((33-dl) /2); i++){
        b += " ";
    }
    if (a.length() % 2 == 0) b += " ";
    b += "#";

    cout << b << endl;
    if (w == 1 || w == 2 || w == 3 || w == 4) cout<<s<<l<<endl;
    if (w == 3 || w == 4) cout<<s<<"-> ";
}

void Okno::strzalka(){
    string s = "                                        ";
    cout <<s<< "-> ";
}

void Okno::krawedz(){
    cout<<s<<l<<endl;
}

void Okno::tekst(string a){
    cout <<s<< a << endl;
}
