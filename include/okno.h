#ifndef OKNO_H
#define OKNO_H
#include <string>

using namespace std;


class Okno
{
    public:
        Okno();
        virtual ~Okno();
/**************RAMKA**************/
    // [-1] krawedz/tekst
    // [0] tekst
    // [1] krawedz/tekst/krawedz
    // [2] tekst/krawedz
    // [3] tekst/krawedz/strzalka
    // [4] krawedz/tekst/krawedz/strzalka
        void ramka(int w, string a);
        void strzalka();
        void krawedz();
        void tekst(string a);

    private:
        string s;
        string l;
};

#endif // OKNO_H
