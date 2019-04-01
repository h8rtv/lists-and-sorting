#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Leitor {
  private:
    string nomeArquivo;
    ifstream arquivo;
    int nroLinhas;

  public:
    Leitor(const char* _nomeArquivo = "");
    ~Leitor();
    ifstream& getArquivo();
    int nroLinhasArquivo();
    void reiniciar();
    // void ler(cb_leitor);
};
