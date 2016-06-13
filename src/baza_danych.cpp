#include <zalacznik.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;
Baza_danych::Baza_danych(){}
Baza_danych::~Baza_danych(){
tabD.clear();
tabP.clear();
tabS.clear();
}

void Baza_danych::zapisz(){
ifstream plik ("data.txt");
plik.close();
remove ("data.txt");
/************STRUNOWE***********/
for (unsigned int i=0; i < tabS.size(); i++){
    Strunowy *tmp = new Strunowy;
    tmp = tabS[i];
    tmp->zapisz();
}
/************DETE***************/
for (unsigned int i=0; i < tabD.size(); i++){
    Dete *tmp = new Dete;
    tmp = tabD[i];
    tmp->zapisz();
}
/************PERKUSYJNE*********/
for (unsigned int i=0; i< tabP.size(); i++){
    Perkusyjny *tmp = new Perkusyjny;
    tmp = tabP[i];
    tmp->zapisz();
}
}/*********ZAPISZ***************/

void Baza_danych::odczyt(){
Okno *ekran=new Okno;
ifstream plik ("data.txt");
string line;
string token;
vector <string> dana;
if ( plik.is_open() ){

    while (getline(plik,line)){
        stringstream stream(line);
        dana.clear();
		while(getline(stream,token,';')){
			dana.push_back(token);
		}
        /*for (unsigned int i=0; i < dana.size(); i++){
            cout << dana[i] << endl;
        }*/

        if (dana[0] == "1.1"){
            Smyczkowy *tmp=new Smyczkowy;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            int il_str = atoi(dana[6].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], il_str, dana[7]);
            tabS.push_back(tmp);
        } //**SMYCZKOWY**
        else if (dana[0] == "1.2"){
            Szarpane *tmp=new Szarpane;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            int il_str = atoi(dana[6].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], il_str, dana[7]);
            tabS.push_back(tmp);
        } //**SZARPANY**
        else if (dana[0] == "1.3"){
            Uderzane *tmp=new Uderzane;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            int il_str = atoi(dana[6].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], il_str, dana[7]);
            tabS.push_back(tmp);
        } //**UDERZANY**
        else if (dana[0] == "2.1"){
            Drewniane *tmp=new Drewniane;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            float dl_rury = atof(dana[6].c_str());
            int il_otw = atoi(dana[8].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], dl_rury, dana[7], il_otw);
            tabD.push_back(tmp);
        } //**DREWNIANY**
        else if (dana[0] == "2.2"){
            Blaszane *tmp=new Blaszane;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            float dl_rury = atof(dana[6].c_str());
            float sr_rozt = atof(dana[8].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], dl_rury, dana[7], sr_rozt);
            tabD.push_back(tmp);
        } //**BLASZANY**
        else if (dana[0] == "2.3"){
            Klawiszowe *tmp=new Klawiszowe;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            float dl_rury = atof(dana[6].c_str());
            int il_klaw = atoi(dana[7].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], dl_rury, il_klaw );
            tabD.push_back(tmp);
        } //**KLAWISZOWY**
        else if (dana[0] == "3.1"){
            Samobrzmiace *tmp=new Samobrzmiace;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], dana[6], dana[7] );
            tabP.push_back(tmp);
        } //**SAMOBRZMIACY**
        else if (dana[0] == "3.2"){
            Membranowe *tmp=new Membranowe;
            float wag = atof(dana[1].c_str());
            float cen = atof(dana[2].c_str());
            int il_szt = atoi(dana[3].c_str());
            float sr_memb = atof(dana[8].c_str());
            tmp->set_param(wag, cen, il_szt, dana[4], dana[5], dana[6], dana[7], sr_memb );
            tabP.push_back(tmp);
        } //**MEMBRANOWY**

    }// While
}
else ekran->ramka(1, "Brak pliku z danymi !");
plik.close();
remove( "data.txt" );
zapisz();
}//***********ODCZYT**************************/

