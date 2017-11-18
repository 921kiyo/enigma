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

  /* 4 checking methods could be abstracted into 1. However, since each config
  error message has different error code, I made 4 separate methods for each */
  void checkPlugboardConfig(const char* path, vector<int>& contacts);
  void checkReflectorConfig(const char* path, vector<int>& contacts);
  void checkRotorConfig(const char* path, vector<int>& contacts);
  void checkRotorPositionConfig(const char* path);

  bool isNumberRangeCorrect(int num);

  // Check if mapping is valid
  // (e.g duplicate contacts, a contact connected to itself etc.)
  bool checkMapping(vector<int> contacts, int range);

  // Check if num is already appeared in contacts.
  // If yes, return the index of the previous contact. Otherwise return -1
  int checkAppearedBefore(vector<int> contacts, int num, int position);

  // This method does whole encryption process
  // and convert letter into encrypted one.
  void encryptMessage(char& letter);
};

#endif
