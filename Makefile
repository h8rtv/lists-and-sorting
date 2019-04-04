NAME=lista-de-clientes

C_SOURCE = $(wildcard src/*.cpp) \
	$(wildcard src/Pessoa/*.cpp) \
	$(wildcard src/ListaSequencial/*.cpp) \
	$(wildcard src/ListaEncadeada/*.cpp) \
	$(wildcard src/Leitor/*.cpp) \
	$(wildcard src/Principal/*.cpp)

H_SOURCE = $(wildcard src/*.h) \
	$(wildcard src/Pessoa/*.h) \
	$(wildcard src/ListaSequencial/*.h) \
	$(wildcard src/ListaEncadeada/*.h) \
	$(wildcard src/Leitor/*.h) \
	$(wildcard src/Principal/*.h)
 
OBJ = $(C_SOURCE:.c=.o)

COMPILER_FLAGS = -c \
	-W \
	-Wall \
	-ansi \
	-pedantic

COMPILER = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) -o $@ $^

%.o: %.c %.h
	$(COMPILER) -o $@ $< $(COMPILER_FLAGS)

main.o: src/main.cpp $(H_SOURCE)
	$(COMPILER) -o $@ $< $(COMPILER_FLAGS)

clean:
	rm -rf *.o $(NAME) *~