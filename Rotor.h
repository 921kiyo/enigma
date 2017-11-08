#ifndef ROTOR_H
#define ROTOR_H

const int ALPHABET_LENGTH = 26;
class Rotor{
private:
  int contacts[ALPHABET_LENGTH];
  int starting_position;
  int num_of_notches;
  int* notches;
public:
  Rotor(const char* path_rot, int position);
  int check_input(const char* path_rot);
  void rotate();
  bool is_key_pressed();
  void rotate_forward();
  void rotate_backward();
  int convert_forward(int input_index);
  int convert_backward(int input_index);
  int get_current_position();
  bool is_current_position_in_notch();
};

#endif
