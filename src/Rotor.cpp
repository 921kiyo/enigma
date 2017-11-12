#include "Rotor.h"
#include "errors.h"
#include "helper.h"

#include <iostream>
#include <fstream>

using namespace std;

Rotor::Rotor(const char* path, int start_position){
  checkInput(path);
  mapInput(path);
  // Map current position;
}

Rotor::~Rotor(){
  delete[] notches_;
}

void Rotor::mapInput(const char* path){
  int array_length = getArrayLength(path);
  int num_array[array_length];
  mapInputToArray(path, num_array);

  // TODO Double check if this checking is enough
  if(isDuplicateInt(num_array, 25)){
    cout << "invalid rotor mapping " << endl;
    // return INVALID_ROTOR_MAPPING;
  }

  // If not error, them map them to each attributes
  num_of_notches_ = array_length - ALPHABET_LENGTH_;
  // Why do I have to call mapInputToArray twice here?
  mapInputToArray(path, contacts_);
  notches_ = new int[num_of_notches_];
  for(int i = 0; i< num_of_notches_; i++){
    notches_[i] = num_array[i+ALPHABET_LENGTH_];
  }
}

void Rotor::rotateForward(){
  current_position_++;
  current_position_ = current_position_ % ALPHABET_LENGTH_;
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
  int index = (input_index + current_position_) % ALPHABET_LENGTH_;
  return contacts_[index];
}

int Rotor::convertBackward(int input_index){
  // cout << "starting position in backward " << starting_position << endl;
  for(int i = 0; i < ALPHABET_LENGTH_; i++){
      // cout << "contacts " << contacts[i] << endl;
      if(input_index == contacts_[i]){
        // cout << "contacts backward[input_index] " << i << endl;
        input_index = i - current_position_;
        if(input_index < 0){
          return ALPHABET_LENGTH_ + input_index;
        }
        else{
          return input_index;
        }
      }
  }
  // Double check this!!
  return input_index;
}
