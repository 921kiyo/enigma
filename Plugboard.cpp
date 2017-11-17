#include "Plugboard.h"
#include "SubComponent.h"
#include "fstream"
#include "errors.h"

#include <iostream>

using namespace std;

Plugboard::Plugboard(const char* path){
  setConfig(path);
}
