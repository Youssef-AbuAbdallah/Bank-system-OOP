#pragma once
# include <iostream>
#include "clsScreen.h"
# include "clsBankClient.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private :

	static void PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << "\t| " << left << setw(15) << Client.AccountNumber();
		cout << "\t| " << left << setw(30) << Client.FullName();
		cout << "\t| " << left << setw(15) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t   Balances List Screen";
		string SubTitle = "\t   ( " + to_string(vClients.size()) + " ) Client(s)";

		_DrawScreenHeader(Title, SubTitle);
		
		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "\t| " << left << setw(30) << "Client Name";
		cout << "\t| " << left << setw(15) << "Balance";

		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t\tNo Clients Available in the system!" << endl;
		}

		else
		{
			for (clsBankClient& Client : vClients)
			{
				PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}

		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		float TotalBalances = clsBankClient::GetTotalBalances();

		cout << "\n\t\t\tTotal Balances = " << TotalBalances << endl;

		cout << "\t\t( " << clsUtil::NumberToText((int)TotalBalances) << " ) " << endl;
	}
};

