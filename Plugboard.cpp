#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
// #include <sstream>
#include "Plugboard.h"
#include "helper.h"
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
  int num_array[MAX_LENGTH];
  int count = 0;
  #ifndef DEBUG
  cout << "path is  " << path << endl;
  #endif
  // TODO Change it from char to int
  ifstream in_stream;
  in_stream.open(path);

  if(in_stream.fail()){
    return ERROR_OPENING_CONFIGURATION_FILE;
  }
  in_stream.getline(line, MAX_LENGTH);

  string str;
  int letter_length, tenth_digit, first_digit, digit;

  for(char* tok = strtok(line, " "); tok != NULL; tok=strtok(NULL, " ")){

    // str = str(tok);
    // cout << "-------------" << endl;
    // cout << "tok " << tok << endl;
    letter_length = strlen(tok);
    // if(letter_length > 1 && letter_length < 2){
    //   return
    // }

    // TODO What if 3 digits ??

    if(letter_length == 2){
      first_digit = tok[1];
      first_digit -= 48;
      tenth_digit = tok[0];
      tenth_digit -= 48;

      if(first_digit > 9 || first_digit < 0 || tenth_digit > 9 || tenth_digit < 0){
        cout << "NON_NUMERIC_CHARACTER...." << endl;
        return NON_NUMERIC_CHARACTER;
      }

      digit = first_digit + tenth_digit*10;
      num_array[count] = digit;
      count++;
    }
    else{
      first_digit = tok[0];
      first_digit -= 48;
      digit = first_digit;
      num_array[count] = digit;
      count++;
    }

    if(digit<0 || digit > 25){
      return INVALID_INDEX;
    }
  }

  cout << "----------" << endl;
  for(int i = 0; i< count; i++){
    for(int x = 0; x < i; x++ ){
      if(num_array[x] == num_array[i]){
        cout << "duplicate! " << endl;
        return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
      }
    }
  }

  if(count%2!=0){
    #ifndef DEBUG
    cout << "failing: not odd number " << INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS << endl;
    #endif
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  }

  cout << "plugboard no problem " << endl;
  in_stream.close();
  // Check the extension is pd
}

// void Plugboard::map_input(const string path){
//
// }
