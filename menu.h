#include <iostream>
#include <string>
#include <stdlib.h>
#include "polynomial.h"

using namespace std;
//Menu class with functions to start the program.
class Menu
{
public:

    Menu()
    {
        //no variable needs to be handeled
    }

    void ShowMenu();//Prompts the user for info when called.

    void GetUserInput();//Allows user to input polynomials when called.

private:

    Polynomial user_poly;
};
