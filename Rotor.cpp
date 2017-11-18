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
  num_of_notches_ = notches_.size();
  current_position_ = start_position;
}

void Rotor::rotate(){
  previous_position_ = current_position_;
  current_position_ = (current_position_ + 1) % ALPHABET_LENGTH;
}

int Rotor::shiftUp(int input_index){
  return (input_index - getCurrentPosition() + ALPHABET_LENGTH) % ALPHABET_LENGTH;
}

int Rotor::shiftDown(int input_index){
  return (input_index + getCurrentPosition()) % ALPHABET_LENGTH;
}

int Rotor::getPreviousPosition(){
  // cout << "previous position " << previous_position_ << endl;
  return previous_position_;
}

int Rotor::getCurrentPosition(){
  // cout << "current position " << current_position_ << endl;
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

int Rotor::mapForward(int input_index){
  return contacts_[input_index];
}

int Rotor::mapBackward(int contact){
  // cout << "starting position in backward " << input_index << endl;
  for(int i = 0; i < ALPHABET_LENGTH; i++){
      // cout << "contacts " << contacts_[i] << endl;
      if(contact == contacts_[i]){
        // cout << "contacts backward[input_index] " << i << endl;
          return i;
      }
  }
  return contact;
}
