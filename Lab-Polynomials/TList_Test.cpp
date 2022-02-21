#include <iostream>
#include "TList.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");


	TList<int> list;
	cout << "\t===== ������������ ������ TList =====";
	cout << "\n1) �������� ������ ������� �� 0 �� 9.";
	for (int i = 0; i < 10; i++) list.InsertFirst(i);
	cout << "\n������: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	cout << "\n2) ������ ������ �������, ����� ������ ������� �� ��������� 5.";
	list.DeleteFirst();
	for (list.Reset(); list.GetCurrentItem() != 5; list.GoNext());
	list.DeleteCurrent();
	cout << "\n������: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	cout << "\n3) ������ ������ � ��������� ������� ����� DeleteCurrent().";
	list.Reset();
	list.DeleteCurrent();
	int k = 0;
	for (list.Reset(); k < list.GetLength()-1; list.GoNext(), k++);
	list.DeleteCurrent();
	cout << "\n������: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	cout << "\n4) �������� �������� 11 �������� �������� � ������� ����� ��� ������� 10";
	list.Reset();
	for (int i = 1; i < 3; i++) list.GoNext();
	list.SetCurrentItem(11);
	list.InsertCurrent(10);
	cout << "\n������: ";
	for (list.Reset(); !list.IsEnd(); list.GoNext()) 
		cout << list.GetCurrentItem() << " ";
	
	

}