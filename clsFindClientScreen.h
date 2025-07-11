#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsBankClient.h"
# include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
{
private:

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

public :

	static void ShowFindClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return; // this will rxit the function and will not continue 
		}

		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = "";
		cout << "Please enter client's account number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found , please enter another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);


		if (!Client.IsEmpty()) // validation of the existance of the client 
		{
			cout << "\nClient found :-) " << endl;
		}
		else
		{
			cout << "\nClient wsa not found :-( \n";
		}


		_PrintClient(Client);

	}
};

