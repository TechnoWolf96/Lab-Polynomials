#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item);
	void DeleteFirst();
};

template<class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	pFirst = pLast = pPrevious = pCurrent = pStop = pHead;
	length = 0;
}

template<class T>
THeadList<T>::~THeadList()
{
	TList<T>::~TList();
	delete pHead;
}

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TList<T>::InsertFirst(item);
	pHead->pNext = pFirst;
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	TList<T>::DeleteFirst();
	pHead->pNext = pFirst;
}