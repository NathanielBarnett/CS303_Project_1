//Students : Nathaniel Barnett    | Adam Bergman         | Urvish Shah
//Email    : nabgz8@mail.umkc.edu | ambd5d@mail.umkc.edu | ujs8t2@mail.umkc.edu

//Professor: Dr. Mohammad Kuhail
//Class    : CS 303 - Data Structures 

//Date     : 9/25/2016
//Project  : Polynomial Addition Program (Project 1B)

//File name:menu.h
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
