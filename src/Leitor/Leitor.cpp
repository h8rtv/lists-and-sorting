#include "Leitor.h"

Leitor::Leitor(const char* _nomeArquivo):
  arquivo(_nomeArquivo)
{
  nroLinhas = 0;
  nomeArquivo = _nomeArquivo;
}

Leitor::~Leitor() {
  arquivo.close();
}

void Leitor::reiniciar() {
  arquivo.clear();
  arquivo.seekg(0, std::ios::beg);
}

int Leitor::nroLinhasArquivo() {
  if (nroLinhas == 0) {
    string linha;
    int contador = 0;
    while (getline(arquivo, linha)) {
      contador++;
    }
    nroLinhas = contador;
  }
  reiniciar();
  return nroLinhas;
}

ifstream& Leitor::getArquivo() {
  return arquivo;
}


// void Leitor::ler(cb_leitor) {
//   string linha;
//   while (getline(arquivo, linha)) {
//     cb_leitor(linha);
//   }
// }
