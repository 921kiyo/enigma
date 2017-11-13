#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "errors.h"
#include "Enigma.h"

using namespace std;

int main(int argc, char** argv){

Enigma enigma(argc, argv);
// What is the maximum length of this?
char message[200];
char encrypted_message[200];
cin >> message;
enigma.encryptMessage(message, encrypted_message);
cout << encrypted_message;

return NO_ERROR;
}
