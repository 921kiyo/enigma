#include <iostream>
#include "Enigma.h"

#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;

Enigma::Enigma(int argc, char** argv){
  Plugboard plugboard(argv[1]);

  // This is a list of rotors
  int count = 0;
  for(int i = 3; i < argc-1; i++){
    rotors[count] = new Rotor(argv[i]);
    count++;
    cout << "hello " << endl;
  }

}
