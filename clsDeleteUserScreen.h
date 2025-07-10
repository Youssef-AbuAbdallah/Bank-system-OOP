#pragma once
#include "clsScreen.h"
# include <iostream>
# include <fstream>
# include "clsInputValidate.h"
# include "clsPerson.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

private :

	static void _PrintUser(clsUser User)
	{

		cout << "\n\tUser Card : ";
		cout << "\n\t___________________";
		cout << "\n\tFirstName   : " << User.FirstName;
		cout << "\n\tLastName    : " << User.LastName;
		cout << "\n\tFull Name   : " << User.FullName();
		cout << "\n\tEmail       : " << User.Email;
		cout << "\n\tPhone       : " << User.Phone;
		cout << "\n\tUserName    : " << User.UserName;
		cout << "\n\tPassword    : " << User.Password;
		cout << "\n\tPermissions  : " << User.Permission;
		cout << "\n\t___________________\n" << endl;
	}

public :

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen");

		string UserName;

		cout << "\nPlease enter username : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found , enter another username : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char Answer = 'n';
		cout << "Are you sure you want to delete this User ? [ y / n ] : ";
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted successfully :-)\n";
				_PrintUser(User);
			}
			else
			{
				cout << "Error User was NOT deleted, try agagin \n";
			}

		}
		else
		{
			cout << "\n\tOperation canceled \n";
		}

	}

};

