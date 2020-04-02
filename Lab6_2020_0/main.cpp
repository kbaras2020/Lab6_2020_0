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


//quando usar formato binário: https://isocpp.org/wiki/faq/serialization#serialize-decide-text-vs-binary


int main(int argc, char* argv[]) { //argv[0] é sempre o nome do executável
	if (argc == 3) {
		int np = 0;
		fstream file;
		file.open("pontos.bin", ios::in | ios::binary);
		if (file.is_open()) {
			int begin = file.tellg();
			file.seekg(0, ios::end);
			int end = file.tellg();
			np = (end - begin) / sizeof(ponto);
			cout << np << endl;
			file.close();
		}
		ponto* pontos = new ponto[np];
		//lePontosFicheiro(pontos, np, argv[1]);
		//escrevePontos(pontos, np);
		//guardaPontosBin(pontos, np, "pontos.bin");
		lePontosBin(pontos, np, "pontos.bin");
		escrevePontos(pontos, np);
		retangulo* ret = defineRetangulo(pontos, np);
		cout << "Area do retangulo: " << calculaArea(ret);
		//guardaRetangulo(ret, argv[2]);
		guardaRetanguloBin(ret, "retangulo.bin");

		retangulo* outroRet = leRetanguloBin("retangulo.bin");
		cout << endl;
		cout << "(" << outroRet->supEsq.x << "," << outroRet->supEsq.y << ")" << endl;
		cout << "(" << outroRet->infDir.x << "," << outroRet->infDir.y << ")" << endl;
		cout << "Area do segundo retangulo: " << calculaArea(outroRet);
		delete outroRet;
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