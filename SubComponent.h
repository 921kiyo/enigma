#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include "Component.h"

class SubComponent: public Component{
protected:
  // C++ 11 default value initialization
  static const int PAIR_SIZE_{13};
  // Plugboard not necessarily SIZE 13???
  int input_pair1_[PAIR_SIZE_] = {0};
  int input_pair2_[PAIR_SIZE_] = {0};
public:
  // Could be protected
  void setConfig(const char* path);
  int map(int input);
  virtual void checkParameters(const int counter) = 0;
  virtual void throwConfigError() = 0;
  virtual void throwNonNumericCharacterError() = 0;
  virtual void throwInvalidMappingError() = 0;
};

#endif
