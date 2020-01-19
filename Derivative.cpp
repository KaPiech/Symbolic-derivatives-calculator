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
	string c;
	c = text;

	struct TreeNode					//drzewo
	{
		int key;
		TreeNode * parent;
		TreeNode * left;
		TreeNode * right;
		char value;
	};

	TreeNode * root = NULL;

	for (int i = c.size()-1; i >= 0; i--)
	{
		TreeNode * w, *p;

		w = new TreeNode;				// nowy wêze³

		w->left = w->right = NULL;		
		w->key = i;						// Wstawiamy klucz.
		w->value = c[i];

		p = root;						// Wyszukujemy miejsce dla w, rozpoczynaj¹c od korzenia

		if (!p)							
			root = w;					
		else
			while (true)              

				if (c[i] == '+' || c[i] == '*' || c[i] == '^' || c[i] == '-' || c[i] == '/')
				{
					if (!p->left)         // Jeœli lewego syna nie ma, 
					{
						p->right = w;       
						break;             
					}
				}
		/*
				if (w->key < p->key)         
				{                      
					if (!p->left)       
					{
						p->left = w;       
						break;             
					}
					else p = p->left;
				}
				else
				{
					if (!p->right)        
					{
						p->right = w;      
						break;             
					}
					else p = p->right;
				}

			w->parent = p;                
		*/
	}
}



void Derivative::calc()			//liczenie pochodnej z ONP
{
	int textsize = text.size();		
	string c, wyj;
	c = text;
	stack <char> temp;
	char a, b, z;

	for (int i = 0; i < textsize; i++)
	{
		temp.push(c[i]);

		if (c[i] == '+' || c[i] == '*' || c[i] == '^' || c[i] == '-' || c[i] == '/')
		{
			temp.pop();
			b = temp.top();
			temp.pop();
			a = temp.top();
			temp.pop();

			if (c[i] == '*')			//(a*b)'
			{	
				if (a == 'x' && b == 'x')
				{	
					wyj += '2';
					z = 'x';
				}
				else
					if (a == 'x')
					{
						z = b;
					}
					else
						if (b == 'x')
						{
							z = a;
						}
						else
						{
							z = '0';
						}
				temp.push(z);
				wyj += z;
			}


			if (c[i] == '+')			//(a+b)'
			{
				if (a == 'x' && b == 'x')
				{
					z = '2';
				}
				else
					if (a == 'x')
					{
						z = '1';
					}
					else
						if (b == 'x')
						{
							z = '1';
						}
						else
						{
							wyj = wyj.substr(0, wyj.size());		//poprawiæ !!!!!!!!!!!
							z = b;
						}
				temp.push(z);
				wyj += '+';
				wyj += z;
			}


			if (c[i] == '-')			//(a-b)'
			{
				if (a == 'x' && b == 'x')
				{
					z = '0';
				}
				else
					if (a == 'x')
					{
						wyj += '+';
						z = '1';
					}
					else
						if (b == 'x')
						{	
							wyj += '-';
							z = '1';
						}	 
						else
						{
							//wyj = wyj.substr(0, wyj.size());				//poprawiæ !!!!!!!!!!!
							wyj += '-';
							z = b;
						}
				temp.push(z);
				wyj += z;
			}


			if (c[i] == '^')			//(a^b)'
			{
				if (a == 'x' && b == 'x')
				{	
					wyj += "log(x)+";
					z = '1';
				}
				else
					if (a == 'x')
					{
						wyj += b;
						wyj += "*x^";
						wyj += char(int(b) - 1);
						
					}
					else
						if (b == 'x')
						{
							wyj += a;
							wyj += "^x *log(";
							wyj += a;
							wyj += ')';
						}
						else
						{
							wyj += a;
							wyj += '^';
							wyj += b;
							
						}
				temp.push(z);
				wyj += z;
			}

			if (c[i] == '/')			//(a/b)'
			{
				if (a == 'x' && b == 'x')
				{
					z = '0';
				}
				else
					if (a == 'x')
					{
						wyj += "1/";
						wyj += b;

					}
					else
						if (b == 'x')
						{
							wyj += '-';
							wyj += a;
							wyj +=  "/(x ^ 2)";
							
						}
						else
						{
							wyj += a;
							wyj += '/';
							wyj += b;
						}
				temp.push(z);
				wyj += z;
			}
		}
		
	}
	text = wyj;
}




void Derivative::ONPtoinfix()			//konwersja ONP na infix
{
	stack <string> st;
	string s = text;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'x' || s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		{
			string operators(1, s[i]);
			st.push(operators);
		}
		else
		{
			string operators1 = st.top();
			st.pop();
			string operators2 = st.top();
			st.pop();
			st.push("(" + operators2 + s[i] +
				operators1 + ")");
		}
	}
	text = st.top();
}