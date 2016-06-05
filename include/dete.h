#ifndef DETE_H
#define DETE_H
#include "instrument.h"

class Dete : public Instrument
{
    public:
        Dete();
        virtual ~Dete();
        virtual void set_param();
        virtual void get_param();
        virtual void zapisz();

    protected:
        float _dl_rury;

    private:
};

#endif // DETE_H
