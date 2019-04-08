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
  int rgint;
  try {
    rgint = stoi(rg);
  }
  catch(std::invalid_argument& e){
    rgint = -1;
  }
  return new Pessoa(nome, rgint);
}

void Principal::carregarArquivoSequencial() {
  auto start = chrono::high_resolution_clock::now();
  string linha;
  listaSequencial.realocar(leitor.nroLinhasArquivo());
  while (getline(leitor.getArquivo(), linha)) {
    listaSequencial.adicionar(parserParaPessoa(linha));
  }
  auto finish = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = finish - start;
  cout << "TEMPO: " << diff.count() << endl;
}

void Principal::carregarArquivoEncadeada() {
  auto start = chrono::high_resolution_clock::now();
  string linha;
  while (getline(leitor.getArquivo(), linha)) {
    listaEncadeada.push(parserParaPessoa(linha));
  }
  auto finish = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = finish - start;
  cout << "TEMPO: " << diff.count() << endl;
}

int Principal::escolherArquivo() {
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
    return -1;
  }
  return opcao - 1;
}

void Principal::listarSequencial() {
  auto start = chrono::high_resolution_clock::now();
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
  auto finish = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = finish - start;
  cout << "TEMPO: " << diff.count() << endl;
}

void Principal::listarEncadeada() {
  auto start = chrono::high_resolution_clock::now();
  int i = 0;
  Pessoa pessoa;
  if (listaEncadeada.getTamanho() == 0) {
    cout << "Lista vazia." << endl;
  }
  while (listaEncadeada.temProximo(i)) {
    pessoa = listaEncadeada[i];
    cout << i + 1 << ") NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
    i++;
  }
  auto finish = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = finish - start;
  cout << "TEMPO: " << diff.count() << endl;
}

void Principal::executar() {
  short opcao = 5;
  int codArquivo = -1;
  do {
    cout << "1 - Carregar Sequencial" << endl;
    cout << "2 - Listar Sequencial" << endl;
    cout << "3 - Carregar Encadeada" << endl;
    cout << "4 - Listar Encadeada" << endl;
    cout << "5 - Sair" << endl;
    cin >> opcao;
    if (opcao == 1) {
      codArquivo = escolherArquivo();
      if (codArquivo != -1) {
        leitor.abrir(ARQUIVOS[codArquivo]);
        carregarArquivoSequencial();
      }
    } else if (opcao == 2) {
      listarSequencial();
    } else if (opcao == 3) {
      codArquivo = escolherArquivo();
      if (codArquivo != -1) {
        leitor.abrir(ARQUIVOS[codArquivo]);
        carregarArquivoEncadeada();
      }
    } else if (opcao == 4) {
      listarEncadeada();
    } else if (opcao == 5) {
      exit(0);
    } else {
      cout << "Opção Inválida." << endl;
    }
  } while (1);
}
