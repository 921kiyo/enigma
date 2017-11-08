#include <iostream>
#include <fstream>
#include <cstring>
#include "Enigma.h"

#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;

Enigma::Enigma(int argc, char** argv){
  plugboard = new Plugboard(argv[1]);
  reflector = new Reflector(argv[2]);

  int num_of_rotors = argc-4;
  rotors = new Rotor*[num_of_rotors];
  cout << "num_of_rotors " << num_of_rotors << endl;
  int starting_position;
  for(int i = 0; i < num_of_rotors; i++){
    starting_position = get_rotor_position(argv[argc-1], i);
    // cout << "starting_position " << starting_position << endl;
    rotors[i] = new Rotor(argv[i+3], starting_position);
  }
}

int Enigma::get_rotor_position(const char* path, int position){
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

void Enigma::encrypt_message(const char* message, char* encrypted_message){
  int array_length = strlen(message);
  int current_index = message[1] -65;
  // cout << "letter_abs_position " << letter_abs_position << endl;

  // Can I use recursion here??

  // Step1 rotate the rotor
  rotors[0]->rotate_forward();
  // Step2
  current_index = rotors[0]->convert_forward(current_index);
  current_index = rotors[1]->convert_forward(current_index);
  current_index = rotors[2]->convert_forward(current_index);
  current_index = reflector->convert_forward(current_index);
  cout << "helo " << current_index << endl;
  current_index = rotors[2]->convert_backward(current_index);
  current_index = rotors[1]->convert_backward(current_index);
  current_index = rotors[0]->convert_backward(current_index);
  cout << "current_index " << current_index << endl;
  encrypted_message[1] = current_index + 65;
  cout << "encrypt_message[1] " << encrypted_message[1] << endl;
  // for(int i = 0; i < array_length ; i++ ){
  //   rotors[i]->convert_forward(letter_abs_position);
  // }
}
