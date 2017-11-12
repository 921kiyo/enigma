EXE = enigma
CC = g++
CFLAGS = -Wall -g -O0 -std=c++11

SRC_DIR = src
TEST_DIR = test

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

TEST_FILES = $(wildcard $(TEST_DIR)/*cpp)
# Exclude tester.cpp
TEST_FILES := $(filter-out $(TEST_DIR)/tester.cpp, $(TEST_FILES))

INC_DIR = -I include
HEADER_FILES = $(wildcard $(INC_DIR)/*.h)

# run: $(EXE)
# 	valgrind --leak-check=full --show-leak-kinds=all  ./$(EXE) plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < input.txt > output.txt

$(EXE): main.cpp $(SRC_FILES) $(HEADER_FILES)
	$(CC) -o $(EXE) main.cpp $(SRC_FILES) -I $(INC_DIR) $(CFLAGS)

tester.o: $(TEST_DIR)/tester.cpp
	$(CC) -o tester.o -c $(TEST_DIR)/tester.cpp $(CFLAGS) \
		-I $(INC_DIR)

tester: tester.o $(TEST_FILES) $(SRC_FILES) $(HEADER_FILES)
	$(CC) -o tester $(TEST_FILES) tester.o $(SRC_FILES) -I $(INC_DIR) $(CFLAGS)

clean:
	rm -f $(EXE) tester tester.o

.PHONY: clean test
