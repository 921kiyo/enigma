OBJ = main.o Plugboard.o Reflector.o Rotor.o
EXE = enigma
GPP = g++
DEBUG = -Wall -g

$(EXE): $(OBJ)
	$(GPP) $(OBJ) -o $@

%.o: %.cpp
	$(GPP) $(DEBUG) -c $<

main.o: Enigma.h errors.h

Plugboard.o: Plugboard.h

Reflector.o: Reflector.h

Rotor.o: Rotor.h

clean:
	rm -f $(OBJ) $(EXE)

.PHONY: clean

# enigma: main.cpp errors.h
# 	g++ -Wall -g main.cpp -o enigma
