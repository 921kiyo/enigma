#include "Plugboard.h"
#include "SubComponent.h"
#include "fstream"
#include "errors.h"

#include <iostream>

using namespace std;

Plugboard::Plugboard(const char* path){
  setConfig(path);
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
