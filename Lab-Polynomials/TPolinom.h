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
	pHead->value = TMonom(0, 0, 0, -1);
}

TPolinom::TPolinom(TPolinom& other) : THeadList<TMonom>::THeadList()
{
	pHead->value = TMonom(0, 0, 0, -1);
	for (other.Reset(); !other.IsEnd(); other.GoNext())
		InsertLast(other.GetCurrentItem());
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
	THeadList::~THeadList();

	pFirst = pLast = pPrevious = pCurrent = pStop = pHead;
	length = 0;

	for (other.Reset(); !other.IsEnd(); other.GoNext())
		AddMonom(other.GetCurrentItem());

	return *this;
}

void TPolinom::AddMonom(TMonom newMonom)
{
	Reset();
	while (newMonom < GetCurrentItem()) GoNext();

	if (GetCurrentItem() == newMonom)
	{
		pCurrent->value.coef += newMonom.coef;
		if (pCurrent->value.coef == 0) 
			DeleteCurrent();
	}
	else InsertCurrent(newMonom);
}

TPolinom TPolinom::operator+(TPolinom& other)
{
	TPolinom result(other);

	for (Reset(); !IsEnd(); GoNext())
		result.AddMonom(GetCurrentItem());

	return result;
}

inline string TPolinom::ToString()
{
	string result;
	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom monom = GetCurrentItem();
		result += to_string(monom.coef);
		if (monom.degX != 0) result += "x^" + to_string(monom.degX);
		if (monom.degY != 0) result += "y^" + to_string(monom.degY);
		if (monom.degZ != 0) result += "z^" + to_string(monom.degZ);
		if (pCurrent->pNext != pStop) result += '+';
	}
	return result;
}
