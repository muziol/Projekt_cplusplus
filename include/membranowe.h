#ifndef MEMBRANOWE_H
#define MEMBRANOWE_H
#include "perkusyjny.h"
#include <string>

class Membranowe : public Perkusyjny
{
    public:
        Membranowe();
        virtual ~Membranowe();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, std::string pal, std::string wl_aku, float sr_memb);
        void get_param();
        void zapisz();

    protected:
        std::string _wl_akustyczne; //wlasciwosci akustyczne (nieokreslonej/okreslonej wysokosci dzwieku)
        float _sr_membrany; //srednica membrany

    private:
};

#endif // MEMBRANOWE_H
