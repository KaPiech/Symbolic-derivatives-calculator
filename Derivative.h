#pragma once
#include <string>


using namespace std;

class Derivative
{
public:
	string	text;

	Derivative() {};

	void calc();		//liczenie pochodnej z ONP
	void infixtoONP();		//konwersja infix na ONP
	void ONPtoTree();		//konwersja ONP na drzewo
	void ONPtoinfix();		//konwersja ONP na infix
};