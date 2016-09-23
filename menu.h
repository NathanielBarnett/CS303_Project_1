#include <iostream>
#include <string>
#include <stdlib.h>

#include "polynomial.h"

using namespace std;

class Menu
{
public:
    Menu()
    {
        //no variable needs to be handeled
    }

    void ShowMenu();

    void GetUserInput();

private:
    Polynomial user_poly;
};