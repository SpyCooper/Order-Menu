#ifndef DRUMSTICKS_CLASS
#define DRUMSTICKS_CLASS

#include <iostream>
#include <string>
#include "product.h"

using namespace std;

class Drumsticks:public Product
{
    public:
        Drumsticks() {size = ""; price = 0;}
        void output(ostream &out)const;
        void input(istream &in);

    protected:
        string size;
};


#endif