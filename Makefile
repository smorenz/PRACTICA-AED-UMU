a.out : main.o DicPalabras.o
	g++ main.o DicPalabras.o

main.o : main.cpp DicPalabras.h
	g++ -c main.cpp

DicPalabras.o : DicPalabras.cpp DicPalabras.h
	g++ -c DicPalabras.cpp