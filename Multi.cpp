#include "Multi.h"
#include <regex>
Multi::Multi(int a, GrayCode* b, bool flag) {
	//m = a;
	Count = a;
	base = b;
		elems.resize(base->Getk(), 0);
		Show.resize(base->Getk(), 0);

	if (base->Getk() != 0 && flag) {

		regex powerful("^[0-9]{0,50}$");

		printf("Хотите ли вы конкретные ненулевые значения - [1], или же их выбрать автоматически - [0]?\n");
		string s;
		while (true) {
			cin >> s;
			if (s == "0" or s == "1")
				break;
			else printf("\nВведите либо [1] либо [0]\n");
		}
		if (stoi(s) == 1) {
			printf("\nВводите по одному элементы\n");
			for (int i = 0; i < Count; i++) {
				cin >> s;
				if (regex_match(s, powerful) && stoi(s) >= 0 && stoi(s) < this->base->Getk()) {
					if (Show[stoi(s)] == 1) {
						printf("Ну зачем же вы пишете повторяющийся элемент?\n");
						i--;
					}
					else
						Show[stoi(s)] = 1;
				}
				else {
					std::cout << "Ошибка ввода!\n";
					i--;

				}
			}
		}
		else {
			srand(time(0));
			for (int i = 0; i < Count; i++) {
				int r = rand() % base->Getk();
				if (Show[r] == 1)
					i--;
				else {
					Show[r] = 1;
				}
			}
		}
	}
}




Multi::Multi() {}

void Multi::Avto() {
	srand(time(0));
	for (int i = 0; i < base->Getk(); i++) {
		if (Show[i] != 0) {
				int r = rand() % base->GetKrat()[i];
					elems[i] = r;
		}
	}
	
}


void Multi::Print(string s) {
	printf("\n||||||||||||||||||||||||||||||||");
	cout << "\n    "<<s<<"\n\n";
	bool flag = 1;
	for (int i = 0; i < base->Getk(); i++) {
		if (Show[i] != 0) {
			cout << "   ";
			for (int j = 0; j < base->Getk() * base->Getn(); j += base->Getk()) {
				cout << "  " << (base->GetCodes().at(i+j));
				flag = 0;
			}

			cout << "  [" << i << "]"<< " :  " << elems[i] << "\n";
		}
	}
	if (flag)
		printf("Пустое множество\n");
	printf("\n||||||||||||||||||||||||||||||||\n");
}

void Multi::Hand() {

	cout << "\n-----------------------------------";
	cout << "\nВы решили заполнить массив вручную\n\n";

	srand(time(0));

	for (int i = 0; i < base->Getk(); i++) {
		if (Show[i] != 0) {
			cout << "Какая кратность будет у этого числа? ";
			for (int j = 0; j < base->Getn(); j++) {
				cout << base->GetCodes()[i + j * base->Getk()]  ;
			}
			cout <<" ["<<i<<"]: "<< base->GetKrat()[i]<<"\n";
			string bit;
			regex powerful("^[0-9]{0,50}$");
			while (true) {
				cin >> bit;
				if (regex_match(bit, powerful) && stoi(bit) >= 0 && stoi(bit) <= this->base->GetKrat()[i]) {
					break; // Ввод соответствует регулярному выражению, выходим из цикла
				}
				else {
					std::cout << "Ошибка ввода!\n";
				}
			}
				elems[i] = stoi(bit);

		}
	}

	/*
	for (int i = 0; i < Count; i++) {
		//int bit;
		bool flag = 0;
		string bit;
		regex powerful("^[0-9]{0,50}$");
		while (true) {
		cin >> bit;
			if (regex_match(bit, powerful) && stoi(bit) >= 0 && stoi(bit) <= this->base->Getk()) {
				break; // Ввод соответствует регулярному выражению, выходим из цикла
			}
			else {
				std::cout << "Ошибка ввода! Ведите либо 0, либо 1\n";
			}
		}
		for (int j = 0; j < base->Getk(); j++) {
			if (stoi(bit) == j 
				&& elems[j] < (base->GetKrat().at(j)) 
				&& regex_match(bit, powerful)) 
			{
				elems[j]++;
				flag++;
				break;
			}

		}
		if (flag == 0) {
			i--;
			cout << "Ошибка ввода, попробуйте другое число.\n";
		}
	} 
	*/
}

void Multi::Unification(Multi& a, Multi& b) { //объединение
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = a.elems[i] > b.elems[i] ? a.elems[i] : b.elems[i];
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::Intersection(Multi& a, Multi& b) { //Пересечение 
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = a.elems[i] < b.elems[i] ? a.elems[i] : b.elems[i];
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::DifferenceA(Multi& a, Multi& b){ // разность множеств A и B
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = a.elems[i] < (base->GetKrat()[i]-b.elems[i]) ? a.elems[i] : base->GetKrat()[i] - b.elems[i];
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::Ar_DifferenceA(Multi& a, Multi& b) { //Арифметическая разность множеств A и B
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = a.elems[i] - b.elems[i] > 0 ? a.elems[i] - b.elems[i] : 0;
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::DifferenceB(Multi& a, Multi& b){ //разность множеств B и A
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = (base->GetKrat()[i]-a.elems[i]) < b.elems[i] ?base->GetKrat()[i]- a.elems[i] : b.elems[i];;
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::Ar_DifferenceB(Multi& a, Multi& b) { //Арифметическая разность множеств B и A
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = b.elems[i] - a.elems[i] > 0 ? b.elems[i] - a.elems[i] : 0;
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::AdditionA(Multi& a, Multi& b){ //Дополнение множества A
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] =  a.base->GetKrat().at(i)-a.elems[i]>0 ? a.base->GetKrat()[i] - a.elems[i] : 0;
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::AdditionB(Multi& a, Multi& b) { //Дополнение множества B
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = b.base->GetKrat().at(i) - b.elems[i] > 0 ? b.base->GetKrat()[i] - b.elems[i] : 0;
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::Sim_Difference(Multi& a, Multi& b){ //Симметрическая разность множеств A и B
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = a.elems[i] - b.elems[i] > 0 || b.elems[i] - a.elems[i] > 0 ? 
			(a.elems[i] - b.elems[i] > 0? a.elems[i] - b.elems[i] : b.elems[i] - a.elems[i] ): 0;
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::Ar_Summ(Multi & a, Multi & b){//арифметическая сумма А и В
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = b.elems[i] + a.elems[i] < base->GetKrat()[i] ? b.elems[i] + a.elems[i] : base->GetKrat()[i];
		if (elems[i] != 0)
			Show[i] = 1;
	}
}

void Multi::Ar_Prod(Multi & a, Multi & b){//арифметическое произведенеие А и В
	for (int i = 0; i < base->Getk(); i++) {
		this->elems[i] = b.elems[i] * a.elems[i] < base->GetKrat()[i] ? b.elems[i] * a.elems[i] : base->GetKrat()[i];
	}
}