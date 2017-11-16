EXE = enigma
CC = g++
CFLAGS = -Wall -g -std=c++11

TEST_DIR = test

SRC_FILES = $(wildcard *.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*cpp)
# Exclude tester.cpp
TEST_FILES := $(filter-out $(TEST_DIR)/tester.cpp, $(TEST_FILES))
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
ARG = ./$(EXE) plugboards/plugboard.pb reflectors/reflector.rf rotors/rotor.rot rotors/rotor.pos < input.txt > output.txt


TEST = ./$(EXE) plugboards/test.pb reflectors/test.rf rotors/test.rot rotors/test.rot \
rotors/test.rot rotors/test.pos < input.txt > output.txt

# run: $(EXE)
# 	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all $(ARG)
# run: $(EXE)
# 	$(ARG)

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

tester.o: $(TEST_DIR)/tester.cpp
	$(CC) -o tester.o -c $(TEST_DIR)/tester.cpp $(CFLAGS)

tester: tester.o $(TEST_FILES) $(SRC_FILES) $(HEADER_FILES)
	$(CC) -o tester $(TEST_FILES) tester.o $(SRC_FILES) $(CFLAGS)

runtest: tester
	$(ARG)

clean:
	rm -f $(EXE) tester tester.o

.PHONY: clean test
