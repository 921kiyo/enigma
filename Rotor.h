#ifndef ROTOR_H
#define ROTOR_H

#include <vector>

using namespace std;

class Rotor{
private:
  // C++ 11 default value initialization
  static const int ALPHABET_LENGTH_{26};
  // TODO double check is this is necessary
  int current_position_;
  int previous_position_;

  int contacts_[ALPHABET_LENGTH_];

  int num_of_notches_;
  vector<int> notches_;
public:
  Rotor(const char* path, int start_position);
  void rotate();
  int shiftUp(int input_index);
  int shiftDown(int input_index);
  int mapForward(int input_index);
  int mapBackward(int input_index);
  int getCurrentPosition();
  int getPreviousPosition();
  bool isCurrentPositionInNotch();
};

#endif
