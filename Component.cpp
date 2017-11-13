#include "Component.h"
#include "errors.h"
#include <iostream>
#include <fstream>

using namespace std;
Component::~Component(){
  // cout << "Base Destructor\t" << endl;
}
int Component::checkInput(const char* path){
  // TODO Check the extension is pd
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

int Component::getArrayLength(const char* path){
  int counter = 0;
  int num;
  fstream in_stream;
  in_stream.open(path);
  while(!in_stream.eof() && in_stream >> num){
  // while(!in_stream.eof()){
  //   in_stream >> num;
    // in_stream >> ws;
    counter++;
  }
  in_stream.close();

  return counter;
}

// This could be optimized!!
void Component::mapInputToArray(const char* path, int* array){
  // TODO Delete this
  int i=0;

  fstream in_stream;

  in_stream.open(path);

  int num;
  while(!in_stream.eof() && in_stream >> num){
    array[i] = num;
    i++;
  }
  in_stream.close();
}

bool Component::isNumberRangeCorrect(int num){
  if(num > 25 || num < 0){
    return false;
  }
  return true;
}

// TODO Is this efficient?
bool Component::isDuplicateInt(int* array, int range){

  for(int i = range-1; i>= 0; i--){
    if(isAppearedBefore(array, array[i], i)){
      return true;
    }
  }
  return false;
}

bool Component::isAppearedBefore(int* array, int num, int position){
  for(int x = 0; x < position; x++ ){
    if(array[x] == array[position]){
      return true;
    }
  }
  return false;
}
