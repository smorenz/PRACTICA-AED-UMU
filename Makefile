CXX := g++
SRC := src
OBJ := obj
CPPFLAGS := -std=c++17 -Wall -Wno-deprecated -O2
OBJS := $(addprefix ./obj/, DicPalabras.o main.o Comandos.o TablaHash.o)

all : ./a.out

a.out : $(OBJS)
	$(CXX) $^ -o ./a.out $(CPPFLAGS)

./obj/%.o : ./src/%.cpp
	test -d ./obj  || mkdir ./obj
	$(CXX) -c $< -o $@ $(CPPFLAGS)
	
clear :
	rm -f ./a.out $(OBJ)/*.o ./salida
