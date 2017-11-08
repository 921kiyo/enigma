#ifndef REFLECTOR_H
#define REFLECTOR_H

const int PAIR_SIZE = 13;
class Reflector{
private:
  int pair_input[PAIR_SIZE];
  int pair_output[PAIR_SIZE];
public:
  Reflector(const char* path);
  int check_input(const char* path);
  int convert_forward(int input);
};

#endif
