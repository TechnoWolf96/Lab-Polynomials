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
	bool IsEmpty() { return length == 0; }
	void InsertFirst(T item);
	void InsertCurrent(T item);
	void InsertLast(T item);
	void DeleteFirst();
	void DeleteCurrent();

	void GoNext();
	void Reset();
	bool IsEnd() { return pCurrent == pLast; }
	T GetCurrentItem() { return pCurrent->value; }
	void SetCurrentItem(T item) { pCurrent->value = item; }


};

template<class T>
inline TList<T>::TList()
{
	length = 0;
	pStop = nullptr;
	pFirst = pCurrent = pPrevious = pLast = pStop;
}

template<class T>
inline TList<T>::~TList()
{
	while (!IsEmpty()) DeleteFirst();
}

template<class T>
inline void TList<T>::InsertFirst(T item)
{
	if (IsEmpty()) pCurrent = pFirst;
	TNode<T>* newNode = new TNode<T>();
	newNode->value = item;
	newNode->pNext = pFirst;
	pFirst = newNode;
	if (IsEmpty()) pLast = pFirst;
	length++;
}

template<class T>
inline void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == pFirst) {InsertFirst(item); return;}
	if (pCurrent == pLast) { InsertLast(item); return; }
	TNode<T>* newNode = new TNode<T>();
	newNode->value = item;
	newNode->pNext = pCurrent;
	pPrevious->pNext = newNode;
	length++;
}

template<class T>
inline void TList<T>::InsertLast(T item)
{
	if (IsEmpty()) { InsertFirst(item); return; }
	TNode<T>* newNode = new TNode<T>();
	newNode->value = item;
	newNode->pNext = nullptr;
	pLast->pNext = newNode;
	length++;
}

template<class T>
inline void TList<T>::DeleteFirst()
{
	if (length == 0) throw "List is empty";
	TNode<T>* pDeletable = pFirst;
	pFirst = pFirst->pNext;
	delete pDeletable;
	length--;

}

template<class T>
inline void TList<T>::DeleteCurrent()
{
	if (length == 0) throw "List is empty";
	TNode<T>* pDeletable = pCurrent;
	pCurrent = pCurrent->pNext;
	pPrevious->pNext = pCurrent;
	delete pDeletable;
	length--;
}

template<class T>
inline void TList<T>::GoNext()
{
	if (IsEnd()) throw "Iterator is already at the end";
	pPrevious = pCurrent;
	pCurrent = pCurrent->pNext;
}

template<class T>
inline void TList<T>::Reset()
{
	pPrevious = pStop;
	if (!IsEmpty()) pCurrent = pFirst;
	else pCurrent = pStop;
}






