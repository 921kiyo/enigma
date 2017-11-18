#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include "Component.h"
#include <vector>

class SubComponent: public Component{
private:
  // C++ 11 default value initialization
  static const int PAIR_SIZE_{13};
  std::vector<int> input_pair1_;
  std::vector<int> input_pair2_;
public:
  SubComponent(const char* path);
  int map(int input);
};

#endif
