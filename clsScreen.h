#pragma once
# include <iostream>
# include "clsUser.h"
# include "Global.h"
# include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

   static string GreenFont ;
   static string WhiteFont ;
   static string RedFont   ;

	static void _DrawScreenHeader(string Title, string SubTitle="")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (!SubTitle.empty())
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl;


	}


    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << RedFont<< "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t Access Denied ! Contact your admin";
            cout << RedFont << "\n\t\t\t\t\t______________________________________\n\n"<<WhiteFont;
            return false;
        }
        else
        {
            return true;
        }
    }

};

