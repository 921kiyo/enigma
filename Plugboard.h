#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "SubComponent.h"

class Plugboard: public SubComponent{
public:
  Plugboard(const char* path);
  virtual void throwNonNumericCharacterError();
  virtual void throwInvalidMappingError();
  virtual void throwConfigError();
};

#endif
