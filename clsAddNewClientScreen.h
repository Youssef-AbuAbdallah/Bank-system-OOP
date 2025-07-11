#pragma once
#include <iostream>
#include "clsScreen.h"
# include "clsBankClient.h"
# include <iomanip>
# include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
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
	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return; // this will rxit the function and will not continue 
		}

		_DrawScreenHeader("\t  Add New Client Screen");

		cout << "\n Please enter account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Alreay exsisting account number , please try another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
			case  clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Addeded Successfully :-)\n";
				_PrintClient(NewClient);
				break;
			}
			case clsBankClient::enSaveResults::svFailedEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}
			case clsBankClient::enSaveResults::svFailedAccountNumberExists:
			{
				cout << "\nError account was not saved because account number is used!\n";
				break;

			}
		}
	}
};

