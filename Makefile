CXX := g++
SRC := src
OBJ := obj
CPPFLAGS := -std=c++17 -Wall -Wno-deprecated -O2
OBJS := $(addprefix ./obj/, DicPalabrasLista.o main.o)

a.out : $(OBJS)
	$(CXX) $^ -o ./a.out $(CPPFLAGS)

./obj/%.o : ./src/%.cpp
	$(CXX) -c $< -o $@ $(CPPFLAGS)
	
clear :
	rm -f ./a.out $(OBJ)/*.o
