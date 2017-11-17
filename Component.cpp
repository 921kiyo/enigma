#include "Component.h"
#include "errors.h"
#include <iostream>
#include <fstream>

using namespace std;

Component::~Component(){}


// Do I need this??
int Component::getArrayLength(const char* path){
  int counter = 0;
  int num;
  fstream in_stream;
  in_stream.open(path);
  while(!in_stream.eof() && in_stream >> num){
    counter++;
  }
  in_stream.close();
  return counter;
}

// This could be optimized!!
void Component::mapInputToArray(const char* path, int* array){
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

bool Component::isNumberRangeCorrect(int num){
  return (num < ALPHABET_LENGTH_ && num >= 0);
}

// TODO Is this efficient?
void Component::checkDuplicateInt(int* array, int range){
  int previous_appeared_position;
  for(int i = range-1; i>= 0; i--){
    previous_appeared_position = isAppearedBefore(array, array[i], i);
    if(previous_appeared_position != -1){
      cerr << "Invalid mapping of input " << i << " to output " << array[i] << " (output " << array[i] << " is already mapped to from input " << previous_appeared_position << ")" << endl;
    }
  }
}

int Component::isAppearedBefore(int* array, int num, int position){
  for(int x = 0; x < position; x++ ){
    if(array[x] == array[position]){
      return x;
    }
  }
  return -1;
}
