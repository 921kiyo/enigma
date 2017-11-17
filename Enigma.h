#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
#include <vector>

using namespace std;

class Enigma{
private:
vector<Rotor> rotors_;
vector<int> rotor_positions_;
int num_of_rotors_;
Plugboard *plugboard_{nullptr};
Reflector *reflector_{nullptr};
public:
  Enigma(int argc, char** argv);
  ~Enigma();
  // They could be private
  void initialiseRotorPosition(const char* path);
  void checkRotorAndRotorPosition();
  void encryptMessage(char& message);
};

#endif
