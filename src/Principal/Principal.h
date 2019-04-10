#pragma once

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <chrono>
#include "../Pessoa/Pessoa.h"
#include "../ListaSequencial/ListaSequencial.h"
#include "../ListaEncadeada/ListaEncadeada.h"
#include "../Leitor/Leitor.h"
#include "../Gravador/Gravador.h"

using namespace std;

class Principal {
  private:
    Leitor leitor;
    Gravador gravador;
    ListaSequencial<Pessoa> listaSequencial;
    ListaEncadeada<Pessoa> listaEncadeada;

  public:
    Principal();
    ~Principal();
    void executar();
    void carregarArquivoSequencial();
    void carregarArquivoEncadeada();
    void salvarListaSequencial();
    void salvarListaEncadeada();
    int escolherArquivo();
    void listarSequencial();
    void listarEncadeada();
    Pessoa* parserParaPessoa(string linha);
    Pessoa* lerPessoa();
    void adicionarFimSequencial();
    void removerFimSequencial();
    void adicionarInicioSequencial();
    void removerInicioSequencial();
    void adicionarMeioSequencial();
    void removerMeioSequencial();
    void adicionarFimEncadeada();
    void removerFimEncadeada();
    void adicionarInicioEncadeada();
    void removerInicioEncadeada();
    void adicionarMeioEncadeada();
    void removerMeioEncadeada();
};
