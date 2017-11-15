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
  // cout << "-------------------" << endl;
  // cout << path << endl;
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    // throw ERROR_OPENING_CONFIGURATION_FILE;
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }
  // while(!in_stream.eof() && in_stream >> num);

  while(in_stream >> num){
    if(!isNumberRangeCorrect(num)){
      throw(INVALID_INDEX);
      // throw INVALID_INDEX;
    }
    // cout << num << endl;
    counter++;
  }

  if(in_stream.fail()&&!in_stream.eof()){
    returnNonNumericCharacterError();
    throw(NON_NUMERIC_CHARACTER);
  }
  // return NO_ERROR;
  return counter;
}

int Component::getArrayLength(const char* path){
  int counter = 0;
  int num;
  fstream in_stream;
  in_stream.open(path);
  while(!in_stream.eof() && in_stream >> num){
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
  int previous_appeared_position;
  for(int i = range-1; i>= 0; i--){
    previous_appeared_position = isAppearedBefore(array, array[i], i);
    if(previous_appeared_position != -1){
      cerr << "Invalid mapping of input " << i << " to output " << array[i] << " (output " << array[i] << " is already mapped to from input " << previous_appeared_position << ")" << endl;
      throw(INVALID_ROTOR_MAPPING);
    }
  }
  return false;
}

int Component::isAppearedBefore(int* array, int num, int position){
  for(int x = 0; x < position; x++ ){
    if(array[x] == array[position]){
      return x;
    }
  }
  return -1;
}
