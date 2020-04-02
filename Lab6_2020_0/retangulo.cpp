#include "Retangulo.h"

retangulo* defineRetangulo(const ponto* const vPontos, int n) {
	retangulo* rect = new retangulo;
	rect->supEsq.x = vPontos[0].x;
	rect->supEsq.y = vPontos[0].y;
	rect->infDir.x = vPontos[0].x;
	rect->infDir.y = vPontos[0].y;
	for (int i = 1; i < n; i++) {
		if (vPontos[i].x < rect->supEsq.x)
			rect->supEsq.x = vPontos[i].x;
		if (vPontos[i].y > rect->supEsq.y)
			rect->supEsq.y = vPontos[i].y;
		if (vPontos[i].x > rect->infDir.x)
			rect->infDir.x = vPontos[i].x;
		if (vPontos[i].y < rect->infDir.y)
			rect->infDir.y = vPontos[i].y;
	}
	return rect;
}

int calculaArea(const retangulo* const pRec) {
	int area = (pRec->infDir.x - pRec->supEsq.x) * (pRec->supEsq.y - pRec->infDir.y);
	return area;
	//return (pRec->infDir.x - pRec->supEsq.x) * (pRec->supEsq.y - pRec->infDir.y);
}

void guardaRetangulo(const retangulo* const pRec, string fileName) {
	fstream file;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		file << "(" << pRec->supEsq.x << "," << pRec->supEsq.y << ")" << endl
			 << "(" << pRec->infDir.x << "," << pRec->infDir.y << ")" << endl
			 << calculaArea(pRec) << endl;
		file.close();
	}
	else cout << "Erro ao abrir o ficheiro" << endl;
}

void guardaRetanguloBin(const retangulo* const pRec, string fileName) {
	fstream file;
	file.open(fileName, ios::out | ios::binary);

	if (file.is_open()) {
		file.write((char*)pRec, sizeof(retangulo));
		file.close();
	}
	else cout << "Erro ao abrir o ficheiro" << endl;
}

retangulo* leRetanguloBin(string fileName) {
	fstream file;
	file.open(fileName, ios::in | ios::binary);
	if (file.is_open()) {
		retangulo* novoRet = new retangulo;
		file.read((char*)novoRet, sizeof(retangulo));
		file.close();
		return novoRet;
	}
	else cout << "Erro ao abrir o ficheiro." << endl;
	return 0;
}