#include <iostream>
#include "Hashtable.h"
using namespace std;
int main()
{
    Hashtable price_menu;
    price_menu.insert("Coke", 40);
    price_menu.insert("Coke", 45);
    price_menu.insert("Coke", 5);
    price_menu.insert("BurgerPizza", 600);
    price_menu.insert("BurgerPizza", 700);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Pepsi", 200);
    price_menu.insert("Burger", 100);
    price_menu.insert("Pizza", 500);
    // price_menu.insert("Coke", 407);

    price_menu.print();
    // cout << "Price of this is " << *price_menu.search("Pizza") << endl;
    price_menu.deletion("Coke");
    price_menu.deletion("Coke");
    price_menu.insert("Coke", 54);
    price_menu.insert("Coke", 57);
    price_menu.deletion("Coke");
    price_menu.deletion("Coke");
    // price_menu.deletion("Coke");

    price_menu.deletion("Pepsi");
    price_menu.deletion("Pepsi");
    price_menu["Burger"] = 18;
    price_menu["Pizza"] += 100;

    cout << "New updated value in the table are: " << *price_menu.search("Burger") << " " << *price_menu.search("Pizza") << endl; // derefrencing becoz it is returning address
    price_menu.print();
}