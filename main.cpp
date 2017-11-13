#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "errors.h"
#include "Enigma.h"

using namespace std;

int main(int argc, char** argv){

Enigma enigma(argc, argv);
char message[80];
char encrypted_message[80];

cin >> message;
enigma.encryptMessage(message, encrypted_message);
cout << encrypted_message << endl;

return NO_ERROR;
}
