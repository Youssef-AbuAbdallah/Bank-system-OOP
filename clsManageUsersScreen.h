#pragma once
# include <iostream>
# include "clsInputValidate.h"
# include "clsScreen.h"
# include "clsListUsersScreen.h"
# include "clsAddNewUserScreen.h"
# include "clsDeleteUserScreen.h"
# include "clsUpdateUserScreen.h"
# include "clsFindUsersScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:

    enum enManageUsersOptions { enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enMainMenue = 6 };

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static short _ReadManageUsersOption()
    {
        short Choice;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
        return Choice;
    }


    static void _ShowListUsersScreen()
    {
        //cout << "List users will be here";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "add new users will be here";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
       // cout << "delete users will be here";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
       // cout << "update users will be here";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
      //  cout << "find user will be here";
        clsFindUsersScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersOption(enManageUsersOptions Option)
    {
        switch (Option)
        {
            case enManageUsersOptions::enListUsers:
            {
                system("cls");
                _ShowListUsersScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersOptions::enAddNewUser:
            {
                system("cls");
                _ShowAddNewUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersOptions::enDeleteUser:
            {
                system("cls");
                _ShowDeleteUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersOptions::enUpdateUser:
            {
                system("cls");
                _ShowUpdateUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersOptions::enFindUser:
            {
                system("cls");
                _ShowFindUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersOptions::enMainMenue:
            {
               // Do noting as main menue will handle it
            }


        }
    }

public:

	static void ShowManageUsersMenue()
	{
		system("cls");
		_DrawScreenHeader("\tManage Users Screen");

        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n";
        cout << setw(37) << left << "" << clsScreen::WhiteFont << "\t\t\Manage users Menue\n";
        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n" << clsScreen::WhiteFont;
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n" << clsScreen::WhiteFont;

        _PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());
	}

};

