#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
# include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\tClient Card:";
		cout << "\n\t___________________";
		cout << "\n\tFirstName   : " << Client.FirstName;
		cout << "\n\tLastName    : " << Client.LastName;
		cout << "\n\tFull Name   : " << Client.FullName();
		cout << "\n\tEmail       : " << Client.Email;
		cout << "\n\tPhone       : " << Client.Phone;
		cout << "\n\tAcc. Number : " << Client.AccountNumber();
		cout << "\n\tPassword    : " << Client.PinCode;
		cout << "\n\tBalance     : " << Client.AccountBalance;
		cout << "\n\t___________________\n" << endl;

	}



public:

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return; // this will exit the function and will not continue 
		}

		clsScreen::_DrawScreenHeader("\tDelete Screen");

		cout << "\nPlease enter account number : ";
		string AccountNumber;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found , please enter another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		char Answer;
		cout << "Do you want to delete this client [ y / n ] : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully " << endl;

				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}

	}

};

