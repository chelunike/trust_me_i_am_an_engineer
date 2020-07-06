#############################################################################
# Sesión 7 Practicas
#############################################################################

HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include


all:  $(BIN)/I_EncuentraInicioPalabras
	@echo "ALL DONE"


# EJECUTABLES

$(BIN)/I_EncuentraInicioPalabras : $(OBJ)/I_EncuentraInicioPalabras.o 
	@echo "Creando ejecutable: I_EncuentraInicioPalabras"
	g++ -o $(BIN)/I_EncuentraInicioPalabras $(OBJ)/I_EncuentraInicioPalabras.o 

$(BIN)/II-FactoresPrimos_VectorDinamicoPrimos : \
				$(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o \
				$(LIB)/libFuncsVectorDinamico.a 
	@echo "Creando ejecutable: II-FactoresPrimos_VectorDinamicoPrimos"
	g++ -o $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos \
			$(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o \
			-lFuncsVectorDinamico -L$(LIB)

#................................................
# OBJETOS 

$(OBJ)/I_EncuentraInicioPalabras.o : $(SRC)/I_EncuentraInicioPalabras.cpp \
					  $(INCLUDE)/I_EncuentraInicioPalabras.h 
	@echo Creando objeto: I_EncuentraInicioPalabras.o
	g++ -c -o $(OBJ)/I_EncuentraInicioPalabras.o $(SRC)/I_EncuentraInicioPalabras.cpp \
		-I$(INCLUDE) -std=c++11

$(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o : \
				$(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp \
				$(INCLUDE)/FuncsVectorDinamico.h 
	@echo Creando objeto: II-FactoresPrimos_VectorDinamicoPrimos.o
	g++ -c -o $(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o \
		$(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp \
		-I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS

# (Vector Dinámico) ........................

$(LIB)/libFuncsVectorDinamico.a : \
	$(OBJ)/FuncsVectorDinamico.o
	@echo "Creando biblioteca: libFuncsVectorDinamico.a"
	ar rvs $(LIB)/libFuncsVectorDinamico.a \
		$(OBJ)/FuncsVectorDinamico.o

$(OBJ)/FuncsVectorDinamico.o : \
	$(SRC)/FuncsVectorDinamico.cpp \
	$(INCLUDE)/FuncsVectorDinamico.h
	@echo "Creando objeto: FuncsVectorDinamico.o"
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o \
		$(SRC)/FuncsVectorDinamico.cpp \
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


