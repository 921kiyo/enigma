#include "Plugboard.h"
#include "SubComponent.h"
#include "fstream"
#include "errors.h"

#include <iostream>

using namespace std;

Plugboard::Plugboard(const char* path){
  int counter = 0;
  // counter = checkInput(path);
  setConfig(path);
  checkParameters(counter);
}

void Plugboard::checkParameters(const int counter){
    if(counter%2!=0 || counter > ALPHABET_LENGTH_){
      cerr << "Incorrect number of parameters in plugboard file plugboard.pb" << endl;
      throw(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
    }
}

void Plugboard::throwConfigError(){
    // cerr <<

}

void Plugboard::throwNonNumericCharacterError(){
  cerr << "Non-numeric character in plugboard file plugboard.pb"  << endl;
}

void Plugboard::throwInvalidMappingError(){
  throw(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
}
