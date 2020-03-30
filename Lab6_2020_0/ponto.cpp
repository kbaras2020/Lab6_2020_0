#include "Ponto.h"
#include <iostream>

using namespace std;

void lePontos(ponto* const vPontos, int n) {
	for (int i = 0; i < n; i++) {
		cout << "x:";
		cin >> vPontos[i].x;
		cout << "y:";
		cin >> vPontos[i].y;
	}
	cout << endl;
}

void escrevePontos(const ponto* const vPontos, int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << vPontos[i].x << "," << vPontos[i].y << ")" << endl;
	}
}