#include "errors.h"
#include "Enigma.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  if(argc < 3 || argc == 4){
    cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?" << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }
  Enigma *enigma = nullptr;
  try{
    enigma = new Enigma(argc, argv);
  }
  catch(int error){
    delete enigma;
    return error;
  }

  // What is the maximum length of this?
  char message[200];
  // This is not working for two words
  cin >> message;

  for(int i = 0; message[i] != '\0'; i++){
    if(message[i] - 'A' < 0 || 25 < message[i] - 'A'){
      cerr << message[i] << " is not a valid input character (input characters must be upper case letters A-Z)!" << endl;
      delete enigma;
      return INVALID_INPUT_CHARACTER;
    }
    // TODO Make sure this doesn't fail
    enigma->encryptMessage(message[i]);
    cout << message[i];
  }
  delete enigma;
  return NO_ERROR;
}
