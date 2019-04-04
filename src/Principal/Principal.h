#pragma once
#include "../Pessoa/Pessoa.h"
#include "../ListaSequencial/ListaSequencial.h"
#include "../ListaEncadeada/ListaEncadeada.h"
#include "../Leitor/Leitor.h"

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
