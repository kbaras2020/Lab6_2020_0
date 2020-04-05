#pragma once
#ifndef H_RETANGULO
#define H_RETANGULO
#include "Ponto.h"
#include "LLPontos.h"

struct retangulo {
	ponto supEsq;
	ponto infDir;
};

retangulo* defineRetangulo(const ponto* const vPontos, int n);
int calculaArea(const retangulo* const pRec);
void guardaRetangulo(const retangulo* const pRec, string fileName);
retangulo* defineRetangulo(Nodo* lista);
#endif