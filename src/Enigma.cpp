#include "Enigma.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define ENIGMA_DEBUG

Enigma::Enigma(int argc, char** argv){
  // Does not have to use new here
  // if used new, put delete in destructor
  plugboard_ = new Plugboard(argv[1]);
  reflector_ = new Reflector(argv[2]);

  num_of_rotors_ = argc-4;
  rotors_ = new Rotor*[num_of_rotors_];
  int starting_position;
  for(int i = 0; i < num_of_rotors_; i++){
    starting_position = getRotorPosition(argv[argc-1], i);
    rotors_[i] = new Rotor(argv[i+3], starting_position);
  }
}

int Enigma::getRotorPosition(const char* path, int position){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail() && in_stream >> num){
    cout << "error opening file for rotor position" << endl;
    // TODO error message
  }
  while(!in_stream.eof() && in_stream >> num){
    if(position == counter){
      return num;
    }
    counter++;
  }
  // Does this always close input stream?
  in_stream.close();
  return -1;
}

void Enigma::encryptMessage(const char* message, char* encrypted_message){
  int message_length = strlen(message);
  int current_index;
    // TODO Can I use recursion here??
  for(int i = 0; i < message_length; i++){
    // TODO not put integer here! Use const int
    current_index = message[i] -65;

    rotorProcess(current_index);
    #ifndef ENIGMA_DEBUG
    cout << "ascii index " << current_index << endl;
    #endif
    encrypted_message[i] = current_index + 65;
  }
  encrypted_message[message_length] = '\0';
}

void Enigma::rotorProcess(int& current_index){
  // TODO Can I use recursion here??

  // TODO pass reference instead
  #ifndef ENIGMA_DEBUG
  cout << "current index before plugboard " << current_index << endl;
  #endif
  current_index = plugboard_->convertForward(current_index);
  #ifndef ENIGMA_DEBUG
  cout << "current index after plugboard " << current_index << endl;
  #endif


  // First rotate the right most rotor by one
  rotors_[num_of_rotors_-1]->rotateForward();
  for(int i = num_of_rotors_; i > 0; i--){
    current_index = rotors_[i-1]->convertForward(current_index);
    #ifndef ENIGMA_DEBUG
    cout << "current_index i " << i << " and index " << current_index << endl;
    #endif
    if(rotors_[i-1]->isCurrentPositionInNotch()){
      if(i-1 > 0){
        rotors_[i-2]->rotateForward();
      }
    }
  }
  current_index = reflector_->convertForward(current_index);
  #ifndef ENIGMA_DEBUG
  cout << "reversing from here... " << current_index << endl;
  #endif
  for(int i = 0; i < num_of_rotors_; i++){
    current_index = rotors_[i]->convertBackward(current_index);
    #ifndef ENIGMA_DEBUG
    cout << "current_index " << current_index << endl;
    #endif
  }
  current_index = plugboard_->convertForward(current_index);
}
