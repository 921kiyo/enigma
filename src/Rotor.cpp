#include "Rotor.h"
#include "errors.h"
#include "helper.h"

#include <iostream>
#include <fstream>

using namespace std;

Rotor::Rotor(const char* path, int start_position){
  checkInput(path);
  mapInput(path, start_position);
}

int Rotor::checkInput(const char* path){
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

  if(!isNumberRangeCorrect(num)){
    cout << "out of range " << endl;
    return INVALID_INDEX;
  }

  return NO_ERROR;
}
void Rotor::mapInput(const char* path, int start_position){
  current_position_ = start_position;

  int array_length = getArrayLength(path);
  int num_array[array_length];
  mapInputToArray(path, num_array);

  // TODO Double check if this checking is enough
  if(isDuplicateInt(num_array, 25)){
    cout << "invalid rotor mapping " << endl;
    // return INVALID_ROTOR_MAPPING;
  }

  // If not error, them map them to each attributes
  num_of_notches_ = array_length - ALPHABET_LENGTH;
  // Why do I have to call mapInputToArray twice here?
  mapInputToArray(path, contacts_);
  notches_ = new int[num_of_notches_];
  for(int i = 0; i< num_of_notches_; i++){
    notches_[i] = num_array[i+ALPHABET_LENGTH];
  }
}

void Rotor::rotateForward(){
  current_position_++;
  current_position_ = current_position_ % ALPHABET_LENGTH;
  // cout << "after rorate forward, start is " << current_position << endl;
}

int Rotor::getCurrentPosition(){
  return current_position_;
}

bool Rotor::isCurrentPositionInNotch(){
  for(int i= 0; i< num_of_notches_; i++){
    if(current_position_ == notches_[i]){
      cout << "yes notch at " << current_position_ << endl;
      return true;
    }
  }
  return false;
}

int Rotor::convertForward(int input_index){
  // cout << "current_position " << current_position << endl;
  int index = (input_index + current_position_) % ALPHABET_LENGTH;
  return contacts_[index];
}

int Rotor::convertBackward(int input_index){
  // cout << "starting position in backward " << starting_position << endl;
  for(int i = 0; i < ALPHABET_LENGTH; i++){
      // cout << "contacts " << contacts[i] << endl;
      if(input_index == contacts_[i]){
        // cout << "contacts backward[input_index] " << i << endl;
        input_index = i - current_position_;
        if(input_index < 0){
          return ALPHABET_LENGTH + input_index;
        }
        else{
          return input_index;
        }
      }
  }
}
