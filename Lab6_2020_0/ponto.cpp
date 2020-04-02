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

void guardaPontosBin(const ponto* const vPontos, int n, string fileName) {
	fstream file;
	file.open(fileName, ios::out | ios::binary);
	if (file.is_open()) {
		file.write((char*)vPontos, n * sizeof(ponto));
		file.close();
	}
	else cout << "Erro ao abrir o ficheiro" << endl;
}

void lePontosBin(ponto* const vPontos, int n, string fileName) {
	fstream file;
	file.open(fileName, ios::in | ios::binary);
	if (file.is_open()) {
		file.read((char*)vPontos, n * sizeof(ponto));
		file.close();
	}
	else cout << "Erro ao abrir o ficheiro" << endl;
}