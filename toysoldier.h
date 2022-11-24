#ifndef TOYSOLDIER_CLASS
#define TOYSOLDIER_CLASS

#include <iostream>
#include "product.h"

using namespace std;

class ToySoldier:public Product
{
    public:
        ToySoldier() {size = 0; price = 0;}
        void output(ostream &out)const;
        void input(istream &in);

    protected:
        double size;
};


#endif