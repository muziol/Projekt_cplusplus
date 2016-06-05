#ifndef PERKUSYJNY_H
#define PERKUSYJNY_H
#include "instrument.h"

class Perkusyjny : public Instrument
{
    public:
        Perkusyjny();
        virtual ~Perkusyjny();
        virtual void set_param();
        virtual void get_param();
        virtual void zapisz();

    protected:
        std::string _paleczki; // TAK lub NIE

    private:
};

#endif // PERKUSYJNY_H
