#pragma once
#include "Derivative.h"
#include <string>
#include <stack>

using namespace std;


void Derivative::infixtoONP()
{
	int textsize = text.size();		//dlugosc stringa

	//wyra¿enie na ONP
	const char znaki[5]{ '+','*','^','-','/' };
	string s, wyj;
	s = text;
	stack <char> stos;
	stack <int> kontr;

	for (int i = 0; i < textsize; i++)
	{
		if (s[i] == 'x' || s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') { wyj += s[i]; }
		else if (s[i] == '(') stos.push(s[i]);	//2
		else if (s[i] == ')')	//3
		{
			while (stos.top() != '(')
			{
				wyj += stos.top();
				stos.pop();
			}
			stos.pop();
		}
		else	//4
		{
			for (int j = 0; j < 5; j++)
			{
				if (s[i] == znaki[j])
				{
					if (kontr.size() == 0 || (j % 2 == 1 && kontr.top() % 2 != 1)) { stos.push(znaki[j]); kontr.push(j); }
					else
					{
						while (stos.size() != 0 && kontr.size() != 0)
						{
							wyj += stos.top();
							stos.pop();
							kontr.pop();
						}//koniec while
						stos.push(znaki[j]);
					}//koniec else
				}//koniec if
			}//koniec for j
		}//koniec else
	}//koniec for i
	while (stos.size() != 0)
	{
		wyj += stos.top();
		stos.pop();
	}
	text = wyj;
	//koniec konwersji
}

void Derivative::ONPtoinfix()
{

}


void Derivative::calc()
{

}
