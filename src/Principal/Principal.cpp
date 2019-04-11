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
  string nome, rg;
  cout << "Digite o nome da Pessoa: ";
  cin >> nome;
  cout << "Digite o RG da Pessoa: ";
  cin >> rg;
  int rgint;
  try {
    rgint = stoi(rg);
  }
  catch(std::invalid_argument& e){
    rgint = -1;
  }
  return new Pessoa(nome, rgint);
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
  Pessoa* pessoa;
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
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarFimEncadeada() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaEncadeada.push(pessoa);
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarInicioSequencial() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaSequencial.unshift(pessoa);
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarInicioEncadeada() {
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaEncadeada.unshift(pessoa);
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarMeioSequencial() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaSequencial.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaSequencial.add(pessoa, i);
  Util::getInstance().stopAndPrint();
}

void Principal::adicionarMeioEncadeada() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaEncadeada.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Pessoa* pessoa = lerPessoa();
  Util::getInstance().start();
  listaEncadeada.add(pessoa, i);
  Util::getInstance().stopAndPrint();
}

void Principal::removerFimSequencial() {
  Util::getInstance().start();
  listaSequencial.pop();
  Util::getInstance().stopAndPrint();
}

void Principal::removerFimEncadeada() {
  Util::getInstance().start();
  listaEncadeada.pop();
  Util::getInstance().stopAndPrint();
}

void Principal::removerInicioSequencial() {
  Util::getInstance().start();
  listaSequencial.shift();
  Util::getInstance().stopAndPrint();
}

void Principal::removerInicioEncadeada() {
  Util::getInstance().start();
  listaEncadeada.shift();
  Util::getInstance().stopAndPrint();
}

void Principal::removerMeioSequencial() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaSequencial.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Util::getInstance().start();
  listaSequencial.remove(i);
  Util::getInstance().stopAndPrint();
}

void Principal::removerMeioEncadeada() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaEncadeada.getTamanho() - 1 << ")" << endl;
  cin >> i;
  Util::getInstance().start();
  listaEncadeada.remove(i);
  Util::getInstance().stopAndPrint();
}

void Principal::salvarListaEncadeada() {
  Util::getInstance().start();
  gravador.abrir(ARQUIVO_SAIDA_ENCADEADA);
  gravador.salvarLista(listaEncadeada);
  Util::getInstance().stopAndPrint();
}

void Principal::salvarListaSequencial() {
  Util::getInstance().start();
  gravador.abrir(ARQUIVO_SAIDA_SEQUENCIAL);
  gravador.salvarLista(listaSequencial);
  Util::getInstance().stopAndPrint();
}

void Principal::menuSequencial() {
  short opcao = 10;
  int codArquivo = -1;
  do {
    cout << "1 - Carregar Sequencial" << endl;
    cout << "2 - Listar Sequencial" << endl;
    cout << "3 - Adicionar Fim Sequencial" << endl;
    cout << "4 - Remover Fim Sequencial" << endl;
    cout << "5 - Adicionar Início Sequencial" << endl;
    cout << "6 - Remover Início Sequencial" << endl;
    cout << "7 - Adicionar Meio Sequencial" << endl;
    cout << "8 - Remover Meio Sequencial" << endl;
    cout << "9 - Salvar Sequencial" << endl;
    cout << "10 - Voltar" << endl;
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
      adicionarFimSequencial();
    } else if (opcao == 4) {
      removerFimSequencial();
    } else if (opcao == 5) {
      adicionarInicioSequencial();
    } else if (opcao == 6) {
      removerInicioSequencial();
    } else if (opcao == 7) {
      adicionarMeioSequencial();
    } else if (opcao == 8) {
      removerMeioSequencial();
    } else if (opcao == 9) {
      salvarListaSequencial();
    } else if (opcao != 10) {
      cout << "Opção Inválida." << endl;
    }
  } while (opcao != 10);
}

void Principal::menuEncadeada() {
  short opcao = 10;
  int codArquivo = -1;
  do {
    cout << "1 - Carregar Encadeada" << endl;
    cout << "2 - Listar Encadeada" << endl;
    cout << "3 - Adicionar Fim Encadeada" << endl;
    cout << "4 - Remover Fim Encadeada" << endl;
    cout << "5 - Adicionar Início Encadeada" << endl;
    cout << "6 - Remover Início Encadeada" << endl;
    cout << "7 - Adicionar Meio Encadeada" << endl;
    cout << "8 - Remover Meio Encadeada" << endl;
    cout << "9 - Salvar Encadeada" << endl;
    cout << "10 - Voltar" << endl;
    cin >> opcao;

    if (opcao == 1) {
      codArquivo = escolherArquivo();
      if (codArquivo != -1) {
        leitor.abrir(ARQUIVOS[codArquivo]);
        carregarArquivoEncadeada();
      }
    } else if (opcao == 2) {
      listarEncadeada();
    }else if (opcao == 3) {
      adicionarFimEncadeada();
    } else if (opcao == 4) {
      removerFimEncadeada();
    } else if (opcao == 5) {
      adicionarInicioEncadeada();
    } else if (opcao == 6) {
      removerInicioEncadeada();
    } else if (opcao == 7) {
      adicionarMeioEncadeada();
    } else if (opcao == 8) {
      removerMeioEncadeada();
    } else if (opcao == 9) {
      salvarListaEncadeada();
    } else if (opcao != 10) {
      cout << "Opção Inválida." << endl;
    }
  } while (opcao != 10);
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
