#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


void TList_Test()
{

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
	for (list.Reset(); k < list.GetLength() - 1; list.GoNext(), k++);
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

void TPolinom_Test()
{
	TPolinom p1;
	p1.AddMonom(TMonom(1, 1, 2, 3));
	p1.AddMonom(TMonom(1, 1, 1, 1));
	cout << "P1 = " + p1.ToString() + '\n';


	TPolinom p2;
	p2.AddMonom(TMonom(1, 1, 2, 3));
	p2.AddMonom(TMonom(-1, 1, 1, 1));
	cout << "P2 = " << p2.ToString() << '\n';
	cout << "P1 + P2 = " << (p1 + p2).ToString();

	cout << "\nP2 * 2 = " << (p2*2).ToString() << '\n';
	cout << "P2 * 2x^2y^2z^2 = " << (p2.MultMonom(TMonom(2, 2, 2, 2))).ToString() << '\n';
	cout << "P1 * P2 = " << (p1 * p2).ToString() << '\n';

	cout << "\n�������� ����� ��������� ����� ������:\n";
	TPolinom p3("1,2x^2y^3z^2 + 1,5y^2z^3 + 1,5y^2z^3 + 0,34x^2 + 130,3242z^1");
	cout << p3.ToString();
}



int main()
{
	setlocale(LC_ALL, "ru");


	TPolinom_Test();
	

}