#include "SubComponent.h"
#include "errors.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

SubComponent::SubComponent(const vector<int> contacts){
  setConfig(contacts);
}

void SubComponent::setConfig(const vector<int> contacts){

  for(int i = 0; i< ALPHABET_LENGTH_; i++){
    if(i%2 == 0){
      input_pair1_.push_back(contacts[i]);
    }
    else{
      input_pair2_.push_back(contacts[i]);
    }
  }
  // for(int i = 0; i< ALPHABET_LENGTH_; i++){
  //   cout << "num_array " << i << " " << contacts[i] << endl;
  // }
}
// void SubComponent::setConfig(const char* path){
//   int num_array[ALPHABET_LENGTH_];
//   mapInputToArray(path, num_array);
//   for(int i = 0; i< ALPHABET_LENGTH_; i++){
//     if(i%2 == 0){
//       input_pair1_[i/2] = num_array[i];
//     }
//     else{
//       input_pair2_[i/2] = num_array[i];
//     }
//   }
//   for(int i = 0; i< ALPHABET_LENGTH_; i++){
//     cout << "num_array " << i << " " << num_array[i] << endl;
//   }
// }

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
