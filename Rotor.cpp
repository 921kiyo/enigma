#include "Rotor.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

Rotor::Rotor(const char* path, int start_position){
  checkInput(path);
  mapInput(path);
  current_position_ = start_position;
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
    // cout << "invalid rotor mapping " << endl;
    throw INVALID_ROTOR_MAPPING;
  }

  // If not error, them map them to each attributes
  num_of_notches_ = array_length - ALPHABET_LENGTH_;
  // Why do I have to call mapInputToArray twice here?
  mapInputToArray(path, contacts_);
  try{
    notches_ = new int[num_of_notches_];
  }catch(const std::bad_array_new_length &e){
    cout << e.what() << endl;
  }

  for(int i = 0; i< num_of_notches_; i++){
    notches_[i] = num_array[i+ALPHABET_LENGTH_];
  }
}

// Do I ever need this?
void Rotor::rotateDown(){
  current_position_ = (current_position_ + 1) % ALPHABET_LENGTH_;
  // cout << "after rorate forward, start is " << current_position << endl;
}

void Rotor::rotateUp(){
  current_position_ = (current_position_ - 1 + ALPHABET_LENGTH_)% ALPHABET_LENGTH_;
  // cout << "after rorate forward, current position is " << current_position_ << endl;
}

int Rotor::shuffleUp(int input_index){
  return (input_index - getCurrentPosition() + ALPHABET_LENGTH_) % ALPHABET_LENGTH_;
}

int Rotor::shuffleDown(int input_index){
  return (input_index + getCurrentPosition()) % ALPHABET_LENGTH_;
}

int Rotor::getCurrentPosition(){
  return current_position_;
}

bool Rotor::isCurrentPositionInNotch(){
  for(int i= 0; i< num_of_notches_; i++){
    if(current_position_ == notches_[i]){
      // cout << "yes notch at " << current_position_ << endl;
      return true;
    }
  }
  return false;
}

int Rotor::convertForward(int input_index){
  // cout << "current_position " << current_position << endl;
  return contacts_[input_index];
}

int Rotor::convertBackward(int input_index){
  // cout << "starting position in backward " << input_index << endl;
  for(int i = 0; i < ALPHABET_LENGTH_; i++){
      // cout << "contacts " << contacts_[i] << endl;
      if(input_index == contacts_[i]){
        // cout << "contacts backward[input_index] " << i << endl;
          return i;
      }
  }
  // Double check this!!
  return input_index;
}

void Rotor::returnNonNumericCharacterError(){
  cout << "Non-numeric character for mapping in rotor file rotor.rot";
}
