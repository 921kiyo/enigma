#ifndef ROTOR_H
#define ROTOR_H

#include "Component.h"
#include <vector>

using namespace std;

class Rotor: public Component{
private:
  int contacts_[ALPHABET_LENGTH_];
  // Default value okay??
  int current_position_{-1};
  int previous_position_{-1};
  int num_of_notches_;
  vector<int> notches_;
public:
  Rotor(const char* path_rot, int start_position);
  void setConfig(const char* path);
  void rotate();
  int shiftUp(int input_index);
  int shiftDown(int input_index);
  int map(int input_index);
  int mapBackward(int input_index);
  int getCurrentPosition();
  int getPreviousPosition();
  bool isCurrentPositionInNotch();
  virtual void throwNonNumericCharacterError();
  virtual void throwInvalidMappingError();
};

#endif
