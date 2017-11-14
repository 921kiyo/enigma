
#include "Enigma.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "errors.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Enigma::Enigma(int argc, char** argv){
  try{
    plugboard_ = new Plugboard(argv[1]);
  }catch(const std::bad_array_new_length &e){
    cout << "newing...1 " << endl;
    cout << e.what() << endl;
  }
  try{
    reflector_ = new Reflector(argv[2]);
  }catch(const std::bad_array_new_length &e){
    cout << "newing...2 " << endl;
    cout << e.what() << endl;
  }
  try{
    num_of_rotors_ = argc-4;
    if(num_of_rotors_ > 0){
      rotors_ = new Rotor*[num_of_rotors_];
    }
  }catch(const std::bad_array_new_length &e){
    cout << "newing...3 " << endl;
    cout << e.what() << endl;
  }

  int starting_position;
  for(int i = 0; i < num_of_rotors_; i++){
    starting_position = getRotorPosition(argv[argc-1], i);
    // if starting_position is -1, do something!!
    try{
        rotors_[i] = new Rotor(argv[i+3], starting_position);
    }catch(const std::bad_array_new_length &e){

      cout << e.what() << endl;
    }

  }
}

Enigma::~Enigma(){
  delete plugboard_;
  delete reflector_;
  for(int i = 0; i < num_of_rotors_; i++){
    delete rotors_[i];
  }
  delete[] rotors_;
}

int Enigma::getRotorPosition(const char* path, int position){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail() && in_stream >> num){
    cerr << "error opening file for rotor position" << endl;
    throw INVALID_ROTOR_MAPPING;
  }
  in_stream >> num;
  while(!in_stream.eof() ){
    // Can I abstruct this away?
    if(num > 25 || num < 0){
      // What is the message here?
      exit(INVALID_INDEX);
    }
    if(in_stream.fail()){
      cerr << "Non-numeric character in rotor positions file rotor.pos";
      exit(NON_NUMERIC_CHARACTER);
    }
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

    // cout << "ascii index " << current_index << endl;

    encrypted_message[i] = current_index + 65;
  }
  encrypted_message[message_length] = '\0';
}

void Enigma::rotorProcess(int& current_index){
  // TODO Can I use recursion here??

  // TODO pass reference instead

  // cout << "current index before plugboard " << current_index << endl;
  current_index = plugboard_->convertForward(current_index);

  // cout << "current index after plugboard " << current_index << endl;
  // First rotate the right most rotor by one
  if(num_of_rotors_ > 0){
    rotors_[num_of_rotors_-1]->rotateDown();
  }

  for(int i = num_of_rotors_ ; i > 0; i--){
    // cout << "rotors_[i-1] " << rotors_[i]->getCurrentPosition() << endl;
    current_index = rotors_[i-1]->shuffleDown(current_index);
    // cout << "current_index1 " << current_index << endl;
    current_index = rotors_[i-1]->convertForward(current_index);
    // cout << "current_index2 " << current_index << endl;
    current_index = rotors_[i-1]->shuffleUp(current_index);
    // cout << "current_index3 " << current_index << endl;
    // cout << "current_index i " << i << " and index " << current_index << endl;

    // TODO need to fix!!
    if(rotors_[i-1]->isCurrentPositionInNotch()){
      if(i-1 > 0){
        rotors_[i-2]->rotateDown();
      }
    }
  }

  current_index = reflector_->convertForward(current_index);
  // cout << "reversing from here... " << current_index << endl;
  for(int i = 0; i < num_of_rotors_; i++){
    current_index = rotors_[i]->shuffleDown(current_index);
    // cout << "current_index1 " << current_index << endl;
    current_index = rotors_[i]->convertBackward(current_index);
    // cout << "current_index2 " << current_index << endl;

    current_index = rotors_[i]->shuffleUp(current_index);
    // cout << "current_index3 " << current_index << endl;
  }
  current_index = plugboard_->convertForward(current_index);
}
