#ifndef ROTOR_H
#define ROTOR_H

#include "Component.h"

class Rotor: public Component{
private:
  int contacts_[ALPHABET_LENGTH_];
  int current_position_;
  int num_of_notches_;
  int* notches_;
public:
  Rotor(const char* path_rot, int start_position);
  ~Rotor();
  void mapInput(const char* path);
  void rotateForward();
  int convertForward(int input_index);
  int convertBackward(int input_index);
  int getCurrentPosition();
  bool isCurrentPositionInNotch();
};

#endif
