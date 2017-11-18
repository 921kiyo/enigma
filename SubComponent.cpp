#include "SubComponent.h"
#include "errors.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

SubComponent::SubComponent(const char* path){
  fstream in_stream;
  in_stream.open(path);
  int num;
  int counter = 0;
  while(in_stream >> num){
    if(counter%2 == 0){
      input_pair1_.push_back(num);
    }
    else{
      input_pair2_.push_back(num);
    }
    counter++;
  }
  in_stream.close();
}

int SubComponent::map(int input){
  int length = input_pair1_.size();
  for(int i = 0; i< length; i++){
    if(input == input_pair1_[i]){
      return input_pair2_[i];
    }
    if(input == input_pair2_[i]){
      return input_pair1_[i];
    }
  }
  return input;
}
