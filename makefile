EXE = enigma
CC = g++
CFLAGS = -I include -Wall -g -O0 -std=c++11

TEST_DIR = test

SRC_FILES = $(wildcard *.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*cpp)
# Exclude tester.cpp
TEST_FILES := $(filter-out $(TEST_DIR)/tester.cpp, $(TEST_FILES))
HEADER_FILES = $(wildcard *.h)

ARG = ./$(EXE) plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot \
rotors/III.rot rotors/I.pos < input.txt > output.txt

# run: $(EXE)
# 	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all $(ARG)

$(EXE): main.cpp $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) main.cpp $(SRC_FILES) -o $(EXE)

tester.o: $(TEST_DIR)/tester.cpp
	$(CC) -o tester.o -c $(TEST_DIR)/tester.cpp $(CFLAGS)

tester: tester.o $(TEST_FILES) $(SRC_FILES) $(HEADER_FILES)
	$(CC) -o tester $(TEST_FILES) tester.o $(SRC_FILES) $(CFLAGS)

runtest: tester
	$(ARG)

clean:
	rm -f $(EXE) tester tester.o

.PHONY: clean test
