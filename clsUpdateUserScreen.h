#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private :

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLoginRegisterScreen;
        }

        return Permissions;

    }

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

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadEmail();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permission = _ReadPermissionsToSet();
	}

public :

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");

		cout << "Please enter username : ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found , enter another username : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char Answer = 'n';
		cout << "Are you sure you want to Update this User ? [ y / n ] : ";
		cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User);

            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult)
            {
                case  clsUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Updated Successfully :-)\n";

                    _PrintUser(User);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;

                }
            }
        }
        else
        {
            cout << "\n\tOperation canceled \n";
        }
	}

};

