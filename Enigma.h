#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

class Enigma{
private:
  Plugboard* plugboard;
  Reflector* reflector;
public:
  Enigma(Plugboard* _plugboard, Reflector* _reflector );
  // at least 3 rotors

};

#endif
