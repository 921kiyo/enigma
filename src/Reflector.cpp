#include "Reflector.h"
#include "helper.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Reflector::Reflector(const char* path){
  checkInput(path);
  mapInput(path);
}

int Reflector::checkInput(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);

  if(in_stream.fail()){
    cout << "failing... " << endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  }

  while(!in_stream.eof() && in_stream >> num){
    counter++;
  }

  if(counter != 26){
    cout << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS " << endl;
    return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  }

  if(!isNumberRangeCorrect(num)){
    cout << "out of range " << endl;
    return INVALID_INDEX;
  }
  return NO_ERROR;
}

void Reflector::mapInput(const char* path){
  int array_length = getArrayLength(path);
  int num_array[array_length];
  mapInputToArray(path, num_array);

  if(isDuplicateInt(num_array, array_length)){
    cout << "INVALID_REFLECTOR_MAPPING " << endl;
    cout << INVALID_REFLECTOR_MAPPING << endl;
  }

  // If not problem with input, then start mapping to pair arrays
  for(int i = 0; i< array_length; i++){
    if(i%2 == 0){
      pair_input_[i/2] = num_array[i];
    }
    else{
      pair_output_[i/2] = num_array[i];
    }
  }
}

int Reflector::convertForward(int input){
  for(int i = 0; i< PAIR_SIZE; i++){
    if(input == pair_input_[i]){
      return pair_output_[i];
    }
    if(input == pair_output_[i]){
      return pair_input_[i];
    }
  }
}
