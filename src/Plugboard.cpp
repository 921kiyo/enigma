#include "Plugboard.h"
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

int Plugboard::checkInput(const char* path){
  int num;
  // Do I need counter?
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

  if(!isNumberRangeCorrect(num)){
    cout << "out of range " << endl;
    return INVALID_INDEX;
  }

  if(counter%2!=0){
    cout << "odd number " << endl;
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  }

  // Check the extension is pd
  return NO_ERROR;
}

void Plugboard::mapInput(const char* path){

  int array_length = getArrayLength(path);
  int num_array[array_length];
  mapInputToArray(path, num_array);

  if(isDuplicateInt(num_array, array_length)){
    //  How do you return this?
    cout << IMPOSSIBLE_PLUGBOARD_CONFIGURATION << endl;
  }

  for(int i = 0; i< array_length; i++){
    if(i%2 == 0){
      pair_input_[i/2] = num_array[i];
    }
    else{
      pair_output_[i/2] = num_array[i];
    }
  }
}

int Plugboard::convertForward(int input){
  for(int i = 0; i< PAIR_MAX_SIZE; i++){
    if(input == pair_input_[i]){
      return pair_output_[i];
    }
    else if(input == pair_output_[i]){
      return pair_input_[i];
    }
    else{
      return input;
    }
  }
}
