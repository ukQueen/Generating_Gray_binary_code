#pragma once
#include "GrayCode.h"
#include <string>



class Multi:public GrayCode
{
	//int m;//мощность  
	int Count; //количество различных элементов в мультимножестве
	vector <int> elems;
	GrayCode* base;
	vector<bool> Show;
public:
	Multi();
	Multi(int a, GrayCode* b, bool flag);
	void Avto();
	void Hand();
	void Print(string s) ;

	void Unification(Multi& a, Multi& b); //объединение
	void Intersection(Multi& a, Multi& b); //пересечение
	void DifferenceA(Multi& a, Multi& b); //разность множеств A и B  |||  
	void Ar_DifferenceA(Multi& a, Multi& b); //Арифметическая разность множеств A и B
	void DifferenceB(Multi& a, Multi& b); //разность множеств B и A
	void Ar_DifferenceB(Multi& a, Multi& b); //Арифметическая разность множеств B и A
	void AdditionA(Multi& a, Multi& b); //Дополнение множества A
	void AdditionB(Multi& a, Multi& b); //Дополнение множества B
	void Sim_Difference(Multi& a, Multi& b); //Симметрическая разность множеств A и B
	void Ar_Summ(Multi& a, Multi& b);//арифметическая сумма А и В
	void Ar_Prod(Multi& a, Multi& b);//арифметическое произведение А и В

};
