#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
// #include <sstream>
#include "Plugboard.h"
#include "errors.h"

using namespace std;

// #define DEBUG

// Constructor
Plugboard::Plugboard(const char* path){
  check_input(path);
  // map_input(path);
}

int Plugboard::check_input(const char* path){
  const int MAX_LENGTH = 80;
  char line[MAX_LENGTH];
  int count = 0;
  #ifndef DEBUG
  cout << "path is  " << path << endl;
  #endif

  ifstream in_stream;
  in_stream.open(path);

  if(in_stream.fail()){
    return ERROR_OPENING_CONFIGURATION_FILE;
  }
  // in_stream.getline(line, MAX_LENGTH);
  //
  // string str;
  // for(char* tok = strtok(line, " "); tok != NULL; tok=strtok(NULL, " ")){
  //   count++;
  //   str = str(tok);
  //   cout << "tok " << tok << endl;
  //   cout << "num " << num << endl;
  // }
  char letter;
  in_stream.get(letter);
  while(!in_stream.eof()){
    // in_stream.get(letter);
    // cin > ws;
    // cout << ws << endl;
  }
  if(count%2!=0){
    #ifndef DEBUG
    cout << "failing: not odd number " << INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS << endl;
    #endif
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  }

  in_stream.close();


  // Check the extension is pd
}

// void Plugboard::map_input(const string path){
//
// }
