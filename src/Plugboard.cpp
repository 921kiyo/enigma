#include "Plugboard.h"
#include "SubComponent.h"
#include "helper.h"
#include "errors.h"

#include <iostream>
#include "fstream"

using namespace std;

// Constructor
Plugboard::Plugboard(const char* path){
  checkInput(path);
  mapInput(path);
}

// TODO You need to call this somewhere
int Plugboard::checkParameters(const int counter){
    if(counter%2!=0){
      cout << "odd number " << endl;
      return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    }
    return NO_ERROR;
}

void Plugboard::returnConfigError(){
    cout << IMPOSSIBLE_PLUGBOARD_CONFIGURATION << endl;
}
