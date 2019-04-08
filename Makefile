NAME=lista-de-clientes

C_SOURCE = $(wildcard src/*.cpp) \
  $(wildcard src/Pessoa/*.cpp) \
  $(wildcard src/ListaSequencial/*.cpp) \
  $(wildcard src/ListaEncadeada/*.cpp) \
  $(wildcard src/Leitor/*.cpp) \
  $(wildcard src/Principal/*.cpp)
 
COMPILER_FLAGS = -std=c++11

COMPILER = g++

all: compile

compile:
	$(COMPILER) $(COMPILER_FLAGS) -o $(NAME) $(C_SOURCE)

clean:
	rm -rf *.o $(NAME) *~