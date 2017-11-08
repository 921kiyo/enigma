#include <iostream>
#include <fstream>
#include "Rotor.h"
#include "errors.h"
#include "helper.h"

using namespace std;

Rotor::Rotor(const char* path){
  check_input(path);
}

int Rotor::check_input(const char* path){

  int array_length = get_array_length(path);
  int num_array[array_length];
  map_input_to_array(path, num_array);

  // TODO Double check if this checking is enough
  if(is_duplicate_int(num_array, 25)){
    cout << "invalid rotor mapping " << endl;
    return INVALID_ROTOR_MAPPING;
  }

  if(!is_number_range_correct(num_array, array_length)){
    cout << "out of range " << endl;
    return INVALID_INDEX;
  }

  // cout << "array length " << array_length << endl;

  num_of_notches = array_length - ALPHABET_LENGTH;

  cout << "num_of_notches " << num_of_notches << endl;

  return NO_ERROR;
}

void Rotor::rotate_forward(int* array){

}

void Rotor::rotate_backward(int* array){

}

// int Rotor::get_starting_position(){
//
// }
