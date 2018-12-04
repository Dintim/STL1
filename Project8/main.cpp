#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <Windows.h>
using namespace std;


void main()
{	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");	
	
	int ch;
	cout << "Выберите номер задания: ";
	cin >> ch;

	switch (ch)
	{
	case 1: {
		ifstream infile("stih.txt");
		string s;
		int cntPred = 0;
		int cntWords = 1;
		int cntChars = 0;
		vector<string> str;
		while (!infile.eof()) {
			string str;
			getline(infile, s, '.');
			for (size_t i = 0; i < s.size(); i++)
			{
				str = s.substr(0, s.find(' '));
				cntChars += str.size();
				s = s.substr(s.find(' ') + 1);
				if (s.find(' ') == string::npos)
					cntChars += s.size();
				cntWords++;
			}
			cntPred++;
		}
		cout << "количество предложений: " << cntPred - 1 << endl;
		cout << "количество слов: " << cntWords << endl;
		cout << "средняя длина слова: " << cntChars / cntWords << endl;
		cout << "среднее количество слов в предложении: " << cntWords / (cntPred - 1) << endl;

		infile.close();
	}
		break;
	case 2: {
		ifstream infile("stih.txt");
		string str = "";
		while (!infile.eof()) {
			string strSub;
			getline(infile, strSub);
			str += strSub;
		}
		cout << str << endl;

		string word, anWord;
		cout << "Какое слово заменить в тексте: ";
		cin >> word;
		cout << "На какое слово: ";
		cin >> anWord;

		int ind = str.find(word);
		while (ind != string::npos) {
			str.replace(ind, word.size(), anWord);
			ind = str.find(word);
		}
		cout << str << endl;

		infile.close();
	}
		break;
	default:
		cout << "Выберите 1 или 2\n";
		break;
	}
	
	
	
	
	
	system("pause");
}