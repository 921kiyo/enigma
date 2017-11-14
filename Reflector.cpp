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
      cout << "Incorrect (odd) number of parameters in reflector file reflector.rf";
      throw INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
    if(counter != ALPHABET_LENGTH_){
      cout << "Insufficient number of mappings in reflector file: reflector.rf";
      throw INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
    // What happens if more than 26 parameters

}

void Reflector::returnConfigError(){
    cout << INVALID_REFLECTOR_MAPPING << endl;
}

void Reflector::returnNonNumericCharacterError(){
  cout << "Non-numeric character in reflector file reflector.rf";
}
