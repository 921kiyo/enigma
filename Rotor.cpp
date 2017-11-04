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

  int array_length = get_array_length(path);
  int num_array[array_length];
  map_input_to_array(path, num_array);

  
  // for(int i = 0; i<array_length; i++){
  //   cout << "input array" << i << " " << num_array[i] << endl;
  // }

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
