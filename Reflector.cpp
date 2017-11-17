#include "Reflector.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Reflector::Reflector(const char* path){
  int counter = 0;
  // counter = checkInput(path);
  setConfig(path);
  checkParameters(counter);
}

void Reflector::checkParameters(const int counter){
    if(counter%2!=0){
      cerr << "Incorrect (odd) number of parameters in reflector file reflector.rf" << endl;
      throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
    }
    if(counter != ALPHABET_LENGTH_){
      cerr << "Insufficient number of mappings in reflector file: reflector.rf" << endl;
      throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
    }
    // What happens if more than 26 parameters

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
