#ifndef COMPONENT_H
#define COMPONENT_H

class Component{
public:
  virtual int checkInput(const char* path_rot) = 0;
  virtual void mapInput(const char* path, int start_position) = 0;
  virtual int convertForward(int input_index) = 0;
};

#endif
