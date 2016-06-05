#ifndef STRUNOWY_H
#define STRUNOWY_H
#include "instrument.h"

class Strunowy : public Instrument
{
    public:
        Strunowy();
        virtual ~Strunowy();
        virtual void set_param();
        virtual void get_param();
        virtual void zapisz();

    protected:
        int _il_strun; //ilosc strun,klawiszy w instrumencie

    private:
};

#endif // STRUNOWY_H
