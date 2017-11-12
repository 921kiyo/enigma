#include "Reflector.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Reflector::Reflector(const char* path){
  checkInput(path);
  mapInput(path);
}

int Reflector::checkParameters(const int counter){
    if(counter != ALPHABET_LENGTH_){
      cout << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS " << endl;
      return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
    return NO_ERROR;
}

void Reflector::returnConfigError(){
    cout << INVALID_REFLECTOR_MAPPING << endl;
}
