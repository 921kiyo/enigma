#include "Plugboard.h"
#include "SubComponent.h"
#include "fstream"
#include "errors.h"

#include <iostream>

using namespace std;

// Constructor
Plugboard::Plugboard(const char* path){
  int counter;
  counter = checkInput(path);
  checkParameters(counter);
  mapInput(path);
}

void Plugboard::checkParameters(const int counter){
    if(counter%2!=0 || counter > ALPHABET_LENGTH_){
      cerr << "Incorrect number of parameters in plugboard file plugboard.pb" << endl;
      throw(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
    }
}

void Plugboard::returnConfigError(){
    throw(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
}

void Plugboard::returnNonNumericCharacterError(){
  cerr << "Non-numeric character in plugboard file plugboard.pb"  << endl;
}
