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

  int array_length = get_array_length(path);
  int num_array[array_length];
  map_input_to_array(path, num_array);

  if(is_duplicate_int(num_array, array_length)){
    return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
  }

  if(!is_number_range_correct(num_array, array_length)){
    cout << "out of range " << endl;
    return INVALID_INDEX;
  }

  if(array_length%2!=0){
    cout << "odd number " << endl;
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  }

  // string str;
  // int letter_length, tenth_digit, first_digit, digit;





  // if(count%2!=0){
  //   #ifndef DEBUG
  //   cout << "failing: not odd number " << INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS << endl;
  //   #endif
  //   return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  // }
  //
  // cout << "plugboard no problem " << endl;
  // in_stream.close();
  // Check the extension is pd
}

// void Plugboard::map_input(const string path){
//
// }
