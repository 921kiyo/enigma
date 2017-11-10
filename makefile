OBJ = main.o Enigma.o Plugboard.o Reflector.o Rotor.o helper.o
EXE = enigma
GPP = g++
DEBUG = -Wall -g

$(EXE): $(OBJ)
	$(GPP) $(OBJ) -o $@

%.o: %.cpp
	$(GPP) $(DEBUG) -c $<
# include -MMD
main.o: Enigma.h errors.h

Enigma.o: Enigma.h Plugboard.h Reflector.h Rotor.h helper.h errors.h

Plugboard.o: Plugboard.h helper.h errors.h

Reflector.o: Reflector.h helper.h errors.h

Rotor.o: Rotor.h helper.h errors.h

helper.o: helper.h

clean:
	rm -f $(OBJ) $(EXE)

# Even if a file called clean exists, clean command will always run when PHONY exists
.PHONY: clean

# enigma: main.cpp errors.h
# 	g++ -Wall -g main.cpp -o enigma
