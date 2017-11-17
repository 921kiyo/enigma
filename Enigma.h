#ifndef ENIGMA_H
#define ENIGMA_H

#include "SubComponent.h"
#include "Rotor.h"
#include <vector>

using namespace std;

class Enigma{
private:
const int ALPHABET_LENGTH_{26};
vector<Rotor> rotors_;
vector<int> rotor_positions_;
int num_of_rotors_;
SubComponent *plugboard_{nullptr};
SubComponent *reflector_{nullptr};
public:
  Enigma(int argc, char** argv);
  ~Enigma();
  // They could be private
  void initialiseRotorPosition(const char* path);
  void checkRotorAndRotorPosition();
  void encryptMessage(char& message);
  // TODO Change the order of methods
  void checkPlugboardConfig(const char* path);
  void checkReflectorConfig(const char* path);
  void checkRotorConfig(const char* path);
  void checkRotorPositionConfig(const char* path);


  // int checkInput(const char* path);
  // void checkParameters(const int counter);
  // void throwConfigError();
  // void throwNonNumericCharacterError();
  // void throwInvalidMappingError();
  // Do I need this??
  int getArrayLength(const char* path);
  void mapInputToArray(const char* path, int* array);
  bool isNumberRangeCorrect(int num);
  void checkDuplicateInt(int* array, int range);
  int isAppearedBefore(int* array, int num, int position);
};

#endif
