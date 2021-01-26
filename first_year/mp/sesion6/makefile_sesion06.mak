#############################################################################
# Sesión 6 Practicas
#############################################################################

HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include


all:  $(BIN)/I_MezclaArrays_ref
	@echo "ALL DONE"


# EJECUTABLES

$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o \
				$(LIB)/libSecuenciaEnteros.a 
	@echo "Creando ejecutable: I_MezclaArrays_ref"
	g++ -o $(BIN)/I_MezclaArrays_ref $(OBJ)/I_MezclaArrays_ref.o \
			-lSecuenciaEnteros -L$(LIB)

$(BIN)/I_DemoSecuenciaEnteros : \
				$(OBJ)/I_DemoSecuenciaEnteros.o \
				$(LIB)/libSecuenciaEnteros.a 
	@echo "Creando ejecutable: I_DemoSecuenciaEnteros"
	g++ -o $(BIN)/I_DemoSecuenciaEnteros \
			$(OBJ)/I_DemoSecuenciaEnteros.o \
			-lSecuenciaEnteros -L$(LIB)

#................................................
# OBJETOS 

$(OBJ)/I_MezclaArrays_ref.o : $(SRC)/I_MezclaArrays_ref.cpp \
					  $(INCLUDE)/SecuenciaEnteros.h 
	@echo Creando objeto: I_MezclaArrays_ref.o
	g++ -c -o $(OBJ)/I_MezclaArrays_ref.o $(SRC)/I_MezclaArrays_ref.cpp \
		-I$(INCLUDE) -std=c++11

$(OBJ)/I_DemoSecuenciaEnteros.o : \
				$(SRC)/I_DemoSecuenciaEnteros.cpp \
				$(INCLUDE)/SecuenciaEnteros.h 
	@echo Creando objeto: I_DemoSecuenciaEnteros.o
	g++ -c -o $(OBJ)/I_DemoSecuenciaEnteros.o \
		$(SRC)/I_DemoSecuenciaEnteros.cpp \
		-I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS

# (Vector Dinámico) ........................

$(LIB)/libSecuenciaEnteros.a : \
	$(OBJ)/SecuenciaEnteros.o
	@echo "Creando biblioteca: libSecuenciaEnteros.a"
	ar rvs $(LIB)/libSecuenciaEnteros.a \
		$(OBJ)/SecuenciaEnteros.o

$(OBJ)/SecuenciaEnteros.o : \
	$(SRC)/SecuenciaEnteros.cpp \
	$(INCLUDE)/SecuenciaEnteros.h
	@echo "Creando objeto: SecuenciaEnteros.o"
	g++ -c -o $(OBJ)/SecuenciaEnteros.o \
		$(SRC)/SecuenciaEnteros.cpp \
	   -I$(INCLUDE) -std=c++11


#................................................
# LIMPEZA

clean:
	@echo "Borrando objetos"
	-rm $(OBJ)/*

mr.proper:  clean
	@echo "Borrando bibliotecas y ejecutables"
	-rm $(BIN)/*
	-rm $(LIB)/*