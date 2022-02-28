#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom& operator=(TPolinom& other);

	void AddMonom(TMonom newMonom);
	TPolinom operator+(TPolinom& other);

	string ToString();
};

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{
	TMonom m;

	m.coef = 0;

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

TPolinom TPolinom::operator+(TPolinom& other)
{
	TPolinom result(other);

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurrentItem();
		result.AddMonom(m);
	}
	return result;
}


inline string TPolinom::ToString()
{
	string result;
	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom monom = GetCurrentItem();
		result += '(' + to_string(monom.coef);
		if (monom.degX != 0) result += "x^" + to_string(monom.degX);
		if (monom.degY != 0) result += "y^" + to_string(monom.degY);
		if (monom.degZ != 0) result += "z^" + to_string(monom.degZ);
		result += ')';
		if (pCurrent->pNext != pStop) result += '+';
		
	}
	return result;
}
