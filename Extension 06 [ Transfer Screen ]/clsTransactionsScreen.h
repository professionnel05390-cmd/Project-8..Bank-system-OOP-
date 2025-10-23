#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
	enum enTransactionsMenueOptions
	{
		eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eTransfer = 4, eShowMainMenue = 5
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
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
		// cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		cout << "\n Withdraw Screen will be here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		// cout << "\n Balances Screen will be here.\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eShowTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;

		case clsTransactionsScreen::eShowMainMenue:
			// Do Nothing here, the Main Screen will handle it :-)
			break;
		}
	}

public:

	static void ShowTransactionsMenue()
	{
		system("cls");
		if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;  // this will exit the function and it will not continue
		}
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformTransactionsMenueOption(enTransactionsMenueOptions(_ReadTransactionsMenueOption()));
	}
};

