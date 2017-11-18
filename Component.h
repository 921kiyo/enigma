#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include <vector>

class Component{
private:
  // C++ 11 default value initialization
  static const int ALPHABET_LENGTH_{26};
  std::vector<int> input_pair1_;
  std::vector<int> input_pair2_;
public:
  // Within this constructor, it gets all inputs from the file and assign them
  // to input_pair1_ and input_pair2_ vectors.
  Component(const char* path);

  int map(int input);
};

#endif
