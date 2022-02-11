#pragma once
#include "TNode.h"

template<class T>
class TList
{
protected:
	TNode<T>* pFirst, * pCurrent, * pPrevious, * pLast, * pStop;
	int length;
public:
	TList();
	~TList();
	bool IsEmpty() { return length == 0 };
	void InsertFirst(T item);
	void InsertCurrent();
	void InsertLast();
	void DeleteFirst();
	void DeleteCurrent();



};

template<class T>
inline TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pCurrent = pPrevious = pLast = pStop;
}

template<class T>
inline void TList<T>::InsertFirst(T item)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->value = item;
	newNode->pNext = pFirst;
	pFirst = newNode;
	if (IsEmpty()) pLast = pFirst;
	length++;
}

template<class T>
inline void TList<T>::InsertLast()
{

}



