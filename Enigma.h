#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
#include <vector>

using namespace std;

class Enigma{
private:
// Rotor **rotors_;
vector<Rotor> rotors_;
int num_of_rotors_;
Plugboard *plugboard_;
Reflector *reflector_;
bool is_plugboard_initialized{false};
bool is_reflector_initialized{false};
public:
  Enigma(int argc, char** argv);
  ~Enigma();
  // They could be private
  int getRotorPosition(const char* path, int position);
  void encryptMessage(char& message);
  void rotorProcess(int& current_index);
};

#endif
