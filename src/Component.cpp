#include "Component.h"
#include "errors.h"
#include "helper.h"
#include <iostream>
#include <fstream>

using namespace std;
// Do you need a constructor when the class does not have any attributes?
// Component::Component(){}


int Component::checkInput(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cout << "failing... " << endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  }
  while(!in_stream.eof() && in_stream >> num){
    if(!isNumberRangeCorrect(num)){
      cout << "out of range " << endl;
      return INVALID_INDEX;
    }
    counter++;
    // If non-numeric character
    // cout << "non numeric character..." << endl;
    // return NON_NUMERIC_CHARACTER;
  }
  return NO_ERROR;
}
