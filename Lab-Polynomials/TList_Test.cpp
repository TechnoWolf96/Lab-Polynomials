#include <iostream>
#include "TList.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");


	TList<int> list;
	cout << "\t===== Тестирование класса TList =====";
	cout << "\n1) Заполним список числами от 0 до 9.";
	for (int i = 0; i < 10; i++) list.InsertFirst(i);
	cout << "\nСписок: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	cout << "\n2) Удалим первый элемент, затем удалим элемент со значением 5.";
	list.DeleteFirst();
	for (list.Reset(); list.GetCurrentItem() != 5; list.GoNext());
	list.DeleteCurrent();
	cout << "\nСписок: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	cout << "\n3) Удалим первый и последний элемент через DeleteCurrent().";
	list.Reset();
	list.DeleteCurrent();
	int k = 0;
	for (list.Reset(); k < list.GetLength()-1; list.GoNext(), k++);
	list.DeleteCurrent();
	cout << "\nСписок: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	cout << "\n4) Присвоим значение 11 третьему элементу и вставим перед ним элемент 10";
	list.Reset();
	for (int i = 1; i < 3; i++) list.GoNext();
	list.SetCurrentItem(11);
	list.InsertCurrent(10);
	cout << "\nСписок: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	
	

}