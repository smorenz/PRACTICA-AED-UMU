CXX	:=	g++
SRC	:=	src
OBJ	:=	obj
CPPFLAGS := -std=c++17 -Wall -Wno-deprecated -O2

VPATH := ./src ./obj

all : a.out

a.out : main.o DicPalabras.o
	$(CXX) $(OBJ)/main.o $(OBJ)/DicPalabras.o $(CPPFLAGS)

main.o : main.cpp DicPalabras.h
	$(CXX) -c $(SRC)/main.cpp -o $(OBJ)/$@ $(CPPFLAGS)

DicPalabras.o : DicPalabras.cpp DicPalabras.h
	$(CXX) -c $(SRC)/DicPalabras.cpp -o $(OBJ)/$@ $(CPPFLAGS)

clean:
	rm -f ./a.out $(OBJ)/*.o
