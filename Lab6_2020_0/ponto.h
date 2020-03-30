#pragma once
#ifndef H_PONTO
#define H_PONTO
#include <iostream>

using namespace std;

struct ponto {
	int x;
	int y;
};


void lePontos(ponto* const vPontos, int n);
void escrevePontos(const ponto* const vPontos, int n);

#endif