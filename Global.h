#pragma once
# include <iostream>
# include "clsUser.h"

clsUser CurrentUser = clsUser::Find("", "");

string GreenFont = "\033[32m";
string WhiteFont = "\033[0m";
string RedFont = "\033[31m";