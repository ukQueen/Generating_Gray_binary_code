#include "GrayCode.h"

GrayCode::GrayCode() {}

GrayCode::GrayCode(int a) {
	n = a;
	if (a == 0)
		k = 0;
	else
	k = 2;
	for (int i = 0; i < n - 1; i++) {
		k *= 2;
	}
	Count = k;
	//Codes = new int[k * n];
	Codes.resize(k * n);
	
	int buf = k / 2;
	
	for (int m= 0; m < n;m++) {
		static int i = 0;
		static int p = 1;
		int f = 0;
		for (i; i < k * p; i++) {
			if (f < buf)
				Codes[i] = 0;
			else
				Codes[i] = 1;
			f++;
			if (f == buf * 2)
				f = 0;
		}
		buf = buf / 2;
		p++;
	} 
	//Krat = new int[k];
	Krat.resize(k);
	srand(time(0));
	
	for (int i = 0; i< k; i++) {
		Krat[i] = rand() % 99+1 ;

	}

}

void GrayCode::Print() {
	cout << "\n  ÓÍÈÂÅÐÑÓÌ\n\n";

	if (n == 0) {
		printf("Ïóñò..\n");
	}
	else {
		for (int i = 0; i < k; i++) {
			if (Krat[i] != 0) {
				cout << "   ";
				for (int j = 0; j < k * n; j += k) {
					cout << "  " << Codes[i + j];
				}

				cout << "  [" << i << "]" << " :  " << Krat[i] << "\n";
			}
		}
	}
}

int GrayCode::Getk() {
	return k;
}


int GrayCode::Getn() {
	return n;
}

int GrayCode::GetCount() {
	return Count;
}

vector <int> GrayCode::GetKrat() {
	return Krat;
}

vector <int> GrayCode::GetCodes() {
	return Codes;
}


/*
void GrayCode::ToNull(int a) {
	srand(time(0));
		for (int i = 0; i < a; i++) { 
			int n = rand() % k ;
			if (Krat[n] == 0)
				i--;
			else {
				max-=Krat[n];
				Krat[n] = 0;
				Count--;
			}
		}
}
*/ 