
#include "Enigma.h"
#include "errors.h"
#include "alphabet.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv){
  // You have to have at least 3 command line arguments (plugboard and reflector)
  // or more than 5 if you include a rotor (and need rotor position file)
  // Note that the value of argc is more than the actual number of command line
  // parameters given
  if(argc < 3 || argc == 4){
    cerr << "usage: enigma plugboard-file reflector-file \
    (<rotor-file>* rotor-positions)?" << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  }
  Enigma *enigma = nullptr;
  // Whenever exception is thrown in input error check, this try/catch will
  // catch it and return an appropriate error code
  try{
    enigma = new Enigma(argc, argv);
  }
  catch(int error){
    delete enigma;
    return error;
  }

  // Get all characters from the input file and remove all spaces
  string temp;
  string string_message = "";
  cin >> ws;
  while(getline(cin, temp)){
    string_message += temp;
  }
  char message[string_message.size()+1];
  strcpy(message, string_message.c_str());

  // Check each letter is an uppercase alphabet
  // and encrypt message letter by letter
  for(int i = 0; message[i] != '\0'; i++){
    if(message[i] - 'A' < 0 || ALPHABET_LENGTH -1 < message[i] - 'A'){
      cerr << message[i] << " is not a valid input character \
      (input characters must be upper case letters A-Z)!" << endl;
      delete enigma;
      return INVALID_INPUT_CHARACTER;
    }
    enigma->encryptMessage(message[i]);
    cout << message[i];
  }
  delete enigma;
  return NO_ERROR;
}
