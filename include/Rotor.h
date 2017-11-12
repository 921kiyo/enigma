#ifndef ROTOR_H
#define ROTOR_H

const int ALPHABET_LENGTH = 26;
class Rotor{
private:
  int contacts_[ALPHABET_LENGTH];
  int current_position_;
  int num_of_notches_;
  int* notches_;
public:
  Rotor(const char* path_rot, int start_position);
  ~Rotor();
  int checkInput(const char* path_rot);
  void mapInput(const char* path, int start_position);
  void rotateForward();
  int convertForward(int input_index);
  int convertBackward(int input_index);
  int getCurrentPosition();
  bool isCurrentPositionInNotch();
};

#endif
