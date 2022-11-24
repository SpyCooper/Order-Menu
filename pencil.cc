#include <iostream>
#include "product.h"
#include "pencil.h"

using namespace std;

void Pencil::output(ostream &out)const
{
    if(&out == &cout)
    {
        //runs the output to the monitor
        cout << lead_diameter << "mm Pencil" << endl;
    }
    else
    {
        //runs the output for a file
        out << "Pencil " << lead_diameter << endl;
    }
}

void Pencil::input(istream &in)
{
    if(&in == &cin)
    {
        //runs the input from the keyboard
        bool done = false;
        while(done == false)
        {
            //asks for diameter of the lead for the pencil
            double temp;
            cout << "Select the diameter of the lead (0.9, 0.7, 0.5, 0.3): ";
            cin >> temp;
            if(temp == 0.9 || temp == 0.7 || temp == 0.5 || temp == 0.3)
            {
                lead_diameter = temp;
                done = true;
            }
            else
            {
                cout << "Error: not a diameter of lead" << endl;
            }
        }
    }
    else
    {
        //runs the input from the data file
        in >> lead_diameter;
        string garbage;
        getline(in, garbage);
    }

    //sets the price of the pencil
    price = 0.99;
}