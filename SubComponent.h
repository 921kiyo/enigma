#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include "Component.h"

class SubComponent: public Component{
private:
  // C++ 11 default value initialization
  static const int PAIR_SIZE_{13};
  // Plugboard not necessarily SIZE 13???
  // This could be vector
  int input_pair1_[PAIR_SIZE_] = {0};
  int input_pair2_[PAIR_SIZE_] = {0};
public:
  SubComponent(const char* path);
  void setConfig(const char* path);
  int map(int input);
};

#endif
