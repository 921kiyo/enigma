#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "errors.h"
#include "Enigma.h"
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

using namespace std;

int open_file(char* path){
  char character;
  ifstream in_stream;
  // in_stream.exceptions ( ifstream::failbit );

  in_stream.open(path);
  // try{in_stream.open("./plugboards/IV.pd");}
  // catch(ifstream::failure& e){
  //   cerr << "Error " << endl;
  // }
  if(in_stream.fail()){
    return ERROR_OPENING_CONFIGURATION_FILE;
  }
  in_stream.get(character);
  while(!in_stream.eof()){
    cout << character;
    in_stream.get(character);
  }

  // TODO INVALID_INPUT_CHARACTER

  // TODO Remove white space

  // TODO upper case character

  in_stream.close();

  return NO_ERROR;
}


int main(int argc, char** argv){

  cout << "argc " << argc << endl;

  cout << "plugboards " << argv[1] << endl;
  Plugboard plugboard(argv[1]);
  // cout << "reflector " << argv[2] << endl;

  // This is a list of rotors
  // for(int i = 3; i < argc-1; i++){
  //     cout << argv[i] << endl;
  // }

  // cout << "Starting position " << argv[argc-1] << endl;

  // TODO Create an instance of Enigma

  // TODO Insufficient # of parameters
  // int error = open_file(argv[2]);
  // cout << "error? " << error << endl;
  // string message;
  // cout << "Type a message you want to encrypt " << endl;
  // cin >> message;
  // cout << "Encrypted message is " << endl;

  return 0;
}