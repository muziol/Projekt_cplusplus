#ifndef BLASZANE_H
#define BLASZANE_H
#include "dete.h"

class Blaszane : public Dete
{
    public:
        Blaszane();
        virtual ~Blaszane();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, float dl_rury, std::string typ_ust, float sr_rozt);
        void get_param();
        void zapisz();

    protected:
        std::string _typ_ustnika; //lekowaty, kociolkowaty
        float _sr_roztrabu; //srednica roztrabu [cm]

    private:
};

#endif // BLASZANE_H
