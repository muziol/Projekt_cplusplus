#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include <string>
class Instrument
{
    public:
        Instrument();
        virtual ~Instrument();
        virtual void set_param()=0;
        virtual void get_param()=0;

    protected:
        float _waga;
        float _cena;
        int _il_sztuk;
        std::string _material; //drewno, metla, tw sztuczne
        std::string _nazwa;

    private:
};

#endif // INSTRUMENT_H
