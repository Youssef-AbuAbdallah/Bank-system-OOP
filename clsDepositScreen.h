#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsBankClient.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private :

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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen");

		string AccountNumber;
		cout << "\nPlease enter account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with account number [ " << AccountNumber << " ] is not exist \n";
			cout << "Please enter valid account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		float DepositAmount;
		cout << "Please enter deposit amount : ";
		DepositAmount = clsInputValidate::ReadFloatNumber();

		while (DepositAmount <= 0)
		{
			cout << "\nInvalid amount of deposit , try again with different amount : ";
			DepositAmount = clsInputValidate::ReadFloatNumber();
		}

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this transaction [ y / n ] ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client.Deposit(DepositAmount);
			cout << "\nAmount deposited successfully .\n";
			cout << "\nNew Balance is : " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\nOperation was cancelled .\n";
		}

	}

};

