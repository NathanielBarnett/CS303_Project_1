//Students : Nathaniel Barnett    | Adam Bergman         | Urvish Shah
//Email    : nabgz8@mail.umkc.edu | ambd5d@mail.umkc.edu | ujs8t2@mail.umkc.edu

//Professor: Dr. Mohammad Kuhail
//Class    : CS 303 - Data Structures 

//Date     : 9/25/2016
//Project  : Polynomial Addition Program (Project 1B)

//File name:main.cpp
#include "menu.h"

int main()
{
    bool temp = true;

    while (temp != false)
    {
        Menu menu_object = Menu();

        menu_object.ShowMenu();

        //ask user if they want to add more polynomials

        char yes_no;

        cout << "\n(Start over) - Do you want to enter more polynomials to add?" << endl;
        cout << "\nPlease enter <Y> (yes) or <N> (no)" << endl;

        cin >> yes_no;
        cin.ignore(256, '\n');

        switch (yes_no)
        {
        case 'Y':
        case 'y':
            menu_object.ShowMenu();

        case 'N':
        case 'n':
            cout << "Thank you for using the polynomial addition program!" << endl;
            temp = false;
            break;

        default:
            cout << "Please enter 'Y' or 'N'" << endl;
        }
    }
    return 0;
}
