#include <iostream>
#include <fstream>
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

char* Enigma::encrypt_message(char* message){
  return "hlo";
}
