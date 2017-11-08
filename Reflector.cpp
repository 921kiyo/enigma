#include <iostream>

#include "Reflector.h"
#include "helper.h"
#include "errors.h"

using namespace std;

Reflector::Reflector(const char* path){
  check_input(path);
}

int Reflector::check_input(const char* path){
  int array_length = get_array_length(path);
  cout << "array lengt " << array_length << endl;
  int num_array[array_length];
  map_input_to_array(path, num_array);

  if(is_duplicate_int(num_array, array_length)){
    cout << "INVALID_REFLECTOR_MAPPING " << endl;
    return INVALID_REFLECTOR_MAPPING;
  }
  if(array_length != 26){
    cout << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS " << endl;
    return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  }

  if(!is_number_range_correct(num_array, array_length)){
    cout << "out of range " << endl;
    return INVALID_INDEX;
  }

  // If not problem with input, then start mapping to pair arrays
  for(int i = 0; i< array_length; i++){
    if(i%2 == 0){
      pair_input[i/2] = num_array[i];
    }
    else{
      pair_output[i/2] = num_array[i];
    }
  }
}

int Reflector::convert_forward(int input){
  for(int i = 0; i< PAIR_SIZE; i++){
    if(input == pair_input[i]){
      return pair_output[i];
    }
    if(input == pair_output[i]){
      return pair_input[i];
    }
  }
}
