#ifndef PLUGBOARD_H
#define PLUGBOARD_H

const int PAIR_MAX_SIZE = 13;
class Plugboard{
private:
  int pair_input[PAIR_MAX_SIZE];
  int pair_output[PAIR_MAX_SIZE];
public:
  Plugboard(const char* path);
  int check_input(const char* path);
  int convert_forward(int input);
};

#endif
