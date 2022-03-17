#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst, * pCurrent, * pPrevious, * pLast, * pStop;
	int length;
public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty();
	void InsertFirst(T item);
	void InsertCurrent(T item);
	void InsertLast(T item);
	void DeleteFirst();
	void DeleteCurrent();

	void GoNext();
	void Reset();
	bool IsEnd();
	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }


};
template <class T>
TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pLast = pPrevious = pCurrent = pStop;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
	while (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template <class T>
bool TList<T>::IsEmpty()
{
	return pFirst == pStop;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->value = item;
	newNode->pNext = pFirst;
	pFirst = newNode;
	length++;
	if (length == 1)
		pLast = pFirst;
}

template <class T>
void TList<T>::InsertLast(T item)
{
	if (length > 0)
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value = item;
		newNode->pNext = pStop;

		pLast->pNext = newNode;
		pLast = newNode;
		length++;
	}
	else
	{
		InsertFirst(item);
	}
}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == pFirst)
	{
		InsertFirst(item);
		pPrevious = pFirst;
	}
		
	else if (pPrevious == pLast)
	{
		InsertLast(item);
		pPrevious = pLast;
	}
		
	else
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value = item;

		newNode->pNext = pCurrent;
		pPrevious->pNext = newNode;
		pCurrent = newNode;
		length++;
	}
}

template <class T>
void TList<T>::DeleteFirst()
{
	if (pFirst == pStop)
		throw "Can't delete element from empty list";

	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	length--;
}

template <class T>
void TList<T>::DeleteCurrent()
{
	if (pCurrent == pStop)
		throw "Can't delete element from empty list";

	if (pFirst == pCurrent)
	{
		DeleteFirst();
		pPrevious = pStop;	// After delete first element pPrevious was null
		pCurrent = pFirst;
	}
	else
	{
		TNode<T>* tmp = pCurrent;
		pCurrent = pCurrent->pNext;
		pPrevious->pNext = pCurrent;
		delete tmp;
		length--;
	}
}

template <class T>
T TList<T>::GetCurrentItem()
{
	if (pCurrent == pStop)
		throw "List is end";
	return pCurrent->value;
}

template <class T>
void TList<T>::Reset()
{
	pPrevious = pStop;
	pCurrent = pFirst;
}

template <class T>
void TList<T>::GoNext()
{
	pPrevious = pCurrent;
	pCurrent = pCurrent->pNext;
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurrent == pStop;
}





