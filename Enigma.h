#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

class Enigma{
private:
Rotor **rotors_;
int num_of_rotors_;
Plugboard *plugboard_;
Reflector *reflector_;

public:
  Enigma(int argc, char** argv);
  ~Enigma();
  // at least 3 rotors
  // They could be private
  // void getExtension(const char* path, char* extension);
  // cout << "extension " << extension << endl;
  int getRotorPosition(const char* path, int position);
  void encryptMessage(const char* message, char* encrypted_message);
  void rotorProcess(int& current_index);
};

#endif
