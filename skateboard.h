#ifndef SKATEBOARD_CLASS
#define SKATEBOARD_CLASS

#include <iostream>
#include "product.h"

using namespace std;

class Skateboard:public Product
{
    public:
        Skateboard() {width = 0; wheel_size = 0; price = 0;}
        void output(ostream &out)const;
        void input(istream &in);

    protected:
        double width;
        int wheel_size;
};


#endif