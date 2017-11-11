#include <iostream>
#include "fstream"

#include "Plugboard.h"
#include "helper.h"
#include "errors.h"

using namespace std;

// Constructor
Plugboard::Plugboard(const char* path){
  check_input(path);
  map_input(path);
}

int Plugboard::check_input(const char* path){
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

  if(!is_number_range_correct(num)){
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

void Plugboard::map_input(const char* path){

  int array_length = get_array_length(path);
  int num_array[array_length];
  map_input_to_array(path, num_array);

  if(is_duplicate_int(num_array, array_length)){
    //  How do you return this?
    cout << IMPOSSIBLE_PLUGBOARD_CONFIGURATION << endl;
  }

  for(int i = 0; i< array_length; i++){
    if(i%2 == 0){
      pair_input[i/2] = num_array[i];
    }
    else{
      pair_output[i/2] = num_array[i];
    }
  }
}

int Plugboard::convert_forward(int input){
  for(int i = 0; i< PAIR_MAX_SIZE; i++){
    if(input == pair_input[i]){
      return pair_output[i];
    }
    else if(input == pair_output[i]){
      return pair_input[i];
    }
    else{
      return input;
    }
  }
}
