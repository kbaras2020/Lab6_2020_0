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
void guardaPontosBin(const ponto* const vPontos, int n, string fileName);
void lePontosBin(ponto* const vPontos, int n, string fileName);

#endif