void Baza_danych::dodaj_instrument(){
    short int odp=0; string wczyt = "";
    Okno *ekran = new Okno;
while (odp>4 || odp<1){
    ekran->ramka(-1, "Wybierz rodzaj instrumentu:");
    ekran->ramka(0, "1. Strunowy  ");
    ekran->ramka(0, "2. Dety      ");
    ekran->ramka(0, "3. Perkusyjny");
    ekran->ramka(3, "4. Powrot    ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ dodaj_strunowy(); } // *1*
else if (odp == 2){ dodaj_dety(); } // *2*
else if (odp == 3){ dodaj_perkusyjny(); } // *3*
else if (odp == 4){  } // *4*
}

void Baza_danych::dodaj_strunowy(){
    short int odp=0; string wczyt = "";
    Okno *ekran = new Okno;
while (odp>4 || odp<1){
    ekran->ramka(-1, "Wybierz instrument strunowy:");
    ekran->ramka(0, "1. Smyczkowy");
    ekran->ramka(0, "2. Szarpany ");
    ekran->ramka(0, "3. Uderzany ");
    ekran->ramka(3, "4. Powrot   ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
/* 1. Smyczkowy */if (odp == 1){
    string typ_smy="", mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, il_str=-1; odp = 0; wczyt = "";
while (odp>3 || odp<1){
    ekran->ramka(-1, "Podaj typ smyczka:");
    ekran->ramka(0, "1. Konskie wlosie    ");
    ekran->ramka(0, "2. Syntetyczne wlosie");
    ekran->ramka(3, "3. Powrot            ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ typ_smy = "Konskie wlosie"; } // *1*
else if (odp == 2){ typ_smy = "Syntetyczne wlosie"; } // *2*
else if (odp == 3){ dodaj_strunowy(); } // *3*
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag <= 0) ekran->tekst("Niepoprawna waga , popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(0, " np. Skrzypce, Altowka,");
    ekran->ramka(3, "Wiolonczela, Kontrabas.");
    getline(cin, naz);
/*********************************************************************************/
    while (il_str<=0){
    ekran->ramka(4, "Podaj il. strun instrumentu:");
    getline(cin, wczyt);
    il_str = atoi(wczyt.c_str());
    if (il_str<=0) ekran->tekst("Niepoprawna ilosc strun, popraw!");}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Smyczkowy *tmp = new Smyczkowy;
tmp->set_param(wag, cen, il_szt, mat, naz, il_str, typ_smy);
if (koniec == 1){
    tabS.push_back(tmp);
    ekran->ramka(-1, "Dodales: ");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawanie !");
ekran->krawedz();
} // *1. Smyczkowy***************SMYCZKOWY***************************/
/* 2. Szarpany */else if (odp == 2){
    string wz_drg="", mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, il_str=-1; odp = 0; wczyt = "";
while (odp>4 || odp<1){
    ekran->ramka(-1, "Napisz czym wzbudzasz drgania:");
    ekran->ramka(0, "1. Gole rece      ");
    ekran->ramka(0, "2. Uzbrojone rece ");
    ekran->ramka(0, "3. Drewniane pioro");
    ekran->ramka(3, "4. Powrot         ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ wz_drg = "Gole rece"; }            // *1*
else if (odp == 2){ wz_drg = "Uzbrojone rece"; }  // *2*
else if (odp == 3){ wz_drg = "Drewniane pioro"; } // *3*
else if (odp == 4){ dodaj_strunowy(); }           // *4*
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag <= 0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(0, "np. Balalajka, Bandzola, Banjo,");
    ekran->ramka(0, "    Gitara, Harfa, Kobza, Lira,");
    ekran->ramka(3, "    Lutnia, Mandolina, Ukulele.");
    getline(cin, naz);
/*********************************************************************************/
    while (il_str<=0){
    ekran->ramka(4, "Podaj il. strun instrumentu:");
    getline(cin, wczyt);
    il_str = atoi(wczyt.c_str());
    if (il_str<=0) ekran->tekst("Niepoprawna ilosc strun, popraw!");}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Szarpane *tmp = new Szarpane;
tmp->set_param(wag, cen, il_szt, mat, naz, il_str, wz_drg);
if (koniec == 1){
    tabS.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *2* Szarpany ******************SZARPANY**************************
/* 3. Uderzany */else if (odp == 3){
    string uderz="", mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, il_str=-1; odp = 0; wczyt = "";
while (odp>4 || odp<1){
    ekran->ramka(-1, "Czym uderzasz w struny:");
    ekran->ramka(0, "1. Recznie    ");
    ekran->ramka(0, "2. Tangentem  ");
    ekran->ramka(0, "3. Mloteczkiem");
    ekran->ramka(3, "4. Powrot     ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ uderz = "Recznie"; }          // *1*
else if (odp == 2){ uderz = "Tangentem"; }   // *2*
else if (odp == 3){ uderz = "Mloteczkiem"; } // *3*
else if (odp == 4){ dodaj_strunowy(); }      // *4*
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(0, "np. Cymbaly, Klawikord,");
    ekran->ramka(3, "    Fortepian, Pianino.");
    getline(cin, naz);
/*********************************************************************************/
    while (il_str<=0){
    ekran->ramka(4, "Podaj il. strun instrumentu:");
    getline(cin, wczyt);
    il_str = atoi(wczyt.c_str());
    if (il_str<=0) ekran->tekst("Niepoprawna ilosc strun, popraw!");}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Uderzane *tmp = new Uderzane;
tmp->set_param(wag, cen, il_szt, mat, naz, il_str, uderz);
if (koniec == 1){
    tabS.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *3*
/* 4. Powrot */else if (odp == 4){ dodaj_instrument(); } // *4************POWROT********************************
}

void Baza_danych::dodaj_dety(){
    short int odp=0; string wczyt = "";
    Okno *ekran = new Okno;
while (odp>4 || odp<1){
    ekran->ramka(-1, "Wybierz instrument dety:");
    ekran->ramka(0, "1. Drewniany ");
    ekran->ramka(0, "2. Blaszany  ");
    ekran->ramka(0, "3. Klawiszowy");
    ekran->ramka(3, "4. Powrot    ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
/* 1. Drewniany */if (odp == 1){
    string typ_wib="", mat="", naz=""; float wag=-1, cen=-1, dl_rury=-1; int il_szt=-1, il_otw = -1; odp = 0;
while (odp>4 || odp<1){
    ekran->ramka(-1, "Podaj typ wibratora:");
    ekran->ramka(0, "1. Pojedynczy stroik   ");
    ekran->ramka(0, "2. Podwojny stroik     ");
    ekran->ramka(0, "3. Wibrator krawedziowy");
    ekran->ramka(3, "4. Powrot              ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ typ_wib = "Pojedynczy stroik"; }         // *1*
else if (odp == 2){ typ_wib = "Podwojny stroik"; }      // *2*
else if (odp == 3){ typ_wib = "Wibrator krawedziowy"; } // *3*
else if (odp == 4){ dodaj_dety(); }                     // *4*
/************************************************************************/
while (il_otw<=0){
    ekran->ramka(4, "Podaj ilosc otworow:");
    getline(cin, wczyt);
    il_otw = atoi(wczyt.c_str());
    if (il_otw<=0) ekran->tekst("Niepoprawna liczba otworow, popraw!");
}
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(0, "np. Flet, Klarnet, Saksofon,");
    ekran->ramka(3, "    Oboj, Fagot.            ");
    getline(cin, naz);
/*********************************************************************************/
    while (dl_rury<=0){
    ekran->ramka(4, "Podaj dl. rury instrumentu: [cm]");
    getline(cin, wczyt);
    dl_rury = atof(wczyt.c_str());
    if (dl_rury<=0) ekran->tekst("Niepoprawna dlugosc rury, popraw!");}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Drewniane *tmp = new Drewniane;
tmp->set_param(wag, cen, il_szt, mat, naz, dl_rury, typ_wib, il_otw);
if (koniec == 1){
    tabD.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *1*********DREWNIANY***********************************/
/* 2. Blaszany */else if (odp == 2){
    string typ_ust="", mat="", naz=""; float wag=-1, cen=-1, sr_rozt = -1; int il_szt=-1, dl_rury=-1; odp = 0; wczyt= "";
while (odp<1 || odp>3){
    ekran->ramka(-1, "1. Podaj srednice roztrabu");
    ekran->ramka(3, "2. Powrot                  ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>3)  ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){
while (sr_rozt<=0){
    ekran->ramka(4, "Podaj srednice roztrabu:[cm]");
    getline(cin, wczyt);
    sr_rozt = atof(wczyt.c_str());
    if (sr_rozt<=0) ekran->tekst("Niepoprawna srednica roztrabu, popraw!");
}
}// *1*
else if (odp == 2){odp=0; dodaj_dety();}// *2*
    odp = 0;
while (odp>4 || odp<1){
    ekran->ramka(-1, "Podaj typ ustnika:");
    ekran->ramka(0, "1. Lejkowaty   ");
    ekran->ramka(0, "2. Kociolkowaty");
    ekran->ramka(3, "3. Powrot      ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ typ_ust = "Lejkowaty"; }         // *1*
else if (odp == 2){ typ_ust = "Kociolkowaty"; } // *2*
else if (odp == 3){ odp=0; dodaj_dety(); }      // *3*
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Cena nie moze byc ujemna, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(3, "np. Trabka, Puzon, Tuba, Rog.");
    getline(cin, naz);
/*********************************************************************************/
    while (dl_rury<=0){
    ekran->ramka(4, "Podaj dl. rury instrumentu: [cm]");
    getline(cin, wczyt);
    dl_rury = atoi(wczyt.c_str());
    if (dl_rury<=0) ekran->tekst("Niepoprawna dlugosc rury, popraw!");}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Blaszane *tmp = new Blaszane;
tmp->set_param(wag, cen, il_szt, mat, naz, dl_rury, typ_ust, sr_rozt);
if (koniec == 1){
    tabD.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *2*
/* 3. Klawiszowy */else if (odp == 3){
    string mat="", naz=""; float wag=-1, cen=-1; int il_szt=-1, dl_rury=-1, il_klaw = -1; odp = 0; wczyt = "";
while (odp<1 || odp>3){
    ekran->ramka(-1, "1. Podaj ilosc klawiszy");
    ekran->ramka(3,  "2. Powrot              ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>3)  ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){
while (il_klaw<=0){
    ekran->ramka(4, "Podaj ilosc klawiszy:");
    getline(cin, wczyt);
    il_klaw = atoi(wczyt.c_str());
    if (il_klaw<=0) ekran->tekst("Niepoprawna liczba klawiszy, popraw!");
}
}// *1*
else if (odp == 2){ dodaj_dety();}// *2*
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(3, "np. Organy, Akordeon, Fisharmonia");
    getline(cin, naz);
/*********************************************************************************/
    while (dl_rury<=0){
    ekran->ramka(4, "Podaj dl. rury instrumentu: [cm]");
    getline(cin, wczyt);
    dl_rury = atoi(wczyt.c_str());
    if (dl_rury<=0) ekran->tekst("Niepoprawna dlugosc rury, popraw!");}
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2 ) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Klawiszowe *tmp = new Klawiszowe;
tmp->set_param(wag, cen, il_szt, mat, naz, dl_rury, il_klaw);
if (koniec == 1){
    tabD.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *3************KLAWISZOWY***********************************/
/* 4. Powrot */else if (odp == 4){ odp=0; dodaj_instrument(); } // *4****POWROT*****************************/
}

void Baza_danych::dodaj_perkusyjny(){
    short int odp=0; string wczyt = "";
    Okno *ekran = new Okno;
while (odp>3 || odp<1){
    ekran->ramka(-1, "Wybierz instrument perkusyjny:");
    ekran->ramka(0, "1. Samobrzmiacy");
    ekran->ramka(0, "2. Membranowy  ");
    ekran->ramka(3, "3. Powrot      ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
/* 1. Samobrzmiace */if (odp == 1){
    string ksz_wib="", mat="", naz="", pal=""; float wag=-1, cen=-1; int il_szt=-1; odp = 0; wczyt = "";
while (odp>5 || odp<1){
    ekran->ramka(-1, "Podaj ksztalt wibratora:");
    ekran->ramka(0, "1. Plytowy  ");
    ekran->ramka(0, "2. Sztabkowy");
    ekran->ramka(0, "3. Rurowy   ");
    ekran->ramka(0, "4. Pretowy  ");
    ekran->ramka(3, "5. Powrot   ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 5 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ ksz_wib = "Plytkowy"; }            // *1*
else if (odp == 2){ ksz_wib = "Sztabkowy"; }      // *2*
else if (odp == 3){ ksz_wib = "Rurowy"; }         // *3*
else if (odp == 4){ ksz_wib = "Pretowy"; }        // *4*
else if (odp == 5){ odp=0; dodaj_perkusyjny(); }  // *5*
/**********************************************************************/
    while (wag<=0 ){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag <=0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(0, "np. Talerze, Gong, Czelesta,");
    ekran->ramka(3, "Ksylofon, Dzwony rurowe, trojkat.");
    getline(cin, naz);
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy sa dolaczone paleczki?");
    ekran->ramka(0, "1. Tak");
    ekran->ramka(3, "2. Nie");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
}
if (odp == 1){pal = "Tak";}       // *1*
else if (odp == 2){pal = "Nie";}  // *2*
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Samobrzmiace *tmp = new Samobrzmiace;
tmp->set_param(wag, cen, il_szt, mat, naz, pal, ksz_wib);
if (koniec == 1){
    tabP.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
}
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *1**************SAMOBRZMIACE********************/
/* 2. Membranowe */else if (odp == 2){
    string wl_aku="", mat="", naz="", pal=""; float wag=-1, cen=-1, sr_memb; int il_szt=-1; odp = 0;
while (odp<1 || odp>3){
    ekran->ramka(-1, "1. Podaj srednice membrany");
    ekran->ramka(3, "2. Powrot                 ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>3)  ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){
while (sr_memb<=0){
    ekran->ramka(4, "Podaj srednice membrany: [cm]");
    getline(cin, wczyt);
    sr_memb = atof(wczyt.c_str());
    if (sr_memb<=0) ekran->tekst("Niepoprawna srednica membrany, popraw!");
}
}// *1*
else if (odp == 2){odp=0; dodaj_perkusyjny();}// *2*
    odp = 0;
while (odp>3 || odp<1){
    ekran->ramka(-1, "Podaj wlasciwosc akustyczna:");
    ekran->ramka(0, "1. Nieokreslona wysokosc dzwieku");
    ekran->ramka(0, "2. Okreslona wysokosc dzwieku   ");
    ekran->ramka(3, "3. Powrot                       ");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 3 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
}
if (odp == 1){ wl_aku = "Nieokreslona wysokosc dzwieku"; }   // *1*
else if (odp == 2){ wl_aku = "Okreslona wysokosc dzwieku"; } // *2*
else if (odp == 3){ odp=0; dodaj_perkusyjny(); }             // *3*
/**********************************************************************/
    while (wag<=0){
    ekran->ramka(4, "Podaj wage instrumentu: [kg]");
    getline(cin, wczyt);
    wag = atof(wczyt.c_str());
    if (wag<=0) ekran->tekst("Niepoprawna waga, popraw!");}
/**************************************************************************/
    while (cen<=0){
    ekran->ramka(4, "Podaj cene instrumentu: [pln]");
    getline(cin, wczyt);
    cen = atof(wczyt.c_str());
    if (cen<=0) ekran->tekst("Niepoprawna cena, popraw!");}
/***************************************************************************/
    while (il_szt<=0){
    ekran->ramka(4, "Podaj il. sztuk instrumentu:");
    getline(cin, wczyt);
    il_szt = atoi(wczyt.c_str());
    if (il_szt<=0) ekran->tekst("Niepoprawna ilosc sztuk, popraw!");}
/******************************************************************************/
    ekran->ramka(-1, "Podaj material instrumentu:");
    ekran->ramka(3, "np. Drewno, Plastik, Metal.");
    getline(cin, mat);
/*******************************************************************************/
    ekran->ramka(-1, "Podaj nazwe instrumentu:");
    ekran->ramka(0, "np. Beben, Tom-tom,");
    ekran->ramka(3, "    Kotly, Rototom.");
    getline(cin, naz);
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy sa dolaczone paleczki?");
    ekran->ramka(0, "1. Tak");
    ekran->ramka(3, "2. Nie");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
}
if (odp == 1){pal = "Tak";}       // *1*
else if (odp == 2){pal = "Nie";}  // *2*
/*********************************************************************************/
    odp = 0;
while (odp<1 || odp>2){
    ekran->ramka(-1, "Czy chcesz zapisac instrument:");
    ekran->ramka(0, "1. TAK");
    ekran->ramka(3, "2. NIE");
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp<1 || odp>2) ekran->tekst("Niepoprawna odpowiedz, popraw!");
} short int koniec = odp;
/************************************************************************************/
Membranowe *tmp = new Membranowe;
tmp->set_param(wag, cen, il_szt, mat, naz, pal, wl_aku, sr_memb );
if (koniec == 1){
    tabP.push_back(tmp);
    ekran->ramka(-1, "Dodales:");
    tmp->get_param();
} // *1*
else ekran->ramka(-1, "Anulowales dodawania !");
ekran->krawedz();
} // *2*
/* 3. Powrot */else if (odp == 3){ dodaj_instrument(); } // *3*********POWROT******************/
}

int Baza_danych::wypisz(string a){
    Okno *ekran = new Okno;
    short int odp = 0; string wczyt = "";
    while (odp<1 || odp>4){
        ekran->ramka(-1, "Jakie instrumenty "+a+"?");
        ekran->ramka(0, "1. Strunowe  ");
        ekran->ramka(0, "2. Dete      ");
        ekran->ramka(0, "3. Perkusyjne");
        ekran->ramka(3, "4. Powrot    ");
        getline(cin, wczyt);
        odp = atoi(wczyt.c_str());
        if (odp > 4 || odp < 1) ekran->tekst("Podales zla liczbe, popraw!");}
/*1. wypisz_strunowe*/if (odp == 1){
int sizS = tabS.size();
for (int i =0; i < sizS; i++){
    Strunowy *tmp=new Strunowy;
    tmp = tabS[i];
    int n = i+1;
    stringstream ss;
    ss << n;
    string nr = ss.str();
    ekran->ramka(-1, "# Nr instrumentu: "+nr);
    tmp->get_param();
    ekran->krawedz();
}}/******WYPISZ_STRUNOWE***********************/
/*2. wypisz_dete*/else if (odp == 2){
int sizD = tabD.size();
for (int i =0; i < sizD; i++){
    Dete *tmp=new Dete;
    tmp = tabD[i];
    int n = i+1;
    stringstream ss;
    ss << n;
    string nr = ss.str();
    ekran->ramka(-1, "Nr instrumentu: "+nr);
    tmp->get_param();
    ekran->krawedz();
}}/******WYPISZ_DETE***************************/
/*3. wypisz_perkusyjne*/else if (odp == 3){
int sizP = tabP.size();
for (int i =0; i < sizP; i++){
    Perkusyjny *tmp=new Perkusyjny;
    tmp = tabP[i];
    int n = i+1;
    stringstream ss;
    ss << n;
    string nr = ss.str();
    ekran->ramka(-1, "Nr instrumentu: "+nr);
    tmp->get_param();
    ekran->krawedz();
}}/******WYPISZ_PERKUSYJNE********************/
/*4. Powrot*/else if (odp == 4){ }
return odp;
}

void Baza_danych::usun(){
Okno *ekran=new Okno;
int odp=0, arg=0, usun=1; string wczyt= "";
arg = wypisz("usunac ");
/* tabS */if (arg == 1){
int rozmiar = tabS.size();
while (odp<1 || odp>rozmiar){
if (tabS.size() == 0){
    ekran->ramka(1, "Brak danych");
    usun = 0;
    break;
}
ekran->ramka(4, "Podaj nr. usuwanego instrumentu:");
getline(cin, wczyt);
odp = atoi(wczyt.c_str());
if (odp<1 || odp>rozmiar) ekran->tekst("Zla odpowiedz, popraw! ");}
if (usun == 1) tabS.erase(tabS.begin() + odp - 1);
}/******************TAB_S*************************************/
/* tabD */else if (arg == 2){
int rozmiar = tabD.size();
while (odp<1 || odp>rozmiar){
if (tabD.size() == 0){
    ekran->ramka(1, "Brak danych");
    usun = 0;
    break;
}
ekran->ramka(4, "Podaj nr. usuwanego instrumentu:");
getline(cin, wczyt);
odp = atoi(wczyt.c_str());
if (odp<1 || odp>rozmiar) ekran->tekst("Zla odpowiedz, popraw! ");}
if (usun == 1) tabD.erase(tabD.begin() + odp - 1);
}/*****************TAB_D**************************************/
/* tabP */else if (arg == 3) {
int rozmiar = tabP.size();
while (odp<1 || odp>rozmiar){
if (tabP.size() == 0){
    ekran->ramka(1, "Brak danych");
    usun = 0;
    break;
}
ekran->ramka(4, "Podaj nr. usuwanego instrumentu:");
getline(cin, wczyt);
odp = atoi(wczyt.c_str());
if (odp<1 || odp>rozmiar) ekran->tekst("Zla odpowiedz, popraw! ");}
if (usun == 1) tabP.erase(tabP.begin() + odp - 1);
}/*****************TAB_P**************************************/
}

void Baza_danych::interfejs(){
    Okno *ekran = new Okno;
    ekran->ramka(-1, "Co chcesz zrobic ?");
    ekran->ramka(0, "1. Dodaj instrument");
    ekran->ramka(0, "2. Usun instrument ");
    ekran->ramka(0, "3. Wypisz          ");
    ekran->ramka(3, "4. Zapisz i wyjdz  ");
}

void Baza_danych::powitaj(){
    Okno *ekran = new Okno;
    ekran->ramka(1, "Witamy w BiBi!");
}

void Baza_danych::start(){
odczyt();
powitaj();
Okno *ekran = new Okno;
short int odp=0; string wczyt = "";

while (odp>4 || odp<1){
    interfejs();
    getline(cin, wczyt);
    odp = atoi(wczyt.c_str());
    if (odp > 4 || odp < 1) ekran->tekst("Podales niepoprawna liczbe, popraw!");
if (odp == 1){ odp=0; dodaj_instrument(); }     /* 1. Dodaj instrument */
else if (odp == 2){ odp=0; usun(); }            /* 2. Usun */
else if (odp == 3){ odp=0; wypisz("wypisac"); } /* 3. Wypisz */
else if (odp == 4){ zapisz(); break; }          /* 4. Zapisz i Wyjdz */
}
}
