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
  auto start = chrono::high_resolution_clock::now();
  string linha;
  listaSequencial.realocar(leitor.nroLinhasArquivo());
  while (getline(leitor.getArquivo(), linha)) {
    listaSequencial.push(parserParaPessoa(linha));
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

void Principal::adicionarFimSequencial() {
  listaSequencial.push(lerPessoa());
}

void Principal::adicionarFimEncadeada() {
  listaEncadeada.push(lerPessoa());
}

void Principal::adicionarInicioSequencial() {
  listaSequencial.unshift(lerPessoa());
}

void Principal::adicionarInicioEncadeada() {
  listaEncadeada.unshift(lerPessoa());
}

void Principal::adicionarMeioSequencial() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaSequencial.getTamanho() - 1 << ")" << endl;
  cin >> i;
  listaSequencial.add(lerPessoa(), i);
}

void Principal::adicionarMeioEncadeada() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaEncadeada.getTamanho() - 1 << ")" << endl;
  cin >> i;
  listaEncadeada.add(lerPessoa(), i);
}

void Principal::removerFimSequencial() {
  listaSequencial.pop();
}

void Principal::removerFimEncadeada() {
  listaEncadeada.pop();
}

void Principal::removerInicioSequencial() {
  listaSequencial.shift();
}

void Principal::removerInicioEncadeada() {
  listaEncadeada.shift();
}

void Principal::removerMeioSequencial() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaSequencial.getTamanho() << ")" << endl;
  cin >> i;
  listaSequencial.remove(i);
}

void Principal::removerMeioEncadeada() {
  int i;
  cout << "Digite o índice da busca (0 - " << listaEncadeada.getTamanho() << ")" << endl;
  cin >> i;
  listaEncadeada.remove(i);
}

void Principal::salvarListaEncadeada() {
  gravador.abrir(ARQUIVO_SAIDA_ENCADEADA);
  gravador.salvarLista(listaEncadeada);
}

void Principal::salvarListaSequencial() {
  gravador.abrir(ARQUIVO_SAIDA_SEQUENCIAL);
  gravador.salvarLista(listaSequencial);
}


void Principal::executar() {
  short opcao = 5;
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
    cout << "10 - Carregar Encadeada" << endl;
    cout << "11 - Listar Encadeada" << endl;
    cout << "12 - Adicionar Fim Encadeada" << endl;
    cout << "13 - Remover Fim Encadeada" << endl;
    cout << "14 - Adicionar Início Encadeada" << endl;
    cout << "15 - Remover Início Encadeada" << endl;
    cout << "16 - Adicionar Meio Encadeada" << endl;
    cout << "17 - Remover Meio Encadeada" << endl;
    cout << "18 - Salvar Encadeada" << endl;
    cout << "19 - Sair" << endl;
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
    } else if (opcao == 10) {
      codArquivo = escolherArquivo();
      if (codArquivo != -1) {
        leitor.abrir(ARQUIVOS[codArquivo]);
        carregarArquivoEncadeada();
      }
    } else if (opcao == 11) {
      listarEncadeada();
    }else if (opcao == 12) {
      adicionarFimEncadeada();
    } else if (opcao == 13) {
      removerFimEncadeada();
    } else if (opcao == 14) {
      adicionarInicioEncadeada();
    } else if (opcao == 15) {
      removerInicioEncadeada();
    } else if (opcao == 16) {
      adicionarMeioEncadeada();
    } else if (opcao == 17) {
      removerMeioEncadeada();
    } else if (opcao == 18) {
      salvarListaEncadeada();
    } else if (opcao == 19) {
      exit(0);
    } else {
      cout << "Opção Inválida." << endl;
    }
    cin.get();
  } while (1);
}
