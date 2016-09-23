#include "menu.h"
#include "polynomial.h"
#include "term.h"

void Menu::GetUserInput()
{
    string polynomial1, polynomial2;

    //read first poly
    cout << "\nPlease enter your first polynomial: ";
    getline(cin, polynomial1);

    //parse user input and convert to Term object and push onto Polynomial
    Poly_Parse(polynomial1, user_poly);

    //read second poly
    cout << "\nPlease enter your second polynomial: ";
    getline(cin, polynomial2);

    //parse user input and convert to Term object and push onto Polynomia2
    Poly_Parse(polynomial2, user_poly);
}

void Menu::ShowMenu()
{
    cout << "********** -Polynomial Program- **********" << endl;
    cout << "\nRules:\n";
    cout << "You can enter your polynomial in the follwing format : ax^n+ax-1" << endl;
    cout << "Considering a = coefficient, x = variable and n = whole number" << endl;
    cout << "Please do not use paranthesis or spaces." << endl;
    cout << "You can enter either the + or - operator based on your choice for the polynomial" << endl;
    cout << endl;

    char input;
    bool end = true;
    while (end != false)
    {
        cout << "\nPlease choose one of the following option:\n";
        cout << "<E> to enter a Polynomial\n<N> to quit the program\n";
        cout << "Please enter <E> or <N>:" << endl;

        cin >> input;
        cin.ignore(256, '\n');

        switch (input)
        {
        case 'E':
        case 'e':
            //call function to let the user enter polynomials
            GetUserInput();
            break;

        case 'N':
        case'n':
            //terminate program 
            end = false;
            exit(0);
            

        default:
            cout << "\nPlease enter 'E' or 'N'" << endl;
        }
    }
}

