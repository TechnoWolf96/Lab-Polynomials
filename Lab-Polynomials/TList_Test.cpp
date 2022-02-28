#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


void TList_Test()
{

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
	for (list.Reset(); k < list.GetLength() - 1; list.GoNext(), k++);
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

void TPolinom_Test()
{
	TPolinom p1;
	p1.AddMonom(TMonom(1, 1, 2, 3));
	p1.AddMonom(TMonom(1, 1, 1, 1));
	cout << "P1 = " + p1.ToString() + '\n';


	TPolinom p2;
	p1.AddMonom(TMonom(1, 1, 2, 3));
	p2.AddMonom(TMonom(-1, 1, 1, 1));
	cout << "P2 = " << p2.ToString() << '\n';
	TPolinom result;
	result = p1 + p2;
	cout << "P1 + P2 = " << result.ToString();
}



int main()
{
	setlocale(LC_ALL, "ru");


	TPolinom_Test();
	

}