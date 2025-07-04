#pragma once
# include <iostream>
# include "clsString.h"
# include "clsUtil.h"
# include "clsPerson.h"
# include "clsInputValidate.h"
# include <fstream>
# include <iomanip>
class clsBankClient : public clsPerson
{
private :

	enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode = 2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Delimiter = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::SplitString(Line, Delimiter);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line = "";
		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber() + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient>_LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> _vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // overwrite
		string DataLine;
		
		if (MyFile.is_open())
		{
			for (clsBankClient& C : _vClients)
			{
				if (C._MarkForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
				
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();
		}
	}

	void _AddNewClient()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}


	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(25) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(32) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(10) << Client.AccountBalance;
	}

public:

	clsBankClient(enMode Mode , string FirstName , string LastName , string Email , string Phone , string AccountNumber ,
		string PinCode , float AccountBalance) : clsPerson (FirstName , LastName , Email , Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	// Read only property
	string AccountNumber()
	{
		return _AccountNumber;
	}

	//void SetAccountNumber(string AccountNumber)
	//{
	//	_AccountNumber = AccountNumber;
	//}
	//__declspec(property(get = GetAccountNumber, put = SetAccountNumber))string AccountNumber ;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	//void Print()
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FirstName;
	//	cout << "\nLastName    : " << LastName;
	//	cout << "\nFull Name   : " << FullName();
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc. Number : " << AccountNumber();
	//	cout << "\nPassword    : " << _PinCode;
	//	cout << "\nBalance     : " << _AccountBalance;
	//	cout << "\n___________________\n";

	//}

	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nFirst Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nLast Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEmail : ";
		Client.Email = clsInputValidate::ReadEmail();

		cout << "\nPhone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nPinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nAccount Balance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static clsBankClient Find(string AccountNumber) 
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // Read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode) // Deal with as a login 
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // Read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1 , svFailedAccountNumberExists = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFailedEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
				break;
			}
			else
			{
				_AddNewClient();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		}
	}

	static void UpdateClient()
	{
		string AccountNumber = "";
		cout << "\nPlease enter account number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = Find(AccountNumber);

		Client.Print();

		cout << "\n\n Update Client Info : ";
		cout << "\n___________________________\n";

		ReadClientInfo(Client);

		enSaveResults SaveResults;

		SaveResults = Client.Save();

		switch (SaveResults)
		{
		case enSaveResults::svSucceeded :
		{
			cout << "\nAccount updated successfully :-)\n";
			Client.Print();
			break;
		}

		case enSaveResults::svFailedEmptyObject :
		{
			cout << "\nError account was not saved because it's empty";
			break;
		}

		}

	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static void AddNewClient()
	{
		cout << "\nPlease enter account number : ";
		string AccountNumber = clsInputValidate::ReadString();
		
		while (IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is already used , choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = GetAddNewClientObject(AccountNumber);

		ReadClientInfo(NewClient);

		enSaveResults SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case enSaveResults::svSucceeded:
		{
			cout << "\nAccount added successfully :-)\n";
			NewClient.Print();
			break;
		}

		case enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's empty";
			break;
		}

		case enSaveResults::svFailedAccountNumberExists:
		{
			cout << "\nError because account number already in use \n";
			break;
		}

		}

	}

	bool Delete()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static void DeleteClient()
	{
		string AccountNumber = "";
		cout << "\nPlease enter account number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = Find(AccountNumber);

		Client.Print();

		cout << "\nAre you sure you want to delete this client y/n ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted successfully " << endl;
				Client.Print();
			}
			else
			{
				cout << "\nError while deleting the client ! " << endl;
			}
		}


	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}


	static void ShowClientsList()
	{
		vector<clsBankClient> vClients = GetClientsList();

		// Print Header
		cout << "\n\t\t\t\tClient List ( " << vClients.size() << " ) Client (s)";
		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "AccountNumber";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(32) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(10) << "Balance";
		
		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\tNo Clients Availabe In The System ! " << endl;
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}

			cout << "\n______________________________________________________________";
			cout << "_________________________________________________________\n" << endl;
		}
	}

	static float GetTotalBalances()
	{
		vector<clsBankClient> vClients = GetClientsList();
		float TotalBalances = 0;
		for (clsBankClient &Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	static void PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(15) << Client.AccountBalance;
	}

	static void ShowTotalBalances()
	{
		vector<clsBankClient> vClients = GetClientsList();
		cout << "\n\t\t\t\tBalances List ( " << vClients.size() << " ) Client (s)";
		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;
		
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(15) << "Balance";

		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		for (clsBankClient& Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

		cout << "\n______________________________________________________________";
		cout << "_________________________________________________________\n" << endl;

		float TotalBalances = GetTotalBalances();

		cout << "\n\t\t\tTotal Balances = " << TotalBalances << endl;

		cout << "\t\t( " << clsUtil::NumberToText((int)TotalBalances) << " ) " << endl;
	}
};

