#ifndef COMPONENT_H
#define COMPONENT_H

class Component{
protected:
  // C++ 11 Default value initialisation
  static const int ALPHABET_LENGTH_{26};
public:
  //
  int checkInput(const char* path);
  int getArrayLength(const char* path);
  void mapInputToArray(const char* path, int* array);
  // Check if the array only contains numbers between 0 and 25
  bool isNumberRangeCorrect(int num);
  void checkDuplicateInt(int* array, int range);
  // This does not need to be in public
  int isAppearedBefore(int* array, int num, int position);
  virtual void setConfig(const char* path) = 0;
  virtual int map(int input_index) = 0;
  virtual void throwInvalidMappingError() = 0;
  // virtual void throwIncorrectParamsError() = 0;
  virtual void throwNonNumericCharacterError() = 0;
  // virtual void throwInvalidIndexError() = 0;

  // ???
  virtual ~Component();
};

#endif
