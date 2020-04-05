#pragma once
#ifndef H_LLPONTOS
#define H_LLPONTOS
#include "ponto.h"

struct Nodo {
	ponto dados;
	Nodo* seguinte;
};

Nodo* novoNodo(ponto* pDados);
void libertaNodo(Nodo* pNodo);
void insereFim(Nodo** pNodo, ponto* pDados);
void removeInicio(Nodo** pNodo);
void mostra(Nodo* lista);

#endif