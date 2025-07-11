#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsDepositScreen.h"
# include "clsWithdrawScreen.h"
# include "clsTotalBalancesScreen.h"

using namespace std;

class clsTransacrionsScreen : protected clsScreen 
{
private :

    enum enTransactionsMenueOptions {Deposit = 1 , Withdraw = 2 , TotalBalances = 3 , GoBackToMainMenue = 4};

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4 :  ");
        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }


    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit will be here";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw will be here";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
       // cout << "\n TotalBalances will be here";
        clsTotalBalancesScreen::ShowTotalBalances();
    }



    static void _PerformTransactionsMenuOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
            case enTransactionsMenueOptions::Deposit :
            {
                system("cls");
                _ShowDepositScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::Withdraw :
            {
                system("cls");
                _ShowWithdrawScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::TotalBalances :
            {
                system("cls");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::GoBackToMainMenue:
            {
                // Do nothing as main menue handle it

            }

        }
    }


public :

	static void ShowTransactionsMenue()
	{
		//system("cls");

        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return; // this will rxit the function and will not continue 
        }

		_DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n";
        cout << setw(37) << left << "" << clsScreen::WhiteFont << "\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n" << clsScreen::WhiteFont;
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdarw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n" << clsScreen::WhiteFont;


        _PerformTransactionsMenuOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}

};

