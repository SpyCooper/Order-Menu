#ifndef PENCIL_CLASS
#define PENCIL_CLASS

#include <iostream>
#include "product.h"

using namespace std;

class Pencil:public Product
{
    public:
        Pencil() {lead_diameter = 0; price = 0;}
        void output(ostream &out)const;
        void input(istream &in);

    protected:
        double lead_diameter;
};


#endif