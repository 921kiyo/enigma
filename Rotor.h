#ifndef ROTOR_H
#define ROTOR_H

const int ALPHABET_LENGTH = 26;
class Rotor{
private:
  int contacts[ALPHABET_LENGTH];
  int current_position;
  int num_of_notches;
  int* notches;
public:
  Rotor(const char* path_rot, int start_position);
  int check_input(const char* path_rot);
  void map_input(const char* path, int start_position);
  void rotate_forward();
  int convert_forward(int input_index);
  int convert_backward(int input_index);
  int get_current_position();
  bool is_current_position_in_notch();
};

#endif
