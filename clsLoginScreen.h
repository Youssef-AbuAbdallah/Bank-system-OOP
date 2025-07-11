#pragma once
# include <iostream>
#include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsUser.h"
# include "clsMainScreen.h"
# include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFailed = false;
		short CountLoginFailed = 0;
		string UserName, Password;

		
		do
		{
			if (LoginFailed)
			{
				CountLoginFailed++;
				cout << RedFont << "\nInvalid username / password \n" << WhiteFont << endl;
				cout << "You have " << 3 - CountLoginFailed << " trial(s) to login \n";
				
			}

			if (CountLoginFailed == 3)
			{
				cout << RedFont << "\nYou are locked after 3 failed Trials !" << WhiteFont << endl;
				return false;
			}

			cout << "Enter UserName : ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.clsUser::IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenue();

	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}

};

