#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "errors.h"
#include "Enigma.h"

using namespace std;

// TODO Delete this
// ./enigma plugboards/I.pb reflectors/I.rf rotors/II.rot rotors/I.rot rotors/III.rot rotors/I.pos
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

  // cout << "plugboards " << argv[1] << endl;
  // Plugboard plugboard(argv[1]);
  // cout << "reflector " << argv[2] << endl;

  Enigma enigma(argc, argv);
  char message[80] = "hello";

  char* encrypted_message;
  // cout << "Type a message you want to encrypt " << endl;
  // cin >> message;
  // cout << "Encrypted message is " << endl;
  enigma.encrypt_message(message);

  // TODO Insufficient # of parameters
  // int error = open_file(argv[2]);
  // cout << "error? " << error << endl;



  return 0;
}
