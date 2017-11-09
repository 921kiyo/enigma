#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "errors.h"
#include "Enigma.h"

using namespace std;

// TODO Delete this
// ./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos
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

  // cout << "plugboards " << argv[1] << endl;
  // Plugboard plugboard(argv[1]);
  // cout << "reflector " << argv[2] << endl;

  Enigma enigma(argc, argv);
  char message[80];
  char encrypted_message[80];

  cout << "Type a message you want to encrypt " << endl;
  cin >> message;

  enigma.encrypt_message(message, encrypted_message);
  cout << "Encrypted message is " << encrypted_message << endl;
  // TODO Insufficient # of parameters
  // int error = open_file(argv[2]);
  // cout << "error? " << error << endl;

return 0;
}
