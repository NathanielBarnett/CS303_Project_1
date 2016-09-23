#include "menu.h"
#include "polynomial.h"
#include "term.h"

void Menu::GetUserInput()
{
	string polynomial1, polynomial2;

	//read first poly
	cout << "Please enter your first polynomial: " << '\n';
	getline(cin, polynomial1);

	//read second poly
	cout << "Please enter your second polynomial: " << '\n';
	getline(cin, polynomial2);
}

void Menu::ShowMenu()
{
	cout << "********** -Polynomial Program- **********" << endl;
	cout << "\nRules:\n";
	cout << "You can enter your polynomial in the follwing format : ax^n + ax - 1" << endl;
	cout << "Considering a = coefficient, x = variable and n = whole number" << endl;
	cout << "Please do not use paranthesis." << endl;
	cout << "You can enter either the + or - operator based on your choice for the polynomial" << endl;
	cout << endl;

	char input;
	bool end = true;
	while (end != false)
	{
		cout << "Please choose one of the following option:\n";
		cout << "<E> to enter a Polynomial\n<N> to quit the program";
		cout << "Please enter <E> or <N>:" << endl;

		cin >> input;
		cin.ignore(256, '\n');

		switch (input)
		{
		case 'E':
		case 'e':
			GetUserInput();
			break;

		case 'N':
		case'n':
			end = false;
			break;

		default:
			cout << "Please enter 'E' or 'N'" << endl;
		}
	}
}
