#include <iostream>
#include "product.h"
#include "skateboard.h"

using namespace std;

void Skateboard::output(ostream &out)const
{
    if(&out == &cout)
    {
        //runs the output to the monitor
        cout << "Skateboard (Width: " << width << " inches, Wheel size: " << wheel_size << "mm)" << endl;
    }
    else
    {
        //runs the output for a file
        out << "Skateboard " << width << " " << wheel_size << endl;
    }
}

void Skateboard::input(istream &in)
{
    if(&in == &cin)
    {
        //runs the input for the keyboard
        bool done1 = false;
        while(done1 == false)
        {
            //asks for the width of the skateboard deck
            double temp;
            cout << "Select the width of the deck in inches (7.5, 8.0, 8.5): ";
            cin >> temp;
            if(temp == 7.5 || temp == 8.0 || temp == 8.5)
            {
                width = temp;
                done1 = true;
            }
            else
            {
                cout << "Error: not an available width" << endl;
            }
        }
        //asks for the diameter of the wheel
        bool done2 = false;
        while(done2 == false)
        {
            int temp;
            cout << "Select the wheel diameter in mm (48, 52, 56, 60): ";
            cin >> temp;
            if(temp == 48 || temp == 52 || temp == 56 || temp == 60)
            {
                wheel_size = temp;
                done2 = true;
            }
            else
            {
                cout << "Error: not an available wheel size" << endl;
            }
        }
    }
    else
    {
        //runs the input from the data file
        in >> width >> wheel_size;
        string garbage;
        getline(in, garbage);
    }
    
    //sets the price of the skateboard
    price = 145.00;
}