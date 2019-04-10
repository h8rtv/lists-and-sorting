#pragma once
#include <iostream>
#include <fstream>
#include <string>
// #include <functional>
using namespace std;

// typedef const function<void (string)> callback_leitura;

class Leitor {
  private:
    const char* nomeArquivo;
    ifstream* arquivo;
    int nroLinhas;

  public:
    Leitor(const char* _nomeArquivo = "");
    ~Leitor();
    ifstream& getArquivo();
    int nroLinhasArquivo();
    void reiniciar();
    void abrir(const char* _nomeArquivo = "");
    // template <typename Func>
    // void lerLinha(Func& cb) {
    //   string linha;
    //   while (getline(*arquivo, linha)) {
    //     cb(linha);
    //   }
    // }
};
