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
    template <class Tipo>
    void salvarListaEncadeada(ListaEncadeada<Tipo>& lista);
    template <class Tipo>
    void salvarListaSequencial(ListaSequencial<Tipo>& lista);
};

template <class Tipo>
void Gravador::salvarListaSequencial(ListaSequencial<Tipo>& lista) {
  if (!arquivo->is_open()) arquivo->open(nomeArquivo);
  ofstream& arquivoR = getArquivo();
  string buffer = "";
  for (int i = 0; i < lista.getTamanho(); i++) {
    buffer += lista[i].toString() + "\n";
    if (buffer.length() >= 512) {
      arquivoR << buffer;
      buffer = "";
    }
  }
  if (buffer.length() > 0) {
    arquivoR << buffer;
  }
  arquivoR.close();
}

template <class Tipo>
void Gravador::salvarListaEncadeada(ListaEncadeada<Tipo>& lista) {
  if (!arquivo->is_open()) arquivo->open(nomeArquivo);
  ofstream& arquivoR = getArquivo();
  Node<Tipo>* node = lista.getbegin();
  Tipo* value = NULL;
  string buffer = "";
  while (node != NULL) {
    buffer += node->getvalue()->toString() + "\n";
    node = node->getnext();
    if (buffer.length() >= 512) {
      arquivoR << buffer;
      buffer = "";
    }
  }
  if (buffer.length() > 0) {
    arquivoR << buffer;
  }
  arquivoR.close();
}