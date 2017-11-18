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
  // Within this constructor, check all input files are valid by calling
  // each "checkXXXConfig" method.
  // Initialise all the components after all the check is done, so that, if
  // exception is thrown while checking config, it throws an error before
  // a new heap is created in order to avoid unpredictable memory leak.
  Enigma(int argc, char** argv);
  // Free up plugboard and reflector heap
  ~Enigma();

  // These 4 methods check each input file by extracting input and check if
  // each input is valid. At the same time they also assign each valid integer
  // to corresponding vectors.
  void checkPlugboardConfig(const char* path, vector<int>& contacts);
  void checkReflectorConfig(const char* path, vector<int>& contacts);
  void checkRotorConfig(const char* path, vector<int>& contacts);
  void checkRotorPositionConfig(const char* path);

  // Check if num is within 0-25
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
