#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string.h>
#include "zalacznik.h"
#include "baza_danych.h"

using namespace std;
vector <Strunowy*> tabS;
vector <Dete*> tabD;
vector <Perkusyjny*> tabP;
/*********DEKLARACJE_FUKCJI*******************************/
void interfejs(); void dodaj_dety(); void dodaj_strunowy(); void dodaj_perkusyjny();
/***************ZAPIS_PLIKU*******************************/
void zapisz(){

}
/***************ODCZYT_PLIKU*****************************/
void odczyt(){
    fstream plik;
    plik.open("data.txt", ios::in | ios::out );
    if ( plik.good() == false ){
        string s = "                                        ";
        string l = "###################################";
        cout<<s<<l<<endl;
        cout <<s<< "#      Brak pliku z danymi !      #" << endl;
        cout<<s<<l<<endl<<endl;
    }
    else {

    }

}
/*************INTERFEJS_DODAWANIA**************************/
void dodaj_instrument(){
    short int odp=0; string wczyt = "";
    string s = "                                        ";
    string l = "###################################";
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#   Wybierz rodzaj instrumentu:   #" << endl;
    cout <<s<< "#   1. Strunowy                   #" << endl;
    cout <<s<< "#   2. Dety                       #" << endl;
    cout <<s<< "#   3. Perkusyjny                 #" << endl;
    cout <<s<< "#   4. Powrot                     #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ dodaj_strunowy(); } // *1*
else if (odp == 2){ dodaj_dety(); } // *2*
else if (odp == 3){ dodaj_perkusyjny(); } // *3*
else if (odp == 4){  } // *4*
}
/***********DODAWANIE_INSTRUMENTU_STRUNOWEGO******************/
void dodaj_strunowy(){
    short int odp=0; string wczyt = "";
    string s = "                                        ";
    string l = "###################################";
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#   Wybierz instrument strunowy:  #" << endl;
    cout <<s<< "#   1. Smyczkowy                  #" << endl;
    cout <<s<< "#   2. Szarpany                   #" << endl;
    cout <<s<< "#   3. Uderzany                   #" << endl;
    cout <<s<< "#   4. Powrot                     #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
/* 1. Smyczkowy */if (odp == 1){
    string typ_smy="", mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, il_str=-1; odp = 0; wczyt = "";
while (odp>3 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#      Podaj typ smyczka:         #" << endl;
    cout <<s<< "#     1. Konskie wlosie           #" << endl;
    cout <<s<< "#     2. Syntetyczne wlosie       #" << endl;
    cout <<s<< "#     3. Powrot                   #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ typ_smy = "Konskie wlosie"; } // *1*
else if (odp == 2){ typ_smy = "Syntetyczne wlosie"; } // *2*
else if (odp == 3){ dodaj_strunowy(); } // *3*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag <= 0) cout <<s<< "Niepoprawna waga , popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#     np. Skrzypce, Altowka,      #" << endl;
    cout <<s<< "#     Wiolonczela, Kontrabas.     #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    while (il_str<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#Podaj il. strun instrumentu:#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_str = atoi(wczyt.c_str());
    if (il_str<=0) cout <<s<< "Niepoprawna ilosc strun, popraw!" << endl;}
/*********************************************************************************/
    odp = 0;
    while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;} short int koniec = odp;
/************************************************************************************/
Smyczkowy *tmp = new Smyczkowy;
tmp->set_param(wag, cen, il_szt, mat, naz, il_str, typ_smy);
cout<<s<<l<<endl;
if (koniec == 1){
    tabS.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *1. Smyczkowy***************SMYCZKOWY***************************/
/* 2. Szarpany */else if (odp == 2){
    string wz_drg="", mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, il_str=-1; odp = 0; wczyt = "";
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "# Napisz czym wzbudzasz drgania:  #" << endl;
    cout <<s<< "#     1. Gole rece                #" << endl;
    cout <<s<< "#     2. Uzbrojone rece           #" << endl;
    cout <<s<< "#     3. Drewniane pioro          #" << endl;
    cout <<s<< "#     4. Powrot                   #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ wz_drg = "Gole rece"; }            // *1*
else if (odp == 2){ wz_drg = "Uzbrojone rece"; }  // *2*
else if (odp == 3){ wz_drg = "Drewniane pioro"; } // *3*
else if (odp == 4){ dodaj_strunowy(); }           // *4*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag <= 0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "# np. Balalajka, Bandzola, Banjo, #" << endl;
    cout <<s<< "#   Gitara, Harfa, Kobza, Lira,   #" << endl;
    cout <<s<< "#   Lutnia, Mandolina, Ukulele.   #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    while (il_str<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#Podaj il. strun instrumentu:#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_str = atoi(wczyt.c_str());
    if (il_str<=0) cout <<s<< "Niepoprawna ilosc strun, popraw!" << endl;}
/*********************************************************************************/
    odp = 0;
    while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;} short int koniec = odp;
/************************************************************************************/
Szarpane *tmp = new Szarpane;
tmp->set_param(wag, cen, il_szt, mat, naz, il_str, wz_drg);
cout<<s<<l<<endl;
if (koniec == 1){
    tabS.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *2* Szarpany ******************SZARPANY**************************
/* 3. Uderzany */else if (odp == 3){
    string uderz="", mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, il_str=-1; odp = 0; wczyt = "";
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#     Czym uderzasz w struny:     #" << endl;
    cout <<s<< "#     1. Recznie                  #" << endl;
    cout <<s<< "#     2. Tangentem                #" << endl;
    cout <<s<< "#     3. Mloteczkiem              #" << endl;
    cout <<s<< "#     4. Powrot                   #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ uderz = "Recznie"; }          // *1*
else if (odp == 2){ uderz = "Tangentem"; }   // *2*
else if (odp == 3){ uderz = "Mloteczkiem"; } // *3*
else if (odp == 4){ dodaj_strunowy(); }      // *4*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#     np. Cymba³y, Klawikord,     #" << endl;
    cout <<s<< "#         Fortepian, Pianino.     #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    while (il_str<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#Podaj il. strun instrumentu:#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_str = atoi(wczyt.c_str());
    if (il_str<=0) cout <<s<< "Niepoprawna ilosc strun, popraw!" << endl;}
/*********************************************************************************/
    odp = 0;
    while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;} short int koniec = odp;
/************************************************************************************/
Uderzane *tmp = new Uderzane;
tmp->set_param(wag, cen, il_szt, mat, naz, il_str, uderz);
cout<<s<<l<<endl;
if (koniec == 1){
    tabS.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *3*
/* 4. Powrot */else if (odp == 4){ dodaj_instrument(); } // *4************POWROT********************************

/************USTAWIANIE_PARAMETROW_DZIEDZICZONYCH****************/
}
/************DODAWANIE_INSTRUMENTU_DETEGO**********************/
void dodaj_dety(){
    short int odp=0; string wczyt = "";
    string s = "                                        ";
    string l = "###################################";
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#   Wybierz instrument dety:      #" << endl;
    cout <<s<< "#   1. Drewniany                  #" << endl;
    cout <<s<< "#   2. Blaszany                   #" << endl;
    cout <<s<< "#   3. Klawiszowy                 #" << endl;
    cout <<s<< "#   4. Powrot                     #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
/* 1. Drewniany */if (odp == 1){
    string typ_wib="", mat="", naz=""; float wag=-1, cen=-1, dl_rury=-1; int il_szt=-1, il_otw = -1; odp = 0;
while (odp<1 || odp>3){
    cout <<s<<l<<endl;
    cout <<s<< "#       1. Podaj ilosc otworow:   #" << endl;
    cout <<s<< "#       2. Powrot                 #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>3)  cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){
    while (il_otw<=0){
    cout << s << "->";
    getline(cin, wczyt);
    il_otw = atoi(wczyt.c_str());
    if (il_otw<=0) cout <<s<< "Niepoprawna liczba otworow, popraw!"<<endl;
    }
}// *1*
else if (odp == 2){ dodaj_dety();}// *2*

    odp = 0;
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#       Podaj typ wibratora:      #" << endl;
    cout <<s<< "#      1. Pojedynczy stroik       #" << endl;
    cout <<s<< "#      2. Podwojny stroik         #" << endl;
    cout <<s<< "#      3. Wibrator krawedziowy    #" << endl;
    cout <<s<< "#      4. Powrot                  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ typ_wib = "Pojedynczy stroik"; }         // *1*
else if (odp == 2){ typ_wib = "Podwojny stroik"; }      // *2*
else if (odp == 3){ typ_wib = "Wibrator krawedziowy"; } // *3*
else if (odp == 4){ dodaj_dety(); }                     // *4*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#   np. Flet, Klarnet, Saksofon,  #" << endl;
    cout <<s<< "#       Oboj, Fagot.              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    while (dl_rury<=0){
    cout <<s<<l<<endl;
    cout <<s<< "# Podaj dl. rury instrumentu: [cm]#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    dl_rury = atof(wczyt.c_str());
    if (dl_rury<=0) cout <<s<< "Niepoprawna dlugosc rury, popraw!" << endl;}
/*********************************************************************************/
    odp = 0;
    while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;} short int koniec = odp;
/************************************************************************************/
Drewniane *tmp = new Drewniane;
tmp->set_param(wag, cen, il_szt, mat, naz, dl_rury, typ_wib, il_otw);
cout<<s<<l<<endl;
if (koniec == 1){
    tabD.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *1*********DREWNIANY***********************************/
/* 2. Blaszany */else if (odp == 2){
    string typ_ust="", mat="", naz=""; float wag=-1, cen=-1, sr_rozt = -1; int il_szt=-1, dl_rury=-1; odp = 0; wczyt= "";
while (odp<1 || odp>3){
    cout <<s<<l<<endl;
    cout <<s<< "#  1. Podaj srednice roztrabu:[cm]#" << endl;
    cout <<s<< "#  2. Powrot                      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>3)  cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){
while (sr_rozt<=0){
    cout << s << "->";
    getline(cin, wczyt);
    sr_rozt = atof(wczyt.c_str());
    if (sr_rozt<=0) cout <<s<< "Niepoprawna srednica roztrabu, popraw!"<<endl;
}
}// *1*
else if (odp == 2){odp=0; dodaj_dety();}// *2*
    odp = 0;
while (odp>4 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#       Podaj typ ustnika:        #" << endl;
    cout <<s<< "#      1. Lejkowaty               #" << endl;
    cout <<s<< "#      2. Kociolkowaty            #" << endl;
    cout <<s<< "#      3. Powrot                  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ typ_ust = "Lejkowaty"; }         // *1*
else if (odp == 2){ typ_ust = "Kociolkowaty"; } // *2*
else if (odp == 3){ odp=0; dodaj_dety(); }      // *3*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->"; cin >> cen; if (cen<=0) cout <<s<< "Cena nie moze byc ujemna, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#  np. Trabka, Puzon, Tuba, Rog.  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    while (dl_rury<=0){
    cout <<s<<l<<endl;
    cout <<s<< "# Podaj dl. rury instrumentu: [cm]#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    dl_rury = atoi(wczyt.c_str());
    if (dl_rury<=0) cout <<s<< "Niepoprawna dlugosc rury, popraw!" << endl;}
/*********************************************************************************/
    odp = 0;
    while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;} short int koniec = odp;
/************************************************************************************/
Blaszane *tmp = new Blaszane;
tmp->set_param(wag, cen, il_szt, mat, naz, dl_rury, typ_ust, sr_rozt);
cout<<s<<l<<endl;
if (koniec == 1){
    tabD.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *2*
/* 3. Klawiszowy */else if (odp == 3){
    string mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, dl_rury=-1, il_klaw = -1; odp = 0; wczyt = "";
while (odp<1 || odp>3){
    cout <<s<<l<<endl;
    cout <<s<< "#       1. Podaj ilosc klawiszy:  #" << endl;
    cout <<s<< "#       2. Powrot                 #" << endl;
    cout <<s<<l<<endl;
        cout <<s<< "->";
        getline(cin, wczyt);
        odp = atoi(wczyt.c_str());
        if (odp<1 || odp>3)  cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){
while (il_klaw<=0){
    cout << s << "->";
    getline(cin, wczyt);
    il_klaw = atoi(wczyt.c_str());
    if (il_klaw<=0) cout <<s<< "Niepoprawna liczba klawiszy, popraw!"<<endl;
}
}// *1*
else if (odp == 2){ dodaj_dety();}// *2*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawba ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#np. Organy, Akordeon, Fisharmonia#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    while (dl_rury<=0){
    cout <<s<<l<<endl;
    cout <<s<< "# Podaj dl. rury instrumentu: [cm]#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    dl_rury = atoi(wczyt.c_str());
    if (dl_rury<=0) cout <<s<< "Niepoprawna dlugosc rury, popraw!" << endl;}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2 ) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;
} short int koniec = odp;
/************************************************************************************/
Klawiszowe *tmp = new Klawiszowe;
tmp->set_param(wag, cen, il_szt, mat, naz, dl_rury, il_klaw);
cout<<s<<l<<endl;
if (koniec == 1){
    tabD.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *3************KLAWISZOWY***********************************/
/* 4. Powrot */else if (odp == 4){ odp=0; dodaj_instrument(); } // *4****POWROT*****************************/
}
/************DODAWANIE_INSTRUMENTU_PERKUSYJNEGO***************/
void dodaj_perkusyjny(){
    short int odp=0; string wczyt = "";
    string s = "                                        ";
    string l = "###################################";
while (odp>3 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#  Wybierz instrument perkusyjny: #" << endl;
    cout <<s<< "#  1. Samobrzmiacy                #" << endl;
    cout <<s<< "#  2. Membranowy                  #" << endl;
    cout <<s<< "#  3. Powrot                      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
/* 1. Samobrzmiace */if (odp == 1){
    string ksz_wib="", mat="", naz="", pal=""; float wag=-1, cen=-1; int il_szt=-1; odp = 0; wczyt = "";
while (odp>5 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj ksztalt wibratora:     #" << endl;
    cout <<s<< "#     1. Plytowy                  #" << endl;
    cout <<s<< "#     2. Sztabkowy                #" << endl;
    cout <<s<< "#     3. Rurowy                   #" << endl;
    cout <<s<< "#     4. Pretowy                  #" << endl;
    cout <<s<< "#     5. Powrot                   #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 5 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ ksz_wib = "Plytkowy"; }            // *1*
else if (odp == 2){ ksz_wib = "Sztabkowy"; }      // *2*
else if (odp == 3){ ksz_wib = "Rurowy"; }         // *3*
else if (odp == 4){ ksz_wib = "Pretowy"; }        // *4*
else if (odp == 5){ odp=0; dodaj_perkusyjny(); }  // *5*
/**********************************************************************/
    while (wag<=0 ){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag <=0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#   np. Talerze, Gong, Czelesta,  #" << endl;
    cout <<s<< "#Ksylofon, Dzwony rurowe, trojkat.#" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "#    Czy sa dolaczone paleczki?   #" << endl;
    cout <<s<< "#            1. Tak               #" << endl;
    cout <<s<< "#            2. Nie               #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;
}
if (odp == 1){pal = "Tak";}       // *1*
else if (odp == 2){pal = "Nie";}  // *2*
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;
} short int koniec = odp;
/************************************************************************************/
Samobrzmiace *tmp = new Samobrzmiace;
tmp->set_param(wag, cen, il_szt, mat, naz, pal, ksz_wib);
cout<<s<<l<<endl;
if (koniec == 1){
    tabP.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
}
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *1**************SAMOBRZMIACE********************/
/* 2. Membranowe */else if (odp == 2){
    string wl_aku="", mat="", naz="", pal=""; float wag=-1, cen=-1, sr_memb; int il_szt=-1; odp = 0;
while (odp<1 || odp>3){
    cout <<s<<l<<endl;
    cout <<s<< "#  1. Podaj srednice membrany:[cm]#" << endl;
    cout <<s<< "#  2. Powrot                      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>3)  cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){
while (sr_memb<=0){
    cout << s << "->";
    getline(cin, wczyt);
    sr_memb = atof(wczyt.c_str());
    if (sr_memb<=0) cout <<s<< "Niepoprawna srednica membrany, popraw!"<<endl;
}
}// *1*
else if (odp == 2){odp=0; dodaj_perkusyjny();}// *2*
    odp = 0;
while (odp>3 || odp<1){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wlasciwosc akustyczna:  #" << endl;
    cout <<s<< "#1. Nieokreslona wysokosc dzwieku #" << endl;
    cout <<s<< "#2. Okreslona wysokosc dzwieku    #" << endl;
    cout <<s<< "#3. Powrot                        #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
}
if (odp == 1){ wl_aku = "Nieokreslona wysokosc dzwieku"; }   // *1*
else if (odp == 2){ wl_aku = "Okreslona wysokosc dzwieku"; } // *2*
else if (odp == 3){ odp=0; dodaj_perkusyjny(); }             // *3*
/**********************************************************************/
    while (wag<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj wage instrumentu: [kg]  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) cout <<s<< "Niepoprawna waga, popraw!" << endl;}
/**************************************************************************/
    while (cen<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj cene instrumentu: [pln] #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) cout <<s<< "Niepoprawna cena, popraw!" << endl;}
/***************************************************************************/
    while (il_szt<=0){
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj il. sztuk instrumentu:  #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) cout <<s<< "Niepoprawna ilosc sztuk, popraw!" << endl;}
/******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#   Podaj material instrumentu:   #" << endl;
    cout <<s<< "# np. Drewno, Plastik, Metal      #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, mat);
/*******************************************************************************/
    cout <<s<<l<<endl;
    cout <<s<< "#    Podaj nazwe instrumentu:     #" << endl;
    cout <<s<< "#      np. Beben, Tom-tom,        #" << endl;
    cout <<s<< "#          Kotly, Rototom.        #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, naz);
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "#    Czy sa dolaczone paleczki?   #" << endl;
    cout <<s<< "#            1. Tak               #" << endl;
    cout <<s<< "#            2. Nie               #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;
}
if (odp == 1){pal = "Tak";}       // *3*
else if (odp == 2){pal = "Nie";}  // *2*
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    cout <<s<<l<<endl;
    cout <<s<< "# Czy chcesz zapisac instrument: #" << endl;
    cout <<s<< "#     1.        TAK              #" << endl;
    cout <<s<< "#     2.        NIE              #" << endl;
    cout <<s<<l<<endl;
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) cout <<s<< "Niepoprawna odpowiedz, popraw!" << endl;
} short int koniec = odp;
/************************************************************************************/
Membranowe *tmp = new Membranowe;
tmp->set_param(wag, cen, il_szt, mat, naz, pal, wl_aku, sr_memb );
cout<<s<<l<<endl;
if (koniec == 1){
    tabP.push_back(tmp);
    cout <<s<< "Dodales: " << endl;
    tmp->get_param();
} // *1*
else cout <<s<< "Anulowales dodawania !";
cout<<s<<l<<endl;
} // *2*
/* 3. Powrot */else if (odp == 3){ dodaj_instrument(); } // *3*
}
/****************WYPISYWANIE*********************************/
int wypisz(string a){
    string s = "                                        ";
    string l = "###################################";
    short int odp = 0; string wczyt = "";
    while (odp<1 || odp>4){
        cout<<s<<l<<endl;
        cout <<s<< "#    Jakie instrumenty "<<a<<"?   #" << endl;
        cout <<s<< "#         1. Strunowe             #" << endl;
        cout <<s<< "#         2. Dete                 #" << endl;
        cout <<s<< "#         3. Perkusyjne           #" << endl;
        cout <<s<< "#         4. Powrot               #" << endl;
        cout<<s<<l<<endl;
        cout <<s<< "->";
        getline(cin, wczyt);
        odp = atoi(wczyt.c_str());
        if (odp > 4 || odp < 1) cout <<s<< "Podales zla liczbe, popraw!" << endl;}
/*1. wypisz_strunowe*/if (odp == 1){
int sizS = tabS.size();
for (int i =0; i < sizS; i++){
    cout<<s<<l<<endl;
    Strunowy *tmp=new Strunowy; tmp = tabS[i];
    cout<<s<<"# Nr instrumentu: "<<i+1<<"  #"<<endl;
    tmp->get_param();
    cout<<s<<l<<endl;
}}/******WYPISZ_STRUNOWE***********************/
/*2. wypisz_dete*/else if (odp == 2){
int sizD = tabD.size();
for (int i =0; i < sizD; i++){
    cout<<s<<l<<endl;
    Dete *tmp=new Dete; tmp = tabD[i];
    cout<<s<<"# Nr instrumentu: "<<i+1<<"  #"<<endl;
    tmp->get_param();
    cout<<s<<l<<endl;
}}/******WYPISZ_DETE***************************/
/*3. wypisz_perkusyjne*/else if (odp == 3){
int sizP = tabP.size();
for (int i =0; i < sizP; i++){
    cout<<s<<l<<endl;
    Perkusyjny *tmp=new Perkusyjny; tmp = tabP[i];
    cout<<s<<"# Nr instrumentu: "<<i+1<<"  #"<<endl;
    tmp->get_param();
    cout<<s<<l<<endl;
}}/******WYPISZ_PERKUSYJNE********************/
/*4. Powrot*/else if (odp == 4){ }
return odp;
}
/*************USUWANIE_INSTRUMENTU***************************/
void usun(){
string s = "                                        ";
string l = "###################################";
unsigned int odp = 0; int arg=0; string wczyt= "";
arg = wypisz("usunac ");
/* tabS */if (arg == 1){
while (odp<1 || odp>tabS.size()){
        string a="1";
cout<<s<<l<<endl;
cout <<s<< "#Podaj nr. usuwanego instrumentu: #" << endl;
cout<<s<<l<<endl;
cout<<s<<"->"; cin >> wczyt;
odp = atoi(wczyt.c_str());
if (odp<1 || odp>tabS.size()) cout <<s<< "Zla odpowiedz, popraw! " << endl;}
tabS.erase(tabS.begin() + odp - 1);
}/******************TAB_S*************************************/
/* tabD */else if (arg == 2){
while (odp<1 || odp>tabD.size()){
cout<<s<<l<<endl;
cout <<s<< "#Podaj nr. usuwanego instrumentu: #" << endl;
cout<<s<<l<<endl;
cout<<s<<"->"; cin >> wczyt;
odp = atoi(wczyt.c_str());
if (odp<1 || odp>tabD.size()) cout <<s<< "Zla odpowiedz, popraw! " << endl;}
tabD.erase(tabD.begin() + odp - 1);
}/*****************TAB_D**************************************/
/* tabP */else if (arg == 3) {
while (odp<1 || odp>tabP.size()){
cout<<s<<l<<endl;
cout <<s<< "#Podaj nr. usuwanego instrumentu: #" << endl;
cout<<s<<l<<endl;
cout<<s<<"->"; cin >> wczyt;
odp = atoi(wczyt.c_str());
if (odp<1 || odp>tabP.size()) cout <<s<< "Zla odpowiedz, popraw! " << endl;}
tabP.erase(tabP.begin() + odp - 1);
}/*****************TAB_P**************************************/

}
/*********************INTERFEJS*******************************/
void interfejs(){
    string s = "                                        ";
    string l = "###################################";
    string e = "";
    e += s+ "#         Co chcesz zrobic ?      #\n";
    e += s+ "#     1. Dodaj instrument         #\n" ;
    e += s+ "#     2. Usun instrument          #\n" ;
    e += s+ "#     3. Wypisz                   #\n" ;
    e += s+ "#     4. Zapisz i wyjdz           #\n" ;
    cout <<s<<l<< endl;
    cout << e;
    cout <<s<<l<< endl;
}
/****************EKRAN_POWITALNY****************************/
void powitaj(){
    string s = "                                        ";
    string l = "###################################";
    cout <<s<<l<< endl;
    cout <<s<< "#          Witamy w BiBi!         #" << endl;
    cout <<s<<l<< endl << endl;
}
/*********************MAIN************************************/
int main(){
odczyt();
powitaj();
string s = "                                        ";
short int odp=0; string wczyt = "";

while (odp>4 || odp<1){
    interfejs();
    cout <<s<< "->";
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) cout <<s<< "Podales niepoprawna liczbe, popraw!" << endl;
if (odp == 1){ odp=0; dodaj_instrument(); }     /* 1. Dodaj instrument */
else if (odp == 2){ odp=0; usun(); }            /* 2. Usun */
else if (odp == 3){ odp=0; wypisz("wypisac"); } /* 3. Wypisz */
else if (odp == 4){ zapisz(); break; }          /* 4. Zapisz i Wyjdz */
}

    return 0;
}
