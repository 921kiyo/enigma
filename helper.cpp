#include <iostream>
#include <fstream>
#include <cstring>
#include "helper.h"

using namespace std;

void map_input_to_array(const char* path, int* array){
  int num, array_length;
  array_length = sizeof(array);
  
  fstream in_stream;

  in_stream.open(path);

  if(in_stream.fail()){
    cout << "failing... " << endl;
  }

  for(int i = 0; i< array_length; i++){
    in_stream >> num;
    array[i] = num;
    cout << num << endl;
  }
}

bool is_number_range_correct(int* array){
  return true;
}
