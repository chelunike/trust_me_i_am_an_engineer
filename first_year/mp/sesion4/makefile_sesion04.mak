
# Variables
SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
LIB = ./lib


# Regla Principal
all: $(BIN)/Ejercicio7 $(BIN)/Ejercicio8 $(BIN)/Ejercicio9
	@echo "ALL DONE"


# Reglas para los Ejecutables
$(BIN)/Ejercicio7: $(OBJ)/I_PosMayor_Basico.o \
			$(LIB)/libGeneradorAleatorioEnteros.a \
			$(OBJ)/FuncionesEj7.o
	g++ -o $(BIN)/Ejercicio7 -I $(INCLUDE) \
		-l GeneradorAleatorioEnteros -L $(LIB) \
		$(OBJ)/I_PosMayor_Basico.o $(OBJ)/FuncionesEj7.o \
		$(OBJ)/GeneradorAleatorioEnteros.o

$(BIN)/Ejercicio8: $(OBJ)/I_OrdenaVector.o \
			$(LIB)/libGeneradorAleatorioEnteros.a \
			$(OBJ)/FuncionesEj8.o
	g++ -o $(BIN)/Ejercicio8 -I $(INCLUDE) \
		-l GeneradorAleatorioEnteros -L $(LIB) \
		$(OBJ)/I_OrdenaVector.o $(OBJ)/FuncionesEj8.o \
		$(OBJ)/GeneradorAleatorioEnteros.o

$(BIN)/Ejercicio9: $(OBJ)/I_OrdenayMezclaVectores.o \
			$(LIB)/libGeneradorAleatorioEnteros.a \
			$(OBJ)/FuncionesEj9.o
	g++ -o $(BIN)/Ejercicio9 -I $(INCLUDE) \
		-l GeneradorAleatorioEnteros -L $(LIB) \
		$(OBJ)/I_OrdenayMezclaVectores.o $(OBJ)/FuncionesEj9.o \
		$(OBJ)/GeneradorAleatorioEnteros.o

$(OBJ)/I_PosMayor_Basico.o : $(SRC)/I_PosMayor_Basico.cpp \
			$(INCLUDE)/GeneradorAleatorioEnteros.h	
	g++ -c -o $(OBJ)/I_PosMayor_Basico.o \
		$(SRC)/I_PosMayor_Basico.cpp -I $(INCLUDE) -std=c++11

$(OBJ)/I_OrdenaVector.o : $(SRC)/I_OrdenaVector.cpp \
			$(INCLUDE)/GeneradorAleatorioEnteros.h	
	g++ -c -o $(OBJ)/I_OrdenaVector.o \
		$(SRC)/I_OrdenaVector.cpp -I $(INCLUDE) -std=c++11

$(OBJ)/I_OrdenayMezclaVectores.o : $(SRC)/I_OrdenayMezclaVectores.cpp \
			$(INCLUDE)/GeneradorAleatorioEnteros.h	
	g++ -c -o $(OBJ)/I_OrdenayMezclaVectores.o \
		$(SRC)/I_OrdenayMezclaVectores.cpp -I $(INCLUDE) -std=c++11

# Clases y librerias

$(OBJ)/GeneradorAleatorioEnteros.o: $(SRC)/GeneradorAleatorioEnteros.cpp \
			$(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
		-I $(INCLUDE) -std=c++11 \
		$(SRC)/GeneradorAleatorioEnteros.cpp

$(LIB)/libGeneradorAleatorioEnteros.a: $(OBJ)/GeneradorAleatorioEnteros.o
	ar rvs $(LIB)/libGeneradorAleatorioEnteros.a \
		$(OBJ)/GeneradorAleatorioEnteros.o

$(LIB)/libFuncionesEj7.a: $(OBJ)/FuncionesEj7.o
	ar rvs $(LIB)/libFuncionesEj7.a \
		$(OBJ)/FuncionesEj7.o

$(LIB)/libFuncionesEj8.a: $(OBJ)/FuncionesEj8.o
	ar rvs $(LIB)/libFuncionesEj8.a \
		$(OBJ)/FuncionesEj8.o

$(OBJ)/FuncionesEj7.o: $(SRC)/FuncionesEj7.cpp \
			$(INCLUDE)/FuncionesEj7.h
	g++ -c -o $(OBJ)/FuncionesEj7.o \
		-I $(INCLUDE) -std=c++11 \
		$(SRC)/FuncionesEj7.cpp

$(OBJ)/FuncionesEj8.o: $(SRC)/FuncionesEj8.cpp \
			$(INCLUDE)/FuncionesEj8.h
	g++ -c -o $(OBJ)/FuncionesEj8.o \
		-I $(INCLUDE) -std=c++11 \
		$(SRC)/FuncionesEj8.cpp

$(OBJ)/FuncionesEj9.o: $(SRC)/FuncionesEj9.cpp \
			$(INCLUDE)/FuncionesEj9.h
	g++ -c -o $(OBJ)/FuncionesEj9.o \
		-I $(INCLUDE) -std=c++11 \
		$(SRC)/FuncionesEj9.cpp

# Reglas de Limpieza

clean: 
	-rm $(OBJ)/* 
	@echo "Clean Done"

mr.proper: clean
	-rm $(BIN)/*
	@echo "Super clean Done"


