#ifndef ROTOR_H
#define ROTOR_H

#include <vector>

using namespace std;

class Rotor{
private:
  // C++ 11 default value initialization
  static const int ALPHABET_LENGTH_{26};
  // This attribute keeps track of A's letter position
  int current_position_;
  // This attribute is used to compare with current_position to see
  // whether the next rotor should rotate, when a notche is triggered.
  int previous_position_;
  // Store first 26 letter index
  int contacts_[ALPHABET_LENGTH_];
  int num_of_notches_;
  vector<int> notches_;
public:
  // Within this constructor, it gets all inputs from the file and assign them
  // to contacts_ and notches_. It also gets num_of_notches_
  // and set the starting position to current_position_.
  Rotor(const char* path, int start_position);
  // Updates current_position_ and previous_position_
  void rotate();
  // TODO Needs explanation here
  int shiftUp(int input_index);
  int shiftDown(int input_index);
  // Return contact by index
  int mapForward(int input_index);
  // Return index by contact
  int mapBackward(int contact);
  int getCurrentPosition();
  int getPreviousPosition();
  bool isCurrentPositionInNotch();
};

#endif
