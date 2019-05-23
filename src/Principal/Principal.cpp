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

Pessoa* Principal::lerPessoa() {
  string nome;
  int rg;
  cout << "Digite o nome da Pessoa: ";
  cin >> nome;
  rg = lerRg();

  return new Pessoa(nome, rg);
}

int Principal::lerRg() {
  int rg;
  cout << "Digite o RG da Pessoa: ";
  cin >> rg;
  return rg;
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

void Principal::carregarArquivoSequencial() {
  Util::getInstance().start();
  string linha;
  listaSequencial.realocar(leitor.nroLinhasArquivo());
  while (getline(leitor.getArquivo(), linha)) {
    listaSequencial.push(parserParaPessoa(linha));
  }
  Util::getInstance().stopAndPrint();
}

void Principal::carregarArquivoEncadeada() {
  Util::getInstance().start();
  string linha;
  while (getline(leitor.getArquivo(), linha)) {
    listaEncadeada.push(parserParaPessoa(linha));
  }
  Util::getInstance().stopAndPrint();
  /*   class CB {
      public:
        CB(Principal* pr = NULL) {
          p = pr;
        }
        void operator()(string linha) {
          p->listaEncadeada.push(p->parserParaPessoa(linha));
        }
      private:
        Principal* p;
    };
    CB cb(this); 
    auto cb = [&](string linha) {
      listaEncadeada.push(parserParaPessoa(linha));
    };
    leitor.lerLinha(cb); */
}

void Principal::listarSequencial() {
  Util::getInstance().start();
  int i = 0;
  Pessoa pessoa;
  if (listaSequencial.getTamanho() == 0) {
    cout << "Lista vazia." << endl;
  }
  while (Util::getInstance().addC(), listaSequencial.temProximo(i)) {
    pessoa = listaSequencial[i];
    cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
    i++;
  }
  Util::getInstance().stopAndPrint();
}

void Principal::listarEncadeada() {
  Util::getInstance().start();
  int i = 0;
  if (listaEncadeada.getTamanho() == 0) {
    cout << "Lista vazia." << endl;
  }
  Pessoa* pessoa = NULL;
  Node<Pessoa>* node = listaEncadeada.getbegin();
  while (Util::getInstance().addC(), listaEncadeada.temProximo(i) && node != NULL) {
    pessoa = node->getvalue();
    cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
    i++;
    Util::getInstance().addM(), node = node->getnext();
  }
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarFimSequencial() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaSequencial.push(pessoa);
  int i = listaSequencial.getTamanho() - 1;
  cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarFimEncadeada() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaEncadeada.push(pessoa);
  int i = listaEncadeada.getTamanho() - 1;
  cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarInicioSequencial() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaSequencial.unshift(pessoa);
  int i = 0;
  cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarInicioEncadeada() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaEncadeada.unshift(pessoa);
  int i = 0;
  cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarMeioSequencial() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaSequencial.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaSequencial.add(pessoa, i);
  cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarMeioEncadeada() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaEncadeada.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaEncadeada.add(pessoa, i);
  cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::removerFimSequencial() {
  int i = listaSequencial.getTamanho() - 1;
  Pessoa pessoa = listaSequencial[i];
  Util::getInstance().start();
  listaSequencial.pop();
  cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
  cout << "Posição: " << listaSequencial.getTamanho() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::removerFimEncadeada() {
  int i = listaEncadeada.getTamanho() - 1;
  Pessoa pessoa = listaEncadeada[i];
  Util::getInstance().start();
  listaEncadeada.pop();
  cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::removerInicioSequencial() {
  int i = 0;
  Pessoa pessoa = listaSequencial[i];
  Util::getInstance().start();
  listaSequencial.shift();
  cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::removerInicioEncadeada() {
  int i = 0;
  Pessoa pessoa = listaEncadeada[i];
  Util::getInstance().start();
  listaEncadeada.shift();
  cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::removerMeioSequencial() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaSequencial.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Pessoa pessoa = listaSequencial[i];
  Util::getInstance().start();
  listaSequencial.remove(i);
  cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::removerMeioEncadeada() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaEncadeada.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Pessoa pessoa = listaEncadeada[i];
  Util::getInstance().start();
  listaEncadeada.remove(i);
  cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::salvarListaEncadeada() {
  Util::getInstance().start();
  gravador.abrir(ARQUIVO_SAIDA_ENCADEADA);
  gravador.salvarListaEncadeada(listaEncadeada);
  Util::getInstance().stopAndPrint();
}

void Principal::salvarListaSequencial() {
  Util::getInstance().start();
  gravador.abrir(ARQUIVO_SAIDA_SEQUENCIAL);
  gravador.salvarListaSequencial(listaSequencial);
  Util::getInstance().stopAndPrint();
}

void Principal::buscaEncadeada() {
  int rg = lerRg();
  int i = 0;
  bool found = false;
  Pessoa* pessoa = NULL;
  Util::getInstance().start();
  Node<Pessoa>* node = listaEncadeada.getbegin();
  while (Util::getInstance().addC(), listaEncadeada.temProximo(i) && node != NULL) {
    pessoa = node->getvalue();
    if (Util::getInstance().addC(), rg == pessoa->getRg()) {
      cout << "[" << i << "] NOME: " << pessoa->getNome() << ", RG: " << pessoa->getRg() << endl;
      found = true;
      break;
    }
    i++;
    Util::getInstance().addM(), node = node->getnext();
  }
  if (!found) cout << "RG não encontrado." << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::buscaSequencial() {
  int rg = lerRg();
  Pessoa pessoa;
  int i = 0;
  bool found = false;
  Util::getInstance().start();
  while (Util::getInstance().addC(), listaSequencial.temProximo(i)) {
    pessoa = listaSequencial[i];
    if (rg == pessoa.getRg()) {
      cout << "[" << i << "] NOME: " << pessoa.getNome() << ", RG: " << pessoa.getRg() << endl;
      found = true;
      break;
    }
    i++;
  }
  if (!found) cout << "RG não encontrado." << endl;
  Util::getInstance().stopAndPrint();
}

int encontrarBinario(ListaSequencial<Pessoa>& lista, int rg) {
  Util& util = Util::getInstance();
  Pessoa p;
  int C = 0;
  int comeco = 0;
  int fim = lista.getTamanho() - 1;
  int meio;
  while (comeco <= fim) {
    C++;
    meio = (fim + comeco) / 2;
    p = lista[meio];
    if (C++, p.getRg() == rg) {
      util.addC(C);
      return meio;
    } else if (C++, p.getRg() < rg)
      comeco = meio + 1;
    else
      fim = meio - 1;
  }
  util.addC(C);
  return -1;
}

void Principal::buscaBinariaSequencial() {
  int rg = lerRg();
  Util::getInstance().start();
  int i = encontrarBinario(listaSequencial, rg);
  if (i != -1)
    cout << "[" << i << "] NOME: " << listaSequencial[i].getNome() << ", RG: " << listaSequencial[i].getRg() << endl;
  else cout << "RG não encontrado." << endl;
  Util::getInstance().stopAndPrint();
}

void Principal::buscaBinariaEncadeada() {
  int rg = lerRg();
  Util::getInstance().start();
  ListaSequencial<Pessoa>* listaIndireta = listaEncadeada.mapToArray();
  int i = encontrarBinario(*listaIndireta, rg);
  if (i != -1)
    cout << "[" << i << "] NOME: " << (*listaIndireta)[i].getNome() << ", RG: " << (*listaIndireta)[i].getRg() << endl;
  else cout << "RG não encontrado." << endl;
  Util::getInstance().stopAndPrint();
  delete listaIndireta;
}

void Principal::menuSequencial() {
  short opcao = 13;
  int codArquivo = -1;
  do {
    cout << "1 - Carregar Sequencial" << endl;
    cout << "2 - Busca RG Sequencial" << endl;
    cout << "3 - Listar Sequencial" << endl;
    cout << "4 - Adicionar Fim Sequencial" << endl;
    cout << "5 - Remover Fim Sequencial" << endl;
    cout << "6 - Adicionar Início Sequencial" << endl;
    cout << "7 - Remover Início Sequencial" << endl;
    cout << "8 - Adicionar Meio Sequencial" << endl;
    cout << "9 - Remover Meio Sequencial" << endl;
    cout << "10 - Salvar Sequencial" << endl;
    cout << "11 - Ordenar Sequencial" << endl;
    cout << "12 - Busca Binária RG Sequencial (Somente se a lista já estiver ordenada)" << endl;
    cout << "13 - Voltar" << endl;
    cin >> opcao;
    if (opcao == 1) {
      codArquivo = escolherArquivo();
      if (codArquivo != -1) {
        leitor.abrir(ARQUIVOS[codArquivo]);
        carregarArquivoSequencial();
      }
    } else if (opcao == 2) {
      buscaSequencial();
    } else if (opcao == 3) {
      listarSequencial();
    } else if (opcao == 4) {
      adicionarFimSequencial();
    } else if (opcao == 5) {
      removerFimSequencial();
    } else if (opcao == 6) {
      adicionarInicioSequencial();
    } else if (opcao == 7) {
      removerInicioSequencial();
    } else if (opcao == 8) {
      adicionarMeioSequencial();
    } else if (opcao == 9) {
      removerMeioSequencial();
    } else if (opcao == 10) {
      salvarListaSequencial();
    } else if (opcao == 11) {
      ordenarSequencial();
    } else if (opcao == 12) {
      buscaBinariaSequencial();
    } else if (opcao != 13) {
      cout << "Opção Inválida." << endl;
    }
  } while (opcao != 13);
}

void Principal::menuEncadeada() {
  short opcao = 13;
  int codArquivo = -1;
  do {
    cout << "1 - Carregar Encadeada" << endl;
    cout << "2 - Busca RG Encadeada" << endl;
    cout << "3 - Listar Encadeada" << endl;
    cout << "4 - Adicionar Fim Encadeada" << endl;
    cout << "5 - Remover Fim Encadeada" << endl;
    cout << "6 - Adicionar Início Encadeada" << endl;
    cout << "7 - Remover Início Encadeada" << endl;
    cout << "8 - Adicionar Meio Encadeada" << endl;
    cout << "9 - Remover Meio Encadeada" << endl;
    cout << "10 - Salvar Encadeada" << endl;
    cout << "11 - Ordenar Encadeada" << endl;
    cout << "12 - Busca Binária RG Encadeada (Somente se a lista já estiver ordenada)" << endl;
    cout << "13 - Voltar" << endl;
    cin >> opcao;

    if (opcao == 1) {
      codArquivo = escolherArquivo();
      if (codArquivo != -1) {
        leitor.abrir(ARQUIVOS[codArquivo]);
        carregarArquivoEncadeada();
      }
    } else if (opcao == 2) {
      buscaEncadeada();
    } else if (opcao == 3) {
      listarEncadeada();
    } else if (opcao == 4) {
      adicionarFimEncadeada();
    } else if (opcao == 5) {
      removerFimEncadeada();
    } else if (opcao == 6) {
      adicionarInicioEncadeada();
    } else if (opcao == 7) {
      removerInicioEncadeada();
    } else if (opcao == 8) {
      adicionarMeioEncadeada();
    } else if (opcao == 9) {
      removerMeioEncadeada();
    } else if (opcao == 10) {
      salvarListaEncadeada();
    } else if (opcao == 11) {
      ordenarEncadeada();
    } else if (opcao == 12) {
      buscaBinariaEncadeada();
    } else if (opcao != 13) {
      cout << "Opção Inválida." << endl;
    }
  } while (opcao != 13);
}


void Principal::executar() {
  short opcao = 5;
  do {
    cout << "1 - Sequencial" << endl;
    cout << "2 - Encadeada" << endl;
    cout << "3 - Sair" << endl;
    cin >> opcao;
    if (opcao == 1) {
      menuSequencial();
    } else if (opcao == 2) {
      menuEncadeada();
    } else if (opcao == 3) {
      exit(0);
    } else {
      cout << "Opção Inválida." << endl;
    }
  } while (1);
}

short Principal::menuOrdenar() {
  short opcao = 7;
  cout << "1 - Selection Sort" << endl;
  cout << "2 - Insertion Sort" << endl;
  cout << "3 - Bubble Sort" << endl;
  cout << "4 - Merge Sort" << endl;
  cout << "5 - Quick Sort" << endl;
  cout << "6 - Shell Sort" << endl;
  cout << "7 - Voltar" << endl;
  cin >> opcao;
  return opcao;
}

void Principal::ordenarSequencial() {
  switch (menuOrdenar()) {
  case 1:
    Util::getInstance().start();
    listaSequencial.selection_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 2:
    Util::getInstance().start();
    listaSequencial.insertion_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 3:
    Util::getInstance().start();
    listaSequencial.bubble_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 4:
    Util::getInstance().start();
    listaSequencial.merge_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 5:
    Util::getInstance().start();
    listaSequencial.quick_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 6:
    Util::getInstance().start();
    listaSequencial.shell_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 7:
    break;
  default:
    cout << "Opção Inválida." << endl;
    break;
  }
}

void Principal::ordenarEncadeada() {
  switch (menuOrdenar()) {
  case 1:
    Util::getInstance().start();
    listaEncadeada.selection_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 2:
    Util::getInstance().start();
    listaEncadeada.insertion_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 3:
    Util::getInstance().start();
    listaEncadeada.bubble_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 4:
    Util::getInstance().start();
    listaEncadeada.merge_sort();
    Util::getInstance().stopAndPrint();
    break;
   case 5:
    Util::getInstance().start();
    listaEncadeada.quick_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 6:
    Util::getInstance().start();
    listaEncadeada.shell_sort();
    Util::getInstance().stopAndPrint();
    break;
  case 7:
    break;
  default:
    cout << "Opção Inválida." << endl;
    break;
  }
}