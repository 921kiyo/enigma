#include "Rotor.h"
#include "alphabet.h"
#include <iostream>
#include <fstream>

using namespace std;

Rotor::Rotor(const char* path, int start_position){
  fstream in_stream;
  in_stream.open(path);
  int num;
  int counter = 0;
  while(in_stream >> num){
    if(counter < ALPHABET_LENGTH){
      contacts_[counter] = num;
    }
    else{
      notches_.push_back(num);
    }
    counter++;
  }
  current_position_ = start_position;
}

int Rotor::getPreviousPosition(){
  return previous_position_;
}

int Rotor::getCurrentPosition(){
  return current_position_;
}

void Rotor::rotate(){
  previous_position_ = current_position_;
  current_position_ = (current_position_ + 1) % ALPHABET_LENGTH;
}

// Use moduler of ALPHABET_LENGTH (26) to make sure the output is always
// between 0 and 25
int Rotor::shiftUp(int input_index){
  return (input_index - getCurrentPosition() + ALPHABET_LENGTH) \
  % ALPHABET_LENGTH;
}

int Rotor::shiftDown(int input_index){
  return (input_index + getCurrentPosition()) % ALPHABET_LENGTH;
}

int Rotor::mapForward(int input_index){
  return contacts_[input_index];
}

int Rotor::mapBackward(int contact){
  for(int i = 0; i < ALPHABET_LENGTH; i++){
      if(contact == contacts_[i]){
          return i;
      }
  }
  return contact;
}

bool Rotor::isCurrentPositionInNotch(){
  int num_of_notches = notches_.size();
  for(int i= 0; i< num_of_notches; i++){
    if(current_position_ == notches_[i]){
      return true;
    }
  }
  return false;
}
