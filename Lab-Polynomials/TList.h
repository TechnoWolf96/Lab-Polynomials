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
	void InsertCurrent(T item);
	void InsertLast(T item);
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
inline TList<T>::~TList()
{
	while (length != 0) DeleteFirst();
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
inline void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == pFirst) {InsertFirst(); return;}
	if (pCurrent == pLast) { InsertLast(); return; }
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
	delete* pDeletable;
	length--;

}

template<class T>
inline void TList<T>::DeleteCurrent()
{
	if (length == 0) throw "List is empty";
	TNode<T>* pDeletable = pCurrent;
	pCurrent = pCurrent->pNext;
	pPrevious->pNext = pCurrent;
	delete* pDeletable;
	length--;
}



