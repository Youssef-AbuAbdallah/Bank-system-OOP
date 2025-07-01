#pragma once
# include <iostream>
# include <string>
# include <limits>
# include "clsDate.h"

using namespace std;


class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1BeforeDate2(DateTo, DateFrom))
		{
			clsDate::SwapDates(DateTo, DateFrom);
		}

		return ((clsDate::IsDate1EqualDate2(Date, DateFrom) || clsDate::IsDate1AfterDate2(Date, DateFrom))
			&& (clsDate::IsDate1EqualDate2(Date, DateTo) || clsDate::IsDate1BeforeDate2(Date, DateTo)));
	}

	static bool IsStringNumberOutOfRange(string Number, string MinValue, string MaxValue)
	{
		if ((Number.size() > MaxValue.size() && Number[0] != '-') || (Number.size() > MinValue.size()))
		{
			return false;
		}
		else
		{
			// Positive Number 
			if (Number[0] != '-' && Number.size() == MaxValue.size())
			{
				for (int i = 0; i < MaxValue.size(); i++)
				{
					if (Number[i] + '0' > MaxValue[i] + '0')
					{
						return false;
					}
				}
				return true;
			}
			// Negative Number
			else if (Number[0] == '-' && Number.size()== MinValue.size())
			{
				for (int i = 1; i < MinValue.size(); i++)
				{
					if (Number[i] + '0' > MinValue[i] + '0')
					{
						return false;
					}
				}
				return true;
			}
			else
			{
				return true;
			}
			
		}
	}

	static string ReadEmail(string ErrorMessage = "Invalid Email , Please enter another Email : ")
	{
		string Email;
		getline(cin >> ws, Email);
		bool VaildEmail = true;
		do
		{
			if (!VaildEmail)
			{
				cout << ErrorMessage;
				getline(cin >> ws, Email);
				VaildEmail = true;
			}

			short NumberOfAts = 0, NumberOfDots = 0;
			for (int i = 0; i < Email.size(); i++)
			{
				if (!(Email[0] >= 65 || Email[0]<=90) && !(Email[0] >= 97 || Email[0]<=122)) // First character is not an character 
				{
					VaildEmail = false;
					break;
				}

				if (Email[i] == '@')
				{
					NumberOfAts++;
					if (i == Email.size() - 1 || NumberOfAts != 1 || ispunct(Email[i + 1]))
					{
						VaildEmail = false;
						break;
					}
				}

				if (Email[i] == '.')
				{
					NumberOfDots++;
					if (i == Email.size() - 1 || NumberOfDots!=1)
					{
						VaildEmail = false;
						break;
					}
				}
				
				if (i == Email.size() - 1 && (NumberOfDots != 1 || NumberOfAts != 1))
				{
					VaildEmail = false;
					break;
				}

			}
		} while (!VaildEmail);

		return Email;
	}

	static string ReadString()
	{
		string Word;
		getline(cin >> ws, Word);
		return Word;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid integer number , Please enter another number : ")
	{
		string Number;
		short NegativeSign = 0;
		bool Valid = true , InRange = true;
		do
		{
			if (!Valid || !InRange)
			{
				cout << ErrorMessage;
			}
			cin >> Number;
			Valid = true;
			
			// handle non digit characters as invalid
			for (int i=0 ; i<Number.size();i++)
			{
				if (!isdigit(Number[i]))
				{
					if (Number[i] == '-' && i==0)
					{
						NegativeSign++;
						continue;
					}
					Valid = false;
					break;
				}
			}
			InRange = clsInputValidate::IsStringNumberOutOfRange(Number, to_string(INT_MIN), to_string(INT_MAX));
		} while (!Valid || !InRange);
		
		return stoi(Number);
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is out of range!, Please enter another number :")
	{
		int Number;

		Number= clsInputValidate::ReadIntNumber();
		while (!IsNumberBetween(Number , From , To))
		{
			cout << ErrorMessage;
			Number= clsInputValidate::ReadIntNumber();
		}
		return Number;
	}

	static double ReadDoubleNumber(string ErrorMessage = "Invalid double number , Please enter another number : ")
	{
		string Number;
		short NegativeSign = 0 , Dot = 0;
		bool Valid = true, InRange = true;
		do
		{
			if (!Valid || !InRange)
			{
				cout << ErrorMessage;
			}
			cin >> Number;
			Valid = true;

			// handle non digit characters as invalid
			for (int i = 0; i < Number.size(); i++)
			{
				if (!isdigit(Number[i]))
				{
					if (Number[i] == '-' && i == 0)
					{
						NegativeSign++;
						continue;
					}
					if (Number[i] == '.' && i != 0)
					{
						Dot++;
						if (Dot > 1)
						{
							Valid = false;
							break;
						}
						continue;
					}
					Valid = false;
					break;
				}
			}
			//InRange = clsInputValidate::IsStringNumberOutOfRange(Number, to_string(INT_MIN), to_string(INT_MAX));
		} while (!Valid || !InRange);

		return stod(Number);
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid float number , Please enter another number : ")
	{
		string Number;
		short NegativeSign = 0 , Dot = 0;
		bool Valid = true, InRange = true;
		do
		{
			if (!Valid || !InRange)
			{
				cout << ErrorMessage;
			}
			cin >> Number;
			Valid = true;

			// handle non digit characters as invalid
			for (int i = 0; i < Number.size(); i++)
			{
				if (!isdigit(Number[i]))
				{
					if (Number[i] == '-' && i == 0)
					{
						NegativeSign++;
						continue;
					}
					if (Number[i] == '.' && i != 0)
					{
						Dot++;
						if (Dot > 1)
						{
							Valid = false;
							break;
						}
						continue;
					}
					Valid = false;
					break;
				}
			}
			//InRange = clsInputValidate::IsStringNumberOutOfRange(Number, to_string(INT_MIN), to_string(INT_MAX));
		} while (!Valid || !InRange);

		return stof(Number);
	}

	static double ReadDoublelNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDoubleNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDoubleNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};

