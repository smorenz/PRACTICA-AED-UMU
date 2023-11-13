CXX := g++
SRC := src
OBJ := obj
CPPFLAGS := -std=c++17 -Wall -Wno-deprecated -O2
OBJS := DicPalabrasLista.o main.o

a.out : $(OBJS)
	$(CXX) $? $(CPPFLAGS)

%.o : %.cpp
	$(CXX) -c $< -o $@ $(CPPFLAGS)

tar :
	tar -cf archivo.tar *.cpp *.h Makefile
