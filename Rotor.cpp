#include <iostream>
#include <fstream>
#include "Rotor.h"
#include "errors.h"
#include "helper.h"

using namespace std;

Rotor::Rotor(const char* path, int position){
  if(check_input(path) == NO_ERROR){
      starting_position = position;
  }
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

  // If not error, them map them to each attributes
  num_of_notches = array_length - ALPHABET_LENGTH;
  // cout << "num_of_notches " << num_of_notches << endl;
  map_input_to_array(path, contacts);
  notches = new int[num_of_notches];
  for(int i = 0; i< num_of_notches; i++){
    notches[i] = num_array[i+ALPHABET_LENGTH];
    // cout << "notches[i] " << notches[i] << endl;
  }
  return NO_ERROR;
}

void Rotor::rotate_forward(){
  starting_position++;
  cout << "starting_position " << starting_position << endl;
}

// Do I need this?
void Rotor::rotate_backward(){
  starting_position--;
}

int Rotor::convert_forward(int input_index){
  // cout << "contacts[input_index] " << contacts[input_index] << endl;
  cout << "contacts[input_index] " << input_index << endl;
  cout << "starting_position1 " << starting_position << endl;
  int index = (input_index + starting_position) % ALPHABET_LENGTH;
  cout << "index " << index << endl;
  return contacts[index];
}

int Rotor::convert_backward(int input_index){
  for(int i = 0; i < ALPHABET_LENGTH; i++){
      if(input_index == contacts[i]){
        cout << "contacts backward[input_index] " << i << endl;
        return i;
      }
  }

}
