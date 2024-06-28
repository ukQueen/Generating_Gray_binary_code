#pragma once
#include "GrayCode.h"
#include <string>



class Multi:public GrayCode
{
	//int m;//��������  
	int Count; //���������� ��������� ��������� � ���������������
	vector <int> elems;
	GrayCode* base;
	vector<bool> Show;
public:
	Multi();
	Multi(int a, GrayCode* b, bool flag);
	void Avto();
	void Hand();
	void Print(string s) ;

	void Unification(Multi& a, Multi& b); //�����������
	void Intersection(Multi& a, Multi& b); //�����������
	void DifferenceA(Multi& a, Multi& b); //�������� �������� A � B  |||  
	void Ar_DifferenceA(Multi& a, Multi& b); //�������������� �������� �������� A � B
	void DifferenceB(Multi& a, Multi& b); //�������� �������� B � A
	void Ar_DifferenceB(Multi& a, Multi& b); //�������������� �������� �������� B � A
	void AdditionA(Multi& a, Multi& b); //���������� ��������� A
	void AdditionB(Multi& a, Multi& b); //���������� ��������� B
	void Sim_Difference(Multi& a, Multi& b); //�������������� �������� �������� A � B
	void Ar_Summ(Multi& a, Multi& b);//�������������� ����� � � �
	void Ar_Prod(Multi& a, Multi& b);//�������������� ������������ � � �

};
