#include <iostream>
#include "product.h"
#include "toysoldier.h"

using namespace std;

void ToySoldier::output(ostream &out)const
{
    if(&out == &cout)
    {
        //runs the output to the monitor
        cout << size << " inches Toy Soldier" << endl;
    }
    else
    {
        //runs the output for a file
        out << "ToySoldier " << size << endl;
    }
}

void ToySoldier::input(istream &in)
{
    if(&in == &cin)
    {
        //runs the input for the keyboard
        bool done = false;
        while(done == false)
        {
            //asks for the size of the toy soldier
            double temp;
            cout << "Select the size of the toy soldier in inches (6, 8, 10, 12): ";
            cin >> temp;
            if(temp == 6 || temp == 8 || temp == 10 || temp == 12)
            {
                size = temp;
                done = true;
            }
            else
            {
                cout << "Error: not a size an available toy soldier" << endl;
            }
        }
    }
    else
    {
        //runs the input from the data file
        in >> size;
        string garbage;
        getline(in, garbage);
    }
    
    //sets the price of the toy soldier
    price = 2.99;
}