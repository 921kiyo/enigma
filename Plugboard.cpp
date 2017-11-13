#include "Plugboard.h"
#include "SubComponent.h"
#include "errors.h"

#include <iostream>
#include "fstream"

using namespace std;

// Constructor
Plugboard::Plugboard(const char* path){
  int counter;
  counter = checkInput(path);
  checkParameters(counter);
  mapInput(path);
}

void Plugboard::checkParameters(const int counter){
    // cout << "counter " << counter << endl;
    if(counter%2!=0){
      throw INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    }
}

void Plugboard::returnConfigError(){
    throw IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
}
