#include "ponto.h"
#include "retangulo.h"
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

int main(int argc, char* argv[]) { //argv[0] é sempre o nome do executável
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
		escrevePontos(pontos, np);
		retangulo* ret = defineRetangulo(pontos, np);
		cout << "Area do retangulo: " << calculaArea(ret);
		guardaRetangulo(ret, argv[2]);

		delete[] pontos;
		delete ret;
	}
	else {
		cout << "Ficheiros de entrada e de saida nao fornecidos.";
	}
	cin.ignore();
	cin.get();
	return 0;
}