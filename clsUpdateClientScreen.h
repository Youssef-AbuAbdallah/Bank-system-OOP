#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsBankClient.h"
# include "clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private :

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nFirst Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nLast Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEmail : ";
		Client.Email = clsInputValidate::ReadEmail();

		cout << "\nPhone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nPinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nAccount Balance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:

	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber = "";
		cout << "\nPlease enter account number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found , please enter another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		char Answer = 'n';
		cout << "\nDo you want to update this client [ y / n ] ?  :  ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\n Update Client Info : ";
			cout << "\n___________________________\n";

			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResults;

			SaveResults = Client.Save();

			switch (SaveResults)
			{
				case clsBankClient::enSaveResults::svSucceeded:
				{
					cout << "\nAccount updated successfully :-)\n";
					_PrintClient(Client);
					break;
				}

				case clsBankClient::enSaveResults::svFailedEmptyObject:
				{
					cout << "\nError account was not saved because it's empty";
					break;
				}

			}
		}

	}

};

