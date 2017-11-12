#ifndef PLUGBOARD_H
#define PLUGBOARD_H

const int PAIR_MAX_SIZE = 13;
class Plugboard{
private:
  // TODO change name here
  int pair_input_[PAIR_MAX_SIZE];
  int pair_output_[PAIR_MAX_SIZE];
public:
  Plugboard(const char* path);
  int checkInput(const char* path);
  void mapInput(const char* path);
  int convertForward(int input);
};

#endif
