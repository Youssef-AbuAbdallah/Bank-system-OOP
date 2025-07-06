# include <iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsBankClient.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\tWithdraw Screen");

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

		float WithdrawAmount;
		cout << "\nPlease enter withdraw amount : ";
		WithdrawAmount = clsInputValidate::ReadFloatNumber();

		while (WithdrawAmount > Client.AccountBalance)
		{
			cout << "\nWithdraw amount can't exceed the account balance \n";
			cout << "You can withdraw up to : " << Client.AccountBalance << endl;
			cout << "Please enter withdraw amount : ";
			WithdrawAmount = clsInputValidate::ReadFloatNumber();
		}

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this transaction [ y / n ] ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if(Client.Withdraw(WithdrawAmount))
			{
				cout << "\nAmount withdrawed successfully .\n";
				cout << "\nNew Balance is : " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "\nCannot Withdraw , Insuffecient Balance as withdraw amount can't exceed the account balance \n";
				cout << "Amount to withdraw : " << WithdrawAmount << endl;
				cout << "Your Balance : " << Client.AccountBalance << endl;
			}
			
		}
		else
		{
			cout << "\nOperation was cancelled .\n";
		}

	}

};

