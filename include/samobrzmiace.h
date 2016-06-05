#ifndef SAMOBRZMIACE_H
#define SAMOBRZMIACE_H
#include "perkusyjny.h"
#include <string>

class Samobrzmiace : public Perkusyjny
{
    public:
        Samobrzmiace();
        virtual ~Samobrzmiace();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, std::string pal, std::string ksz_wib);
        void get_param();
        void zapisz();

    protected:
        std::string _ksztalt_wibratora; //plytowy, sztabkowy, rurowy, pretowy

    private:
};

#endif // SAMOBRZMIACE_H
