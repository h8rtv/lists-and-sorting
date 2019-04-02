#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Leitor {
  private:
    const char* nomeArquivo;
    ifstream* arquivo;
    int nroLinhas;
    bool aberto;

  public:
    Leitor(const char* _nomeArquivo = "");
    ~Leitor();
    ifstream& getArquivo();
    int nroLinhasArquivo();
    void reiniciar();
    void abrir(const char* _nomeArquivo = "");
};
