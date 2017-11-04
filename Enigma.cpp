#include <iostream>
#include "Enigma.h"

using namespace std;

Enigma::Enigma(Plugboard* _plugboard, Reflector* _reflector ){
  plugboard = _plugboard;
  reflector = _reflector;
}
