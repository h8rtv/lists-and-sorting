#pragma once
#include <chrono>
#include <iostream>

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
typedef std::chrono::_V2::system_clock::time_point time_point;
typedef std::chrono::duration<double> duration;

struct Relatorio {
  Relatorio() {
    c = 0;
    m = 0;
    start = high_resolution_clock::now();
  }
  long c;
  long m;
  time_point start;
};

class Util {
  private:
    Util();
    Relatorio relatorio;
    bool running;
    void zerarRelatorio();
  public:
    ~Util();
    static Util& getInstance();
    void start();
    void addC(long _c = 1);
    void addM(long _m = 1);
    void stopAndPrint();
};

