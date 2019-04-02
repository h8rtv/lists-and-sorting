#pragma once
#include "../Pessoa/Pessoa.h"
#include "../ListaSequencial/ListaSequencial.h"
#include "../Leitor/Leitor.h"

class Principal {
  private:
    Leitor leitor;
    ListaSequencial<Pessoa> listaSequencial;

  public:
    Principal();
    ~Principal();
    void executar();
    void carregarArquivo();
    void escolherArquivo();
    void listar();
    Pessoa* parserParaPessoa(string linha);
};
