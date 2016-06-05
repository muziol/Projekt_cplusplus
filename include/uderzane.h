#ifndef UDERZANE_H
#define UDERZANE_H
#include "strunowy.h"
#include <string>

class Uderzane : public Strunowy
{
    public:
        Uderzane();
        virtual ~Uderzane();
        void set_param(float wag, float cen, int il_szt, std::string mat, std::string naz, int il_str, std::string uderz);
        void get_param();
        void zapisz();

    protected:
        std::string _uderzane; //recznie/tangentem/mloteczkiem

    private:
};

#endif // UDERZANE_H
