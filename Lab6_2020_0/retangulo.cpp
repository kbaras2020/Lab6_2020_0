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