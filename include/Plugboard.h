#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "SubComponent.h"

class Plugboard: public SubComponent{
public:
  Plugboard(const char* path);
  int checkParameters(const int counter);
  void returnConfigError();
};

#endif
