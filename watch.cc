#include <iostream>
#include "product.h"
#include "watch.h"

using namespace std;

void Watch::output(ostream &out)const
{
    if(&out == &cout)
    {
        //runs the output to the monitor
        cout << color << " "  << diameter << " inch watch" << endl;
    }
    else
    {
        //runs the output to a file
        out << "Watch " << color << " " << diameter << endl;
    }
}

void Watch::input(istream &in)
{
    if(&in == &cin)
    {
        //runs the input for the keyboard
        bool done1 = false;
        while(done1 == false)
        {
            //asks for the diameter
            double temp;
            cout << "Select the diameter of the watch (1.1, 1.3, 1.4): ";
            cin >> temp;
            if(temp == 1.1 || temp == 1.3 || temp == 1.4)
            {
                diameter = temp;
                done1 = true;
            }
            else
            {
                cout << "Error: not a diameter of an available watch" << endl;
            }
        }
        bool done2 = false;
        while(done2 == false)
        {
            //asks for the color
            string temp;
            cout << "Select the color of the watch (black, silver, gold): ";
            cin >> temp;
            if(temp == "black" || temp == "silver" || temp == "gold")
            {
                color = temp;
                done2 = true;
            }
            else
            {
                cout << "Error: not a color of available watch" << endl;
            }
        }
    }
    else
    {
        //runs the input from the data file
        in >> color >> diameter;
        string garbage;
        getline(in, garbage);
    }

    //sets the price of the watch
    price = 84.99;
}