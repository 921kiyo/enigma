#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


#include "errors.h"
#include "Enigma.h"

using namespace std;

// TODO Delete this
// ./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < input.txt > output.txt

int main(int argc, char** argv){

  Enigma enigma(argc, argv);
  char message[80];
  char encrypted_message[80];

  cin >> message;
  enigma.encrypt_message(message, encrypted_message);
  cout << encrypted_message << endl;

return 0;
}
