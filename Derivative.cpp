#pragma once
#include "Derivative.h"
#include <string>
#include <stack>

using namespace std;


void Derivative::infixtoONP()		//konwersja infix na ONP
{
	int textsize = text.size();		//dlugosc stringa


	const char operators[5]{ '+','*','^','-','/' };
	string s, wyj;
	s = text;
	stack <char> stos;
	stack <int> kontr;

	for (int i = 0; i < textsize; i++)
	{
		if (s[i] == 'x' || s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') { wyj += s[i]; }
		else if (s[i] == '(') stos.push(s[i]);
		else if (s[i] == ')')
		{
			while (stos.top() != '(')
			{
				wyj += stos.top();
				stos.pop();
			}
			stos.pop();
		}
		else
		{
			for (int j = 0; j < 5; j++)
			{
				if (s[i] == operators[j])
				{
					if (kontr.size() == 0 || (j % 2 == 1 && kontr.top() % 2 != 1))
					{
						stos.push(operators[j]);
						kontr.push(j);
					}
					else
					{
						while (stos.size() != 0 && kontr.size() != 0)
						{
							wyj += stos.top();
							stos.pop();
							kontr.pop();
						}
						stos.push(operators[j]);
					}
				}
			}
		}
	}

	while (stos.size() != 0)
	{
		wyj += stos.top();
		stos.pop();
	}
	text = wyj;

}


void Derivative::ONPtoTree()		//konwersja ONP na drzewo
{
	/*
	s = text;
	struct Tree
	{
		Tree * up;
		Tree * left;
		Tree * right;
	};


	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'x' || s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		{

		}

	}
	*/

}



void Derivative::calc()		//liczenie pochodnej z ONP
{

}


void Derivative::ONPtoinfix()		//konwersja ONP na infix
{

}