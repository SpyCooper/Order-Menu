#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include "product.h"
#include "toysoldier.h"
#include "drumsticks.h"
#include "skateboard.h"
#include "pencil.h"
#include "watch.h"

using namespace std;

int main()
{
    //make a STL list of products
    list<Product*> products;

    //load in from orders.txt based on what type the file says it is
    ifstream infile;
    infile.open("orders.txt");
    if(!infile.fail())
    {
        while(!infile.eof())
        {
            if(infile.peek() == '\n' || infile.peek() == '\r')
            {
                string garbage;
                getline(infile, garbage);
            }
            else
            {
                string type;
                infile >> type;
                if(type == "ToySoldier")
                {
                    ToySoldier *temp;
                    temp = new ToySoldier;
                    temp->input(infile);
                    products.push_back(temp);
                }
                else if(type == "Drumstick")
                {
                    Drumsticks *temp;
                    temp = new Drumsticks;
                    temp->input(infile);
                    products.push_back(temp);
                }
                else if(type == "Skateboard")
                {
                    Skateboard *temp;
                    temp = new Skateboard;
                    temp->input(infile);
                    products.push_back(temp);
                }
                else if(type == "Pencil")
                {
                    Pencil *temp;
                    temp = new Pencil;
                    temp->input(infile);
                    products.push_back(temp);
                }
                else if(type == "Watch")
                {
                    Watch *temp;
                    temp = new Watch;
                    temp->input(infile);
                    products.push_back(temp);
                }
                else
                {
                    string garbage;
                    getline(infile, garbage);
                }
            }
        }
    }

    int choice = 0;

    while(choice != 9)
    {
        //displays a menu with borders and asks for which option the user wants
        cout << "--------------------------------------" << endl;
        cout << "Choose an option" << endl;
        cout << "1. Add a Toy Soldier" << endl;
        cout << "2. Add a Drumsticks" << endl;
        cout << "3. Add a Skateboard" << endl;
        cout << "4. Add a Pencil" << endl;
        cout << "5. Add a Watch" << endl;
        cout << "6. View sum of all products order" << endl;
        cout << "7. Show all ordered products" << endl;
        cout << "8. Remove a product from the order" << endl;
        cout << "9. End Program" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------------" << endl;
        
        if(choice == 1)
        {
            //adds a new toy soldier to the list
            ToySoldier *temp;
            temp = new ToySoldier;
            temp->input(cin);
            products.push_back(temp);
        }
        else if(choice == 2)
        {
            //adds a new pair of drumsticks to the list
            Drumsticks *temp;
            temp = new Drumsticks;
            temp->input(cin);
            products.push_back(temp);
        }
        else if(choice == 3)
        {
            //adds a new skateboard to the list
            Skateboard *temp;
            temp = new Skateboard;
            temp->input(cin);
            products.push_back(temp);
        }
        else if(choice == 4)
        {
            //adds a new pencil to the list
            Pencil *temp;
            temp = new Pencil;
            temp->input(cin);
            products.push_back(temp);
        }
        else if(choice == 5)
        {
            //adds a new watch to the list
            Watch *temp;
            temp = new Watch;
            temp->input(cin);
            products.push_back(temp);
        }
        else if(choice == 6)
        {
            //iterator goes through the list and adds up all the sums of the list
            double sum = 0;
            if(products.empty())
            {
                cout << "You have no orders." << endl;
            }
            else
            {
                list<Product*>::iterator it;
                it = products.begin();
                while(it != products.end())
                {
                    sum = sum + (*it)->get_price();
                    ++it;
                }
            }
            cout << "Total price is $" << sum << endl;
        }
        else if(choice == 7)
        {
            //show all products
            if(products.empty())
            {
                cout << "You have no orders." << endl;
            }
            else
            {
                list<Product*>::iterator it;
                it = products.begin();
                while(it != products.end())
                {
                    (*it)->output(cout);
                    ++it;
                }
            }
        }
        else if(choice == 8)
        {
            //remove an item from the list after checking if it's empty
            if(products.empty())
            {
                cout << "Error: You have no orders" << endl;
            }
            else
            {
                list<Product*>::iterator it;
                it = products.begin();
                while(it != products.end())
                {
                    char choice;
                    (*it)->output(cout);
                    cout << "Would you like to remove this product? (y/n) ";
                    cin >> choice;
                    if(choice == 'y')
                    {
                        products.erase(it);
                        break;
                    }
                    else
                    {
                        ++it;
                    }
                }
            }
        }
        else if(choice != 9)
        {
            //returns an error if an number not 1-9 is entered
            cout << "Error: not an option" << endl;
        }
    }

    //save to orders.txt
    ofstream outfile;
    outfile.open("orders.txt");
    if(outfile.fail())
    {
        return 1;
    }
    //iterator goes through the list and outputs the data to a file
    list<Product*>::iterator it;
    it = products.begin();
    while(it != products.end())
    {
        (*it)->output(outfile);
        ++it;
    }

    //closes both files
    infile.close();
    outfile.close();
    return 0;
}