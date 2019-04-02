#include <iostream>
#include <stdlib.h>
#include "Principal.h"
#include "Arquivos.h"

Principal::Principal()
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
  listaSequencial.realocar(leitor.nroLinhasArquivo());
  while (getline(leitor.getArquivo(), linha)) {
    listaSequencial.adicionar(parserParaPessoa(linha));
  }
}

void Principal::escolherArquivo() {
  short opcao;
  cout << "1 - NomeRG10.txt" << endl;
  cout << "2 - NomeRG50.txt" << endl;
  cout << "3 - NomeRG100.txt" << endl;
  cout << "4 - NomeRG1K.txt" << endl;
  cout << "5 - NomeRG10K.txt" << endl;
  cout << "6 - NomeRG1M.txt" << endl;
  cout << "7 - NomeRG100M.txt" << endl;
  cin >> opcao;
  if (opcao < 1 || opcao > 7) {
    cout << "Opção Inválida." << endl;
  } else {
    leitor.abrir(ARQUIVOS[opcao - 1]);
    carregarArquivo();
  }
}

void Principal::listar() {
  int i = 0;
  Pessoa pessoa;
  if (listaSequencial.getTamanho() == 0) {
    cout << "Lista vazia." << endl;
  }
  while (listaSequencial.temProximo(i)) {
    pessoa = listaSequencial[i];
    cout << i + 1 << ") NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
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
      escolherArquivo();
    } else if (opcao == 2) {
      listar();
    } else if (opcao == 3) {
      exit(0);
    } else {
      cout << "Opção Inválida." << endl;
    }
  } while (1);
}
