#include "ponto.h"
#include "retangulo.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Quantos pontos?";
	int np; 
	cin >> np;
	ponto * pontos = new ponto[np];
	lePontos(pontos, np);
	escrevePontos(pontos, np);
	retangulo* ret = defineRetangulo(pontos, np);
	cout << "Area do retangulo: " << calculaArea(ret);
	delete[] pontos;
	delete ret;
	cin.ignore();
	cin.get();
	return 0;
}