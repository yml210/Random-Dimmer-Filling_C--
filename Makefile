CC=gcc
CXX=g++
LD=ld
INCLUDE_DIR= .
#CFLAGS= -g -I$(INCLUDE_DIR)
CPPFLAGS= -g -I$(INCLUDE_DIR)

OBJ=  Site.o Lattice.o Dimer.o Dimers.o main.o

dimer.exe: $(OBJ)
	$(CXX) $(CPPFLAGS) -o $@ $(OBJ)
