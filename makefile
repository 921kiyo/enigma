EXE = enigma
CC = g++
CFLAGS = -Wall -g -std=c++11
INC = -I include

SRC_DIR = src
TEST_DIR = test

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

TEST_FILES = $(wildcard $(TEST_DIR)/*cpp)
# Exclude tester.cpp
TEST_FILES := $(filter-out $(TEST_DIR)/tester.cpp, $(TEST_FILES))

INC_DIR = include
HEADER_FILES = $(INC_DIR)/*.h

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
