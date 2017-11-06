#include <iostream>
#include <fstream>
#include <cstring>
#include "helper.h"
#include "errors.h"

using namespace std;

int get_array_length(const char* path){
  int counter = 0;
  int num;
  fstream in_stream;
  in_stream.open(path);
  while(!in_stream.eof() && in_stream >> num){
    // in_stream >> num;
    // in_stream >> ws;
    // cout << "num" << num << endl;
    counter++;
  }
  in_stream.close();
  // TODO Double check this -1
  return counter-1;
}

void map_input_to_array(const char* path, int* array){
  int i=0;

  fstream in_stream;

  in_stream.open(path);

  if(in_stream.fail()){
    cout << "failing... " << endl;
    // return ERROR_OPENING_CONFIGURATION_FILE
  }
  int num;
  // in_stream >> num;
  while(!in_stream.eof()){
    in_stream >> num;
    array[i] = num;
    i++;
  }
  in_stream.close();
}

// Check if the array only contains numbers between 0 and 25
bool is_number_range_correct(int* array, int length){
  for(int i = 0; i< length; i++){
    if(array[i] > 25 || array[i] < 0){
      return false;
    }
  }
  return true;
}

// TODO Is this efficient?
bool is_duplicate_int(int* array, int range){

  for(int i = range-1; i>= 0; i--){
    if(is_appeared_before(array, array[i], i)){
      return true;
    }
  }
  return false;
}

bool is_appeared_before(int* array, int num, int position){
  for(int x = 0; x < position; x++ ){
    if(array[x] == array[position]){
      cout << "duplicate! " << endl;
      cout << "array[x] " << array[x] << endl;
      return true;
    }
  }
  return false;
}
