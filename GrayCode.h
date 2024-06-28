#pragma once
#include"Adds.h"
class GrayCode
{
protected:
	int n;// разрядность 
	int k;//элементов (2^n)
	int Count;//количество различных элементов
	vector <int> Codes;
	vector <int> Krat;
public:
	GrayCode();
	GrayCode(int a);
	int Getk();
	 void Print();
	//void ToNull(int a);
	int Getn();
	int GetCount();
	vector <int> GetKrat();
	vector<int> GetCodes();
};

