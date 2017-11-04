#include <iostream>
#include <fstream>
#include "Rotor.h"
#include "errors.h"
#include "helper.h"

using namespace std;

Rotor::Rotor(const char* path){
  check_input(path);
}

int Rotor::check_input(const char* path){
  int input_array[80];
  for(int i = 0; i< 80; i++){
    input_array[i] = -1;
  }
  map_input_to_array(path, input_array);
  for(int i = 0; i<80; i++){
    cout << "input array" << i << " " << input_array[i] << endl;
  }

  // cout << "path " << path << endl;
  // int num;
  // int rotors[26];
  // fstream in_stream;
  // in_stream.open(path);
  // if(in_stream.fail()){
  //   cout << "failing... " << endl;
  // }
  // // in_stream.get(num);
  // for(int i = 0; i< 26; i++){
  //   in_stream >> num;
  //   rotors[i] = num;
  //   cout << num << endl;
  // }

  // while(!in_stream.eof()){
  //   cout << "num " << num << endl;
  //   in_stream >> num;
  // }
  // in_stream.close();
  return NO_ERROR;
}
