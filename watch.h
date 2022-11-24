#ifndef WATCH_CLASS
#define WATCH_CLASS

#include <iostream>
#include <string>
#include "product.h"

using namespace std;

class Watch:public Product
{
    public:
        Watch() {diameter = 0; color = ""; price = 0;}
        void output(ostream &out)const;
        void input(istream &in);

    protected:
        double diameter;
        string color;
};


#endif