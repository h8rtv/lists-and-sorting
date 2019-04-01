#include <iostream>
#include "Principal.h"
#include <stdlib.h>

Principal::Principal():
  leitor("./arquivocomprimidonomerg/NomeRG10.txt")
{
  executar();
}

Principal::~Principal() {
  exit(0);
}

Pessoa* Principal::parserParaPessoa(string linha) {
  int pos = linha.find(',');
  string nome = linha.substr(0, pos);
  string rg = linha.substr(pos + 1, linha.size());
  return new Pessoa(nome, rg);
}

void Principal::carregarArquivo() {
  string linha;
  // listaSequencial.instanciar(leitor.nroLinhasArquivo());
  while (getline(leitor.getArquivo(), linha)) {
    listaSequencial.adicionar(parserParaPessoa(linha));
  }
}

void Principal::listar() {
  int i = 0;
  Pessoa* pessoa;
  if (listaSequencial.getTamanho() == 0) {
    cout << "Lista vazia." << endl;
  }
  while (listaSequencial.temProximo(i)) {
    pessoa = listaSequencial.get(i);
    if (pessoa != NULL) {
      cout << i + 1 << ") NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
    }
    i++;
  }
}

void Principal::executar() {
  short opcao = 3;
  do {
    cout << "1 - Carregar" << endl;
    cout << "2 - Listar" << endl;
    cout << "3 - Sair" << endl;
    cin >> opcao;
    if (opcao == 1) {
      carregarArquivo();
    } else if (opcao == 2) {
      listar();
    } else if (opcao == 3) {
      exit(0);
    } else {
      cout << "Opção Inválida." << endl;
    }
  } while (1);
}
