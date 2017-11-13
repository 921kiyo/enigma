#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "SubComponent.h"

class Reflector: public SubComponent{
public:
  Reflector(const char* path);
  int checkParameters(const int counter);
  void returnConfigError();
};

#endif
