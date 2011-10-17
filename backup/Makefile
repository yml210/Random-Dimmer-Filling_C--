CC=gcc
CXX=g++
INCLUDE_DIR= .
CPPFLAG= -g
#CPPFLAG= -g -I$(INCLUDE_DIR)

OBJ=  Site.o Lattice.o Dimer.o Dimers.o main.o

dimer.exe: $(OBJ)
	$(CXX) $(CPPFLAG) -o $@ $(OBJ)
