CXX	:=	g++
SRC	:=	src
OBJ	:=	obj
CPPFLAGS := -std=c++17 -Wall -Wno-deprecated -O2
OBJS := $(addprefix obj/,DicPalabras.o main.o)
VPATH := ./src ./obj

all : a.out

a.out : $(OBJS)
	$(CXX) $? -o ./a.out $(CPPFLAGS)

%.o : %.cpp
	$(CXX) -c $< -o ./obj/$@ $(CPPFLAGS)
clean:
	rm -f ./a.out $(OBJ)/*.o
