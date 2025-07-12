#include <iostream>
# include "clsLoginScreen.h"
# include "clsScreen.h" // for global fonts colors here
# include "Global.h"
using namespace std;

string clsScreen::GreenFont = "\033[32m";
string clsScreen::WhiteFont = "\033[0m";
string clsScreen::RedFont = "\033[31m";

int main()
{

    while (true) // this loop to solve the problem of Circular Reference
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }


    return 0;
}