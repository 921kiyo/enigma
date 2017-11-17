#ifndef COMPONENT_H
#define COMPONENT_H

class Component{
protected:
  // C++ 11 Default value initialisation
  static const int ALPHABET_LENGTH_{26};
public:
  void mapInputToArray(const char* path, int* array);
  virtual void setConfig(const char* path) = 0;
  virtual int map(int input_index) = 0;

  // ???
  virtual ~Component();
};

#endif
