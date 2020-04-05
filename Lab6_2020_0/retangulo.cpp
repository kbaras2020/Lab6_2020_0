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

retangulo* defineRetangulo(Nodo* lista) {
	Nodo* aux = lista;
	retangulo* rect = new retangulo;
	rect->supEsq.x = aux->dados.x;
	rect->supEsq.y = aux->dados.y;
	rect->infDir.x = aux->dados.x;
	rect->infDir.y = aux->dados.y;
	while (aux != 0) {
		if (aux->dados.x < rect->supEsq.x)
			rect->supEsq.x = aux->dados.x;
		if (aux->dados.y > rect->supEsq.y)
			rect->supEsq.y = aux->dados.y;
		if (aux->dados.x > rect->infDir.x)
			rect->infDir.x = aux->dados.x;
		if (aux->dados.y < rect->infDir.y)
			rect->infDir.y = aux->dados.y;
		aux = aux->seguinte;
	}
	return rect;
}