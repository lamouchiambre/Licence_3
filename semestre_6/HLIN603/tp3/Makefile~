GPP = g++
SRC = main.cpp CompteBancaire.cpp CompteDepot.cpp CompteRemunere.cpp   #Strophe.cpp
OBJ = $(SRC:%.cc=%.o)
EXE = main

all: $(OBJ)
	$(GPP) -o $(EXE) $(OBJ)

clean:
	rm -f *~ *.o $(EXE)

.SUFFIXES: .cpp .o

%.o: %.cpp
	$(GPP) -c $<