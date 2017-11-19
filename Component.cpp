#include "Component.h"
#include <iostream>
#include <fstream>

using namespace std;

Component::Component(const char* path){
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

int Component::map(int input){
  // Both pair1 and pair2 has to have the same length
  // since they are in pair. So I use pair1 length.
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
