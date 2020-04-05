#include "Ponto.h"

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

void lePontosFicheiro(ponto* const vPontos, int n, string fileName) {
	fstream file;
	file.open(fileName, ios::in);
	int x, y;
	int i = 0;
	char c;
	if (file.is_open()) {
		while ((file >> c >> x >> c >> y >> c)) {
			vPontos[i].x = x;
			vPontos[i].y = y;
			i++;
		}
		file.close();
	}

}
ponto* lePontoVetor(ponto* vPontos, int i) {
	ponto* pto = new ponto;
	pto->x = vPontos[i].x;
	pto->y = vPontos[i].y;
	return pto;
}

ponto* lePonto() {
	ponto* pto = new (ponto);
	cout << "x: ";
	cin >> pto->x;
	cout << "y: ";
	cin >> pto->y;
	cout << endl;
	return pto;
}