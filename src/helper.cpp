#include "helper.h"
#include "errors.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// TODO more description here
// I double checked with Dr.Fidelis about using global helper functions

int getArrayLength(const char* path){
  int counter = 0;
  int num;
  fstream in_stream;
  in_stream.open(path);
  while(!in_stream.eof() && in_stream >> num){
  // while(!in_stream.eof()){
  //   in_stream >> num;
    // in_stream >> ws;
    counter++;
  }
  in_stream.close();

  return counter;
}

void mapInputToArray(const char* path, int* array){
  // TODO Delete this
  int i=0;

  fstream in_stream;

  in_stream.open(path);

  int num;
  while(!in_stream.eof() && in_stream >> num){
    array[i] = num;
    i++;
  }
  in_stream.close();
}

// Check if the array only contains numbers between 0 and 25
bool isNumberRangeCorrect(int num){
  if(num > 25 || num < 0){
    return false;
  }
  return true;
}

// TODO Is this efficient?
bool isDuplicateInt(int* array, int range){

  for(int i = range-1; i>= 0; i--){
    if(isAppearedBefore(array, array[i], i)){
      return true;
    }
  }
  return false;
}

bool isAppearedBefore(int* array, int num, int position){
  for(int x = 0; x < position; x++ ){
    if(array[x] == array[position]){
      return true;
    }
  }
  return false;
}
