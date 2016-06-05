#ifndef BAZA_DANYCH_H
#define BAZA_DANYCH_H
#include <iostream>
#include <vector>
#include <zalacznik.h>

using namespace std;

class Baza_danych
{
    public:
        Baza_danych();
        virtual ~Baza_danych();
        void dodaj_instrument();
        void dodaj_strunowy();
        void dodaj_dety();
        void dodaj_perkusyjny();
        void zapisz();
        void odczyt();
        int wypisz(string a);
        void usun();
        void interfejs();
        void powitaj();
        void start();

    protected:

    private:
        vector <Strunowy*> tabS;
        vector <Dete*> tabD;
        vector <Perkusyjny*> tabP;
};

#endif // BAZA_DANYCH_H
