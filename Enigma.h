#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

using namespace std;

class Enigma{
private:
Rotor **rotors;
Plugboard *plugboard;
Reflector *reflector;

public:
  Enigma(int argc, char** argv);
  // at least 3 rotors
  int get_rotor_position(const char* path, int position);
  void encrypt_message(const char* message, char* encrypted_message);
};

#endif
