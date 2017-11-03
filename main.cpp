#include <iostream>
#include <fstream>

#include "errors.h"

using namespace std;

int open_file(char* path){
  cout << "path " << path << endl;
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

  // cout << "argc " << argc << endl;
  //
  // cout << "plugboards " << argv[1] << endl;
  // cout << "reflector " << argv[2] << endl;
  // This is a list of rotors
  // for(int i = 3; argv[i] != '\0'; i++){
  //     cout << argv[i] << endl;
  // }

  // TODO Insufficient # of parameters
  int error = open_file(argv[2]);
  cout << "error? " << error << endl;
  return 0;
}
