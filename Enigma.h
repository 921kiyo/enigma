#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

using namespace std;

class Enigma{
private:
Rotor **rotors;
int num_of_rotors;
Plugboard *plugboard;
Reflector *reflector;

public:
  Enigma(int argc, char** argv);
  // at least 3 rotors
  // They could be private
  int get_rotor_position(const char* path, int position);
  void encrypt_message(const char* message, char* encrypted_message);
  void rotor_process(int& current_index);
};

#endif
