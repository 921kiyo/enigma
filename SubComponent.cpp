#include "SubComponent.h"
#include "errors.h"

#include <iostream>
#include <fstream>

using namespace std;

SubComponent::SubComponent(const char* path){
  setConfig(path);
}

void SubComponent::setConfig(const char* path){
  // Do I need to get array length here??
  int array_length = ALPHABET_LENGTH_;
  int num_array[array_length];
  mapInputToArray(path, num_array);
  for(int i = 0; i< array_length; i++){
    if(i%2 == 0){
      input_pair1_[i/2] = num_array[i];
    }
    else{
      input_pair2_[i/2] = num_array[i];
    }
  }
}

int SubComponent::map(int input){
  for(int i = 0; i< PAIR_SIZE_; i++){
    if(input == input_pair1_[i]){
      return input_pair2_[i];
    }
    if(input == input_pair2_[i]){
      return input_pair1_[i];
    }
  }
  return input;
}
