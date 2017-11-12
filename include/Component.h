#ifndef COMPONENT_H
#define COMPONENT_H

class Component{
protected:
  static const int ALPHABET_LENGTH_{26};
public:
  int checkInput(const char* path);
  int getArrayLength(const char* path);
  void mapInputToArray(const char* path, int* array);
  // Check if the array only contains numbers between 0 and 25
  bool isNumberRangeCorrect(int num);
  bool isDuplicateInt(int* array, int range);
  // This does not need to be in public
  bool isAppearedBefore(int* array, int num, int position);
  virtual void mapInput(const char* path) = 0;
  virtual int convertForward(int input_index) = 0;
  // virtual void returnInvalidMappingError() = 0;
  // virtual void returnIncorrectParamsError() = 0;
  // virtual void returnInvalidIndexError() = 0;

  virtual ~Component();
};

#endif
