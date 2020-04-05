#include "ponto.h"
#include "retangulo.h"
#include "LLPontos.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
Windows Shell:
C:\Caminho para a pasta do projeto\Pasta do projeto> g++ main.cpp ponto.cpp retangulo.cpp -o teste
C:\Caminho para a pasta do projeto\Pasta do projeto> .\teste.exe pontos.txt retangulo.txt
*/

/*
Visual Studio:
Debug->NomeDoProjeto Properties->Configuration Properties->Debugging->Command Arguments
escrever os nomes dos ficheiros separados por um espaço pontos.txt retangulo.txt
*/

//lista ligada a partir do ficheiro caso seja passado no arg, caso contrário, inserçao de pontos manual
int main(int argc, char* argv[]) { 
	Nodo* listaPts = NULL;
	if (argc == 3) {
		int np = 0;
		fstream file;
		file.open(argv[1], ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				np++;
			}
			file.close();
		}
		ponto* pontos = new ponto[np];
		lePontosFicheiro(pontos, np, argv[1]);
		//criar a lista a partir do vetor de pontos
		for (int i = 0; i < np; i++) {
			ponto* p = lePontoVetor(pontos, i);
			insereFim(&listaPts, p);
		}
		mostra(listaPts);
		retangulo* ret = defineRetangulo(pontos, np);
		cout << "Area do retangulo: " << calculaArea(ret);
		guardaRetangulo(ret, argv[2]);

		delete[] pontos;
		delete ret;
	}
	else if (argc == 1) {
		char continuar = 's';
		do {
			ponto* ponto = lePonto();
			insereFim(&listaPts, ponto);
			mostra(listaPts);
			cout << "Inserir + pontos? (s/n)" << endl;
			cin >> continuar;
		} while (continuar == 's');
		mostra(listaPts);
		retangulo* ret = defineRetangulo(listaPts);
		cout << "Area do retangulo: " << calculaArea(ret) << endl;

		removeInicio(&listaPts);
		cout << "A remover do inicio..." << endl;
		mostra(listaPts);
	}
	else {
		cout << "Ficheiros de entrada e de saida nao fornecidos.";
	}
	cin.ignore();
	cin.get();
	return 0;
}