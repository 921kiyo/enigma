#ifndef ROTOR_H
#define ROTOR_H

#include "alphabet.h"
#include <vector>

using namespace std;

class Rotor{
private:
  // This attribute keeps track of A's letter position relative to
  // absolute position
  int current_position_;
  // This attribute is used to compare with current_position to see
  // whether the next rotor should rotate, when a notche is triggered.
  int previous_position_;
  // Store first 26 letter index
  int contacts_[ALPHABET_LENGTH];
  // Store after 26th letter index as notches
  vector<int> notches_;

public:
  // Within this constructor, it gets all inputs from the file and assign them
  // to contacts_ and notches_.
  // It also sets the starting position to current_position_.
  Rotor(const char* path, int start_position);
  // Getter
  int getCurrentPosition();
  // Getter
  int getPreviousPosition();
  // Updates current_position_ and previous_position_
  void rotate();
  // shiftUp and shiftDown calculates absolute position of input_index
  // by adding/subtructing current position of rotor.
  int shiftUp(int input_index);
  int shiftDown(int input_index);
  // Returns contact by index
  int mapForward(int input_index);
  // Returns index by contact
  int mapBackward(int contact);
  // Returns true is current_position_ is at a notch
  bool isCurrentPositionInNotch();
};

#endif
