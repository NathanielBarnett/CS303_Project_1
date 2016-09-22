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

        cout << "Do you want to enter more polynomials to add?" << endl;
        cout << "Please enter <Y> (yes) or <N> (no)" << endl;

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