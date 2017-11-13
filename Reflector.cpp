#include "Reflector.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Reflector::Reflector(const char* path){
  int counter;
  counter = checkInput(path);
  checkParameters(counter);
  mapInput(path);
}

void Reflector::checkParameters(const int counter){
    if(counter != ALPHABET_LENGTH_){
      throw INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
}

void Reflector::returnConfigError(){
    cout << INVALID_REFLECTOR_MAPPING << endl;
}
