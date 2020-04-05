#include "LLPontos.h"

Nodo* novoNodo(ponto* pDados) {
	Nodo* elemento = new Nodo;
	elemento->seguinte = NULL;
	elemento->dados.x = pDados->x;
	elemento->dados.y = pDados->y;
	return elemento;
}

void libertaNodo(Nodo* pNodo) {
	delete pNodo;
}

void insereFim(Nodo** pNodo, ponto* pDados) {
	Nodo* novo = novoNodo(pDados);
	if (*pNodo == NULL)
		*pNodo = novo;
	else {
		Nodo* aux = *pNodo;
		while (aux->seguinte != NULL)
			aux = aux->seguinte;
		aux->seguinte = novo;
	}
}

void removeInicio(Nodo** pNodo) {
	Nodo* aux = *pNodo;
	*pNodo = aux->seguinte;
	libertaNodo(aux);
}

void mostra(Nodo* lista) {
	Nodo* aux = lista;
	cout << endl;
	while (aux != 0) {
		cout << "(" << aux->dados.x << "," << aux->dados.y << ")" << "->";
		aux = aux->seguinte;
	}
	cout << "NULL" << endl;
}