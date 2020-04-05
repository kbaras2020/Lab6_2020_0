#pragma once
#ifndef H_PONTO
#define H_PONTO
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ponto {
	int x;
	int y;
};


void lePontos(ponto* const vPontos, int n);
void escrevePontos(const ponto* const vPontos, int n);
void lePontosFicheiro(ponto* const vPontos, int n, string f);

ponto* lePontoVetor(ponto* vPontos, int i);
ponto* lePonto();
#endif