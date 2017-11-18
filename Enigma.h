#ifndef ENIGMA_H
#define ENIGMA_H

#include "Component.h"
#include "Rotor.h"
#include <vector>

using namespace std;

class Enigma{
private:
const int ALPHABET_LENGTH_{26};
vector<Rotor> rotors_;
vector<int> rotor_positions_;
int num_of_rotors_;
Component *plugboard_{nullptr};
Component *reflector_{nullptr};
public:
  Enigma(int argc, char** argv);
  ~Enigma();
  void encryptMessage(char& letter);
  // TODO Change the order of methods
  /* 4 checking methods could be abstracted into 1. However, since each config
  error message has different error code, I made 4 separate methods for each */
  void checkPlugboardConfig(const char* path, vector<int>& contacts);
  void checkReflectorConfig(const char* path, vector<int>& contacts);
  void checkRotorConfig(const char* path, vector<int>& contacts);
  void checkRotorPositionConfig(const char* path);
  void mapInputToArray(const char* path, int* array);
  bool isNumberRangeCorrect(int num);
  bool isDuplicateInt(vector<int> contacts, int range);
  int isAppearedBefore(vector<int> contacts, int num, int position);
};

#endif
