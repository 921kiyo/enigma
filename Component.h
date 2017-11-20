#ifndef SUBCOMPONENT_H
#define SUBCOMPONENT_H

#include <vector>

// Component class is used to create plugboard and reflector instance, 
// since their functionality in terms of mapping is essentially the same
class Component{
private:
  // Store pair letters index in each vector, so it is easy to
  // map because pair letters are stored at the same index.
  std::vector<int> input_pair1_;
  std::vector<int> input_pair2_;
public:
  // Within this constructor, it gets all inputs from the file and assign them
  // to input_pair1_ and input_pair2_ vectors.
  Component(const char* path);
  // Map the input accoding to wired-up pairs stored in
  // input_pair1_ and input_pair2_ .
  // If corresponding input is not found in the pair vectors,
  // return input itself.
  int map(int input);
};

#endif
