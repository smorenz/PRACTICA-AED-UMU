CXX	:=	g++
SRC	:=	src
OBJ	:=	obj
 
all: a.out

a.out : main.o DicPalabras.o
	$(CXX) $(OBJ)/main.o $(OBJ)/DicPalabras.o

main.o : $(SRC)/main.cpp $(SRC)/DicPalabras.h
	$(CXX) -c $(SRC)/main.cpp -o $(OBJ)/$@

DicPalabras.o : $(SRC)/DicPalabras.cpp $(SRC)/DicPalabras.h
	$(CXX) -c $(SRC)/DicPalabras.cpp -o $(OBJ)/$@

clean:
	rm -f a.out $(OBJ)/*.o
