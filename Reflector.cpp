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
    if(counter%2!=0){
      // throw INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
      cerr << "Incorrect (odd) number of parameters in reflector file reflector.rf" << endl;
      exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
    }
    if(counter != ALPHABET_LENGTH_){
      cerr << "Insufficient number of mappings in reflector file: reflector.rf" << endl;
      // throw INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
      exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
    }
    // What happens if more than 26 parameters

}

void Reflector::returnConfigError(){
  cerr << INVALID_REFLECTOR_MAPPING << endl;
}

void Reflector::returnNonNumericCharacterError(){
  cerr << "Non-numeric character in reflector file reflector.rf"  << endl;
}
