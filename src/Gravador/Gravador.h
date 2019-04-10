#pragma once
#include <iostream>
#include <fstream>
#include "../ListaEncadeada/ListaEncadeada.h"
#include "../ListaSequencial/ListaSequencial.h"
using namespace std;


class Gravador {
  private:
    const char* nomeArquivo;
    ofstream* arquivo;

  public:
    Gravador();
    ~Gravador();
    ofstream& getArquivo();
    void abrir(const char* _nomeArquivo = "default.txt");
    template <class Lista>
    void salvarLista(Lista& lista);
};

template <class Lista>
void Gravador::salvarLista(Lista& lista) {
  if (!arquivo->is_open()) arquivo->open(nomeArquivo);
  for (int i = 0; i < lista.getTamanho(); i++) {
    *arquivo << lista[i].toString() << endl;
  }
}
