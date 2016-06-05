#ifndef SMYCZKOWY_H
#define SMYCZKOWY_H
#include "strunowy.h"
#include <string>

class Smyczkowy : public Strunowy
{
    public:
        Smyczkowy();
        ~Smyczkowy();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, int il_str, std::string typ_smy);
        void get_param();
        void zapisz();
        void odczyt();

    protected:
        std::string _typ_smyczka; //konskie/syntetyczne wlosie

    private:
};

#endif // SMYCZKOWY_H
