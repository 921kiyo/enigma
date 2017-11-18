#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include <vector>

class Component{
private:
  // C++ 11 default value initialization
  static const int ALPHABET_LENGTH_{26};
  static const int PAIR_SIZE_{13};
  std::vector<int> input_pair1_;
  std::vector<int> input_pair2_;
public:
  Component(const char* path);
  int map(int input);
};

#endif
