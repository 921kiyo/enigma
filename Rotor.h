#ifndef ROTOR_H
#define ROTOR_H

const int ALPHABET_LENGTH = 26;
class Rotor{
private:
  int contacts[ALPHABET_LENGTH];
public:
  Rotor(const char* path);
  int check_input(const char* path);
  void rotate();
  bool is_key_pressed();
  void move_forward();
  void move_backward();
};

#endif
