#include <iostream>
# include "clsBankClient.h"
#include "clsInputValidate.h"
# include "clsString.h"
# include "clsUtil.h"
# include <vector>
# include <string>
# include <cstdlib>
# include "clsDate.h"
# include <fstream>
# include "clsMainScreen.h"
# include "clsScreen.h"

string clsScreen::GreenFont = "\033[32m";
string clsScreen::WhiteFont = "\033[0m";
string clsScreen::RedFont = "\033[31m";

int main()
{

    clsMainScreen::ShowMainMenue();

    return 0;
}