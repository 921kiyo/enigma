#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "SubComponent.h"

class Plugboard: public SubComponent{
public:
  Plugboard(const char* path);
  void checkParameters(const int counter);
  void throwConfigError();
  virtual void throwNonNumericCharacterError();
  virtual void throwInvalidMappingError();
};

#endif
