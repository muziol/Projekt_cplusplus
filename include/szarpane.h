#ifndef SZARPANE_H
#define SZARPANE_H
#include "strunowy.h"
#include <string>

class Szarpane : public Strunowy
{
    public:
        Szarpane();
        virtual ~Szarpane();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, int il_str, std::string wz_drg);
        void get_param();
        void zapisz();

    protected:
        std::string _wzbudzanie_drgan; //rece gole/uzbrojone, drewnanie pioro

    private:
};

#endif // SZARPANE_H
