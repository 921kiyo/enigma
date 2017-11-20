EXE = enigma
CC = g++
CFLAGS = -Wall -g -std=c++11

SRC_FILES = $(wildcard *.cpp)
HEADER_FILES = $(wildcard *.h)
OBJ_FILES = $(wildcard *.o)
GCH_FILES = $(wildcard *.h.gch)

ARG = ./$(EXE) plugboards/I.pb reflectors/I.rf < input.txt > output.txt

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

clean:
	rm -f $(EXE) $(OBJ_FILES) $(GCH_FILES)

.PHONY: clean
