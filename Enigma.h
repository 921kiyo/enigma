#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

class Enigma{
private:
Rotor **rotors;

public:
  Enigma(int argc, char** argv);
  // at least 3 rotors

};

#endif
