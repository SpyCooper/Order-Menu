#include <iostream>
#include "product.h"
#include "drumsticks.h"

using namespace std;

void Drumsticks::output(ostream &out)const
{
    if(&out == &cout)
    {
        //runs the output to the monitor
        cout << size << " Drumstick Pair" << endl;
    }
    else
    {
        //runs the output for a file
        out << "Drumstick " << size << endl;
    }
}

void Drumsticks::input(istream &in)
{
    if(&in == &cin)
    {
        //runs the input for the keyboard
        bool done = false;
        while(done == false)
        {
            //asks for the size of the drumsticks
            string temp;
            cout << "Select the size of the drumstick (2B, 5B, 5A, 7A): ";
            cin >> temp;
            if(temp == "2B" || temp == "5B" || temp == "5A" || temp == "7A")
            {
                size = temp;
                done = true;
            }
            else
            {
                cout << "Error: not a size of stick" << endl;
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

    //sets the price of the drumsticks
    price = 4.99;
}