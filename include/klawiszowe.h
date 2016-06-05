#ifndef KLAWISZOWE_H
#define KLAWISZOWE_H
#include "dete.h"

class Klawiszowe : public Dete
{
    public:
        Klawiszowe();
        virtual ~Klawiszowe();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, float dl_rury, int il_klaw);
        void get_param();
        void zapisz();

    protected:
        int _il_klawiszy; //ilosc klawiszy

    private:
};

#endif // KLAWISZOWE_H
