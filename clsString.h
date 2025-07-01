#pragma once
# include <iostream>
# include <string>
# include <vector>

using namespace std;

class clsString
{
private:
	string _Value;
	//char _Char;

public:

	vector<string> Vec;

	clsString()
	{
		_Value = "";
	}


	clsString(string Value, char Char)
	{
		_Value = Value;
		//_Char = Char;
	}

	// property set
	void SetValue(string Value)
	{
		_Value = Value;
	}

	// property get
	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	// property set
	/*void SetChar(char Char)
	{
		_Char = Char;
	}*/

	// property get
	/*char GetChar()
	{
		return _Char;
	}*/

	__declspec(property(get = GetChar, put = SetChar)) char Char;



	static short CountWords(string S1, string Delimiter = " ")
	{
		string Word;
		short Counter = 0;
		int pos = 0;

		while ((pos = S1.find(Delimiter)) != std::string::npos)
		{
			Word = S1.substr(0, pos);
			if (!Word.empty())
			{
				Counter++;
			}
			S1.erase(0, pos + Delimiter.size());
		}
		if (!S1.empty())
		{
			Counter++;
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}


	static string ReadString()
	{
		string Line;
		getline(cin >> ws, Line);
		return Line;
	}

	static char ReadChar()
	{
		char ch;
		cin >> ch;
		return ch;
	}



	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		cout << "First Letter of the string \"" << S1 << "\" is : " << endl;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstLetter)
			{
				cout << S1[i] << endl;
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}


	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(this->_Value);
	}


	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(this->_Value);
	}


	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}


	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}


	static char InvertCharacterCase(char ch)
	{
		if (isupper(ch))
		{
			return tolower(ch);
		}
		else if (islower(ch))
		{
			return toupper(ch);
		}
		else
		{
			return ch;
		}
	}

	/*char InvertCharacterCase()
	{
		return InvertCharacterCase(_Char);
	}*/

	static string InvertAllLetterCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertCharacterCase(S1[i]);
		}
		return S1;
	}

	void InvertAllLetterCase()
	{
		_Value = InvertAllLetterCase(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}


	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}


	//static short CountLetter(string Word, char ch)
	//{
	//	short Counter = 0;
	//	for (int i = 0; i < Word.length(); i++)
	//	{
	//		if (Word[i] == ch)
	//		{
	//			Counter++;
	//		}
	//	}
	//	return Counter;
	//}

	//


	static short CountSpecificLetter(string Word, char ch, bool MatchCase = true)
	{
		short Counter = 0;
		for (int i = 0; i < Word.length(); i++)
		{
			if (MatchCase)
			{
				if (Word[i] == ch)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(Word[i]) == tolower(ch))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char ch, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, ch, MatchCase);
	}


	static bool IsVowel(char ch)
	{
		ch = tolower(ch);
		return (ch == 'e' || ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u');
	}

	/*bool IsVowel()
	{
		return IsVowel(_Char);
	}*/

	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintVowels(string S)
	{
		for (int i = 0; i < S.length(); i++)
		{
			if (IsVowel(S[i]))
			{
				cout << S[i] << " ";
			}
		}
	}

	void PrintVowels()
	{
		PrintVowels(_Value);
	}

	static void PrintEachWordInALineFromAString(string S1, string Delimiter = " ")
	{
		string Word;
		short Counter = 0;
		int pos = 0;

		while ((pos = S1.find(Delimiter)) != std::string::npos)
		{
			Word = S1.substr(0, pos);
			if (!Word.empty())
			{
				cout << Word << endl;
			}
			S1.erase(0, pos + Delimiter.size());
		}
		if (!S1.empty())
		{
			cout << S1 << endl;
		}
	}

	void PrintEachWordInALineFromAString()
	{
		PrintEachWordInALineFromAString(_Value);
	}



	static vector <string> SplitString(string S, string Delimiter = " ")
	{
		string Word;
		short pos = 0;
		vector <string> Vec;

		while ((pos = S.find(Delimiter)) != std::string::npos)
		{
			Word = S.substr(0, pos);
			if (!Word.empty())
			{
				Vec.push_back(Word);
			}
			S.erase(0, pos + Delimiter.size());
		}
		if (!S.empty())
		{
			Vec.push_back(S);
		}
		return Vec;
	}

	vector <string> SplitString()
	{
		return SplitString(this->Value);
	}


	static string TrimRight(string S)
	{
		for (int i = S.length() - 1; i >= 0; i--)
		{
			if (S[i] != ' ')
			{
				return S.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}



	static string TrimLeft(string S)
	{
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
			{
				return S.substr(i, S.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string Trim(string S)
	{
		return TrimLeft(TrimRight(S));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> Vec, string Delimiter = " ")
	{
		string S = "";
		for (string& w : Vec)
		{
			S += w + Delimiter;
		}
		return S.substr(0, S.length() - Delimiter.length());
	}

	void JoinString()
	{
		_Value = JoinString(Vec);
	}

	static string ReverseString(string S, string Delimiter = " ")
	{
		vector<string> vec = SplitString(S);
		vector<string>::iterator iter = vec.end();
		string Reversed = "";

		while (iter != vec.begin())
		{
			iter--;
			Reversed += *iter + Delimiter;
		}

		//for (int i = vec.size() - 1; i >= 0; i--)
		//{
		//	Reversed += vec[i] + Delimiter;
		//}
		//
		return Reversed.substr(0, Reversed.length() - Delimiter.length());
	}

	void ReverseString()
	{
		_Value = ReverseString(_Value);
	}

	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos;
		while ((pos = S1.find(StringToReplace)) != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
		}
		return S1;
	}

	void ReplaceWordInStringUsingBuiltInFunction(string StringToReplace, string sRepalceTo)
	{
		_Value = ReplaceWordInStringUsingBuiltInFunction(this->Value, StringToReplace, sRepalceTo);
	}

	static string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = SplitString(S1, " ");
		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}

	void ReplaceWordInStringUsingSplit(string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		_Value = ReplaceWordInStringUsingSplit(_Value, StringToReplace, sRepalceTo, MatchCase);
	}

	static string RemovePunctuationsFromString(string S1)
	{
		string S2 = "";
		for (int i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}

	void RemovePunctuationsFromString()
	{
		_Value = RemovePunctuationsFromString(_Value);
	}

};

