#include "Reflector.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Reflector::Reflector(const char* path){
  setConfig(path);
}


void Reflector::throwInvalidMappingError(){
  throw(INVALID_REFLECTOR_MAPPING);
}
