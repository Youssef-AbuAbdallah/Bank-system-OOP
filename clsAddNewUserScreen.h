#pragma once
# include <iostream>
# include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
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

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full access ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n";

		cout << "\nShow Client List ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}


		cout << "\nUpdate Client ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Clients ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users ? [ y / n ] : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;

	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName :";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName :";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email :";
		User.Email = clsInputValidate::ReadEmail();

		cout << "\nEnter Phone :";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password :";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions :";
		User.Permission = _ReadPermissionsToSet();

	}

public :

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\tAdd New User Screen");

		string UserName = "";
		cout << "Please enter user name : ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "User alreay exisits , try another username : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults Results = NewUser.Save();

		switch (Results)
		{
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser added successfully :-) \n";
				_PrintUser(NewUser);
				break;
			}
			case  clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nFailed because user is empty ! ";
				break;
			}
			case  clsUser::enSaveResults::svFaildUserExists:
			{
				cout << "\nFailed because user is already exists ! ";
				break;
			}

		}

	}

};

