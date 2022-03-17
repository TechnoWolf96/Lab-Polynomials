#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>

const int nonDisplayedZeros = 4; // Количество неотображаемых нулей при выводе коэффициента полинома
								 // Кол-во символов после запятой = 6 - nonDisplayedZeros


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(string str);
	TPolinom& operator=(TPolinom& other);

	void AddMonom(TMonom newMonom);
	TPolinom MultMonom(TMonom monom);

	TPolinom operator+(TPolinom& other);
	TPolinom AddPolinom(TPolinom& other);
	TPolinom operator*(double coef);
	TPolinom operator* (TPolinom& other);
	bool operator==(TPolinom& other);

	string ToString();
};

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{
	TMonom m;

	m.coef = 1;

	m.degX = m.degY = 0, m.degZ = -1;
	pHead->value = m;
}

TPolinom::TPolinom(TPolinom& other)
{
	TMonom m(1, 0, 0, -1);
	pHead->value = m;
	for (other.Reset(); !other.IsEnd(); other.GoNext())
	{
		InsertLast(other.GetCurrentItem());
	}
}

inline TPolinom::TPolinom(string str)
{	
	int i = 0;
	
	while (i < str.length())
	{
		if (str[i] == ' ' || str[i] == '+') {i++; continue;}
		string coef;
		for (; isdigit(str[i]) || str[i] == ' ' || str[i] == ',' || str[i] == '-'; i++)
		{
			if (str[i] == ' ') continue;
			coef.push_back(str[i]);
		}
		string degX;
		if (str[i] == 'x')
		{
			i += 2;
			while (isdigit(str[i]))
			{
				degX.push_back(str[i]);
				i++;
			}
		}
		string degY;
		if (str[i] == 'y')
		{
			i += 2;
			while (isdigit(str[i]))
			{
				degY.push_back(str[i]);
				i++;
			}
		}
		string degZ;
		if (str[i] == 'z')
		{
			i += 2;
			while (isdigit(str[i]))
			{
				degZ.push_back(str[i]);
				i++;
			}
		}
		double _coef = 1; int _degX = 0, _degY = 0, _degZ = 0;
		if (!coef.empty()) _coef = stod(coef);
		if (!degX.empty()) _degX = stoi(degX);
		if (!degY.empty()) _degY = stoi(degY);
		if (!degZ.empty()) _degZ = stoi(degZ);
		AddMonom(TMonom(_coef, _degX, _degY, _degZ));
	}
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
	while (pFirst != pStop)
	{
		TNode<TMonom>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	pFirst = pLast = pPrevious = pCurrent = pStop = pHead;
	length = 0;

	for (other.Reset(); !other.IsEnd(); other.GoNext())
	{
		AddMonom(other.GetCurrentItem());
	}
	return *this;
}

void TPolinom::AddMonom(TMonom m)
{
	Reset();
	while (m < pCurrent->value)
	{
		GoNext();
	}
	if (pCurrent->value == m)
	{
		pCurrent->value.coef += m.coef;
		if (pCurrent->value.coef == 0)
		{
			DeleteCurrent();
		}
	}
	else
	{
		InsertCurrent(m);
	}
}

inline TPolinom TPolinom::MultMonom(TMonom monom)
{
	TPolinom result;
	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom resultMonom = GetCurrentItem();
		resultMonom.coef *= monom.coef;
		resultMonom.degX += monom.degX;
		resultMonom.degY += monom.degY;
		resultMonom.degZ += monom.degZ;
		result.AddMonom(resultMonom);
	}
	return result;
}

TPolinom TPolinom::operator+(TPolinom& other)
{
	TPolinom result(other);
	Reset(); result.Reset();

	while (!IsEnd())
	{
		if (result.pCurrent->value > pCurrent->value)
		{
			result.GoNext();
		}
		else if (result.pCurrent->value < pCurrent->value)
		{
			result.InsertCurrent(pCurrent->value);
			GoNext();
		}
		else
		{
			result.pCurrent->value.coef += pCurrent->value.coef;
			if (result.pCurrent->value.coef == 0)
			{
				result.DeleteCurrent();
				GoNext();
			}
			else
			{
				result.GoNext();
				GoNext();
			}
		}
	}
	return result;
}

inline TPolinom TPolinom::AddPolinom(TPolinom& other)
{
	TPolinom result(other);
	for (Reset(); !IsEnd(); GoNext())
		result.AddMonom(GetCurrentItem());
	return result;
}

inline TPolinom TPolinom::operator*(double coef)
{
	TPolinom result(*this);
	for (Reset(), result.Reset(); !IsEnd(); GoNext(), result.GoNext())
	{
		TMonom currentMonom = GetCurrentItem();
		currentMonom.coef *= coef;
		result.SetCurrentItem(currentMonom);
	}
	return result;
}

inline TPolinom TPolinom::operator*(TPolinom& other)
{
	TPolinom result;
	for (other.Reset(); !other.IsEnd(); other.GoNext())
		result = result + MultMonom(other.GetCurrentItem());
	return result;
}

inline bool TPolinom::operator==(TPolinom& other)
{
	if (GetLength() != other.GetLength()) return false;
	for (Reset(), other.Reset(); !IsEnd(); GoNext(), other.GoNext())
		if (!GetCurrentItem().EqualCoef(other.GetCurrentItem())) return false;
	return true;
}


inline string TPolinom::ToString()
{
	string result;
	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom monom = GetCurrentItem();
		string coef = to_string(monom.coef);
		for (int i = 0; i < nonDisplayedZeros; i++) 
			coef.pop_back();

		result += ' ' + coef;
		if (monom.degX != 0) result += "x^" + to_string(monom.degX);
		if (monom.degY != 0) result += "y^" + to_string(monom.degY);
		if (monom.degZ != 0) result += "z^" + to_string(monom.degZ);
		result += ' ';
		if (pCurrent->pNext != pStop) result += '+';
		
	}
	return result;
}
