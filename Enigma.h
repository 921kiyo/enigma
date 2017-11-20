#ifndef ENIGMA_H
#define ENIGMA_H

#include "Component.h"
#include "Rotor.h"
#include <fstream>
#include <vector>

using namespace std;

class Enigma{
private:
vector<Rotor> rotors_;
vector<int> rotor_positions_;
// Even though I could easily get the number of rotors from rotors_,
// I store this as an attribute, because I use it frequently
// (e.g if statement, for loop etc).
int num_of_rotors_;
// C++ 11 default initialisation + use of nullptr
// Plubboard and reflector are initialized after all input error check is done,
// so that there is no concern for memory leak when an exception is thrown.
Component *plugboard_{nullptr};
Component *reflector_{nullptr};
public:
  // Within this constructor, check all input files are valid by calling
  // each "checkXXXConfig" method.
  // Initialise all the components after all the check is done, so that, if
  // exception is thrown while checking config, it throws an error to main
  // before a new heap is created in order to avoid unpredictable memory leak.
  Enigma(int argc, char** argv);
  // Free up plugboard and reflector heap in the destructor
  ~Enigma();
  // These 4 checkConfig methods check each input file by extracting input
  // and check if each input is valid (and throws exception error
  // as defined in the spec).
  // They also assign each valid integer to corresponding vectors.
  void checkPlugboardConfig(const char* path, vector<int>& contacts);
  // This is a helper method for checking if inputs are valid for plugboard
  // The reason this is in a separate method is that the numbers in plugboard
  // have to be read off in pairs (as defined in the spec). Thus, unlike other
  // checkConfig methods, I call istream twice in every while loop iteration.
  bool isPlugboardInputValid(const char* path, fstream& in_stream, int& index_num);
  void checkReflectorConfig(const char* path, vector<int>& contacts);
  void checkRotorConfig(const char* path, vector<int>& contacts);
  void checkRotorPositionConfig(const char* path);
  // Check if num is within the range of 0-25
  bool isNumberRangeCorrect(int num);
  // Check if num is already appeared in contacts.
  // If yes, return the index of the previous contact. Otherwise return -1
  int checkAppearedBefore(vector<int> contacts, int num, int position);
  // This method does whole encryption process
  // and convert a letter into encrypted one.
  void encryptMessage(char& letter);
};

#endif
