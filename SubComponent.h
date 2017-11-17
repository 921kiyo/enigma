#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include "Component.h"
#include <vector>

using namespace std;

class SubComponent: public Component{
private:
  // C++ 11 default value initialization
  static const int PAIR_SIZE_{13};
  // Plugboard not necessarily SIZE 13???
  // This could be vector
  vector<int> input_pair1_;
  vector<int> input_pair2_;
public:
  SubComponent(const vector<int> contacts);
  void setConfig(const vector<int> contacts);
  int map(int input);
};

#endif
