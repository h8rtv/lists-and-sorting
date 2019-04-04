#pragma once

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "../Pessoa/Pessoa.h"
#include "../ListaSequencial/ListaSequencial.h"
#include "../ListaEncadeada/ListaEncadeada.h"
#include "../Leitor/Leitor.h"

using namespace std;

class Principal {
  private:
    Leitor leitor;
    ListaSequencial<Pessoa> listaSequencial;
    ListaEncadeada<Pessoa> listaEncadeada;

  public:
    Principal();
    ~Principal();
    void executar();
    void carregarArquivoSequencial();
    void carregarArquivoEncadeada();
    int escolherArquivo();
    void listarSequencial();
    void listarEncadeada();
    Pessoa* parserParaPessoa(string linha);
};
