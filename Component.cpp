#include "Component.h"
#include "errors.h"
#include <iostream>
#include <fstream>

using namespace std;

Component::~Component(){}

// This could be optimized!!
// void Component::mapInputToArray(const char* path, int* array){
//   int i=0;
//   fstream in_stream;
//   in_stream.open(path);
//   int num;
//   while(!in_stream.eof() && in_stream >> num){
//     array[i] = num;
//     i++;
//   }
//   in_stream.close();
// }
