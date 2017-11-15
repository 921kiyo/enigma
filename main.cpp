#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "errors.h"
#include "Enigma.h"

using namespace std;

int main(int argc, char** argv){
  // for(int i = 0; i < argc; i++){
  //     cout << argv[i] << endl;
  // }

  if(argc < 3 || argc == 4){
    cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?" << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }
  Enigma *enigma;
  try{
      enigma = new Enigma(argc, argv);
  }
  catch(int error){
    return error;
  }

  // What is the maximum length of this?
  char message[200];
  // char encrypted_message[200];
  // cout << "before message" << endl;
  cin >> message;
  // cout << "message " << message << endl;
  for(int i = 0; message[i] != '\0'; i++){
    // cout << "message " << message[i] << endl;
    if(message[i] - 'A' < 0 || 25 < message[i] - 'A'){
      // cout << message[i] - 'A' << endl;
      cerr << message[i] << " is not a valid input character (input characters must be upper case letters A-Z)!" << endl;
      return INVALID_INPUT_CHARACTER;
    }
    try{
      enigma->encryptMessage(message[i]);
      cout << message[i];
    }catch(int error){
      return error;
    }
  }

  delete enigma;
  // enigma.encryptMessage(message, encrypted_message);
  // cout << message;

  return NO_ERROR;
}
