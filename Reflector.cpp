#include "Reflector.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Reflector::Reflector(const char* path){
  int counter = 0;
  setConfig(path);
}

void Reflector::throwConfigError(){
  cerr << INVALID_REFLECTOR_MAPPING << endl;
}

void Reflector::throwNonNumericCharacterError(){
  cerr << "Non-numeric character in reflector file reflector.rf"  << endl;
}

void Reflector::throwInvalidMappingError(){
  throw(INVALID_REFLECTOR_MAPPING);
}
