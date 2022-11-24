#ifndef PRODUCT_CLASS
#define PRODUCT_CLASS

#include <iostream>

using namespace std;

class Product
{
    public:
        virtual void output(ostream &out)const =0;
        virtual void input(istream &in) =0;
        double get_price() {return price;}

    protected:
        double price;
};


#endif