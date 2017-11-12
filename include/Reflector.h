#ifndef REFLECTOR_H
#define REFLECTOR_H

const int PAIR_SIZE = 13;
class Reflector{
private:
  int pair_input_[PAIR_SIZE];
  int pair_output_[PAIR_SIZE];
public:
  Reflector(const char* path);
  int checkInput(const char* path);
  void mapInput(const char* path);
  int convertForward(int input);
};

#endif
