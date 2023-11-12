CXX	:=	g++
SRC	:=	src
OBJ	:=	obj
CPPFLAGS := -std=c++17 -Wall -Wno-deprecated -O2
OBJS := $(addprefix ./obj/,DicPalabrasLista.o main.o)
VPATH := ./$(SRC) ./$(OBJ)

all : a.out

a.out : $(OBJS)
	$(CXX) $? -o ./a.out $(CPPFLAGS)

%.o : %.cpp
	$(CXX) -c $< -o $@ $(CPPFLAGS)
	
clean:
	rm -f ./a.out $(OBJ)/*.o
