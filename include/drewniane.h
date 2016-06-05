#ifndef DREWNIANE_H
#define DREWNIANE_H
#include "dete.h"
#include <string>

class Drewniane : public Dete
{
    public:
        Drewniane();
        virtual ~Drewniane();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, float dl_rury, std::string typ_wib, int il_otw);
        void get_param();
        void zapisz();

    protected:
        int _il_otworow; //il dziur ktorymi malipuje sie strumien wyjsciowy dziwieku
        std::string _typ_wibratora; // pojedynczy/podwojny stroik, wibrator krawedziowy

    private:
};

#endif // DREWNIANE_H
