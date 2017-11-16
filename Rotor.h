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
  // int* notches_;
  vector<int> notches_;
public:
  Rotor(const char* path_rot, int start_position);
  ~Rotor();
  void mapInput(const char* path);
  void rotateUp();
  void rotateDown();
  int shuffleUp(int input_index);
  int shuffleDown(int input_index);
  int convertForward(int input_index);
  int convertBackward(int input_index);
  int getCurrentPosition();
  int getPreviousPosition();
  bool isCurrentPositionInNotch();
  virtual void returnNonNumericCharacterError();
};

#endif
