#include <iostream>
#include <fstream>
#include "Rotor.h"
#include "errors.h"
#include "helper.h"

using namespace std;

Rotor::Rotor(const char* path, int start_position){
  check_input(path);
  map_input(path, start_position);
}

int Rotor::check_input(const char* path){
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

  return NO_ERROR;
}
void Rotor::map_input(const char* path, int start_position){
  current_position = start_position;

  int array_length = get_array_length(path);
  int num_array[array_length];
  map_input_to_array(path, num_array);

  // TODO Double check if this checking is enough
  if(is_duplicate_int(num_array, 25)){
    cout << "invalid rotor mapping " << endl;
    // return INVALID_ROTOR_MAPPING;
  }

  // If not error, them map them to each attributes
  num_of_notches = array_length - ALPHABET_LENGTH;
  map_input_to_array(path, contacts);
  notches = new int[num_of_notches];
  for(int i = 0; i< num_of_notches; i++){
    notches[i] = num_array[i+ALPHABET_LENGTH];
    // cout << "notches[i] " << notches[i] << endl;
  }

}

void Rotor::rotate_forward(){
  current_position++;
  current_position = current_position % ALPHABET_LENGTH;
  // cout << "after rorate forward, start is " << current_position << endl;
}

int Rotor::get_current_position(){
  return current_position;
}

bool Rotor::is_current_position_in_notch(){
  for(int i= 0; i< num_of_notches; i++){
    if(current_position == notches[i]){
      cout << "yes notch at " << current_position << endl;
      return true;
    }
  }
  return false;
}

int Rotor::convert_forward(int input_index){
  // cout << "current_position " << current_position << endl;
  int index = (input_index + current_position) % ALPHABET_LENGTH;
  return contacts[index];
}

int Rotor::convert_backward(int input_index){
  // cout << "starting position in backward " << starting_position << endl;
  for(int i = 0; i < ALPHABET_LENGTH; i++){
      // cout << "contacts " << contacts[i] << endl;
      if(input_index == contacts[i]){
        // cout << "contacts backward[input_index] " << i << endl;
        input_index = i - current_position;
        if(input_index < 0){
          return ALPHABET_LENGTH + input_index;
        }
        else{
          return input_index;
        }
      }
  }
}
