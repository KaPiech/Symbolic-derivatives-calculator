#pragma once
#include <string>

using namespace std;

class Derivative
{
public:
	string	text;
	int textsize;

	Derivative() {};

	void calc();
	void infixtoONP();
	void ONPtoinfix();
};