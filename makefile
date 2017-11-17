EXE = enigma
CC = g++
CFLAGS = -Wall -g -std=c++11


SRC_FILES = $(wildcard *.cpp)
HEADER_FILES = $(wildcard *.h)

# ARG = ./$(EXE) plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot \
# rotors/III.rot rotors/I.pos < input.txt > output.txt

# ARG = ./$(EXE) plugboards/plugboard.pb reflectors/reflector.rf rotors/rotor.rot rotors/rotor2.rot rotors/rotor.pos < input.txt > output.txt

# No command line arguments given
# ARG = ./$(EXE)
# Non-numeric character in plugboard file (file contains "abc")
# ARG = ./$(EXE) plugboards/plugboard.pb reflectors/reflector.rf rotors/rotor.rot rotors/rotor.pos < input.txt > output.txt

# ARG = ./$(EXE) plugboards/I.pb reflectors/I.rf < input.txt > output.txt

# Non-numeric character in plugboard file (file contains "14x")

# No starting position
ARG = ./$(EXE) plugboards/plugboard.pb reflectors/reflector.rf rotors/rotor.rot rotors/rotor.pos < input.txt > output.txt


# ARG = ./$(EXE) plugboards/plugboard.pb reflectors/reflector.rf rotors/rotor.rot rotors/rotor.pos < input.txt > output.txt

# run: $(EXE)
# 	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all $(ARG)
# run: $(EXE)
# 	$(ARG)

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

clean:
	rm -f $(EXE)

.PHONY: clean
