#include "Enigma.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

Enigma::Enigma(int argc, char** argv){
  // Doing all input error checks here
  vector<int> contacts;

  for(int i = 0; i < argc; i++){
    cout << argv[i] << endl;
  }
  // Check Plugboard
  checkPlugboardConfig(argv[1]);
  // setPlugboardConfig(contacts);
  // contacts.clear();
  checkReflectorConfig(argv[2]);
  // setReflectorConfig(contacts);
  // contacts.clear();
  for(int i = 3; i < argc-1; i++){
    checkRotorConfig(argv[i]);
    // setRotorConfig(contacts);
    // contacts.clear();
  }
  checkRotorPositionConfig(argv[argc-1]);
  // setRotorConfig(contacts);
  // contacts.clear();
  cout << "config checked " << endl;

  // Once all config files are fine, create each component here
  plugboard_ = new Plugboard(argv[1]);
  reflector_ = new Reflector(argv[2]);
  if(argc == 3){
    num_of_rotors_ = 0;
  }
  else{
    num_of_rotors_ = argc-4;
  }
  // Is this even correct??
  cout << "num_of_rotors_ " << num_of_rotors_ << endl;
  if(num_of_rotors_ < 0){
    cerr << "No starting position for rotor 0 in rotor position file: rotor.pos";
    throw(NO_ROTOR_STARTING_POSITION);
  }

  initialiseRotorPosition(argv[argc-1]);
  checkRotorAndRotorPosition();
  for(int i = 0; i < num_of_rotors_; i++){
    // if starting_position is -1, do something!!

    Rotor rotor(argv[i+3], rotor_positions_[i]);
    rotors_.push_back(rotor);
  }
}

Enigma::~Enigma(){
    if(plugboard_){
        delete plugboard_;
    }
    if(reflector_){
        delete reflector_;
    }
}

// -------------------------------------------------------

void Enigma::checkPlugboardConfig(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(in_stream >> num){
    if(!isNumberRangeCorrect(num)){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      throw(INVALID_INDEX);
    }
    counter++;
  }

  if(in_stream.fail()&&!in_stream.eof()){
    cerr << "Non-numeric character in plugboard file plugboard.pb" << endl;
    throw(NON_NUMERIC_CHARACTER);
  }
  if(counter%2!=0 || counter > ALPHABET_LENGTH_){
    cerr << "Incorrect number of parameters in plugboard file plugboard.pb" << endl;
    throw(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
  }
}

void Enigma::checkReflectorConfig(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(in_stream >> num){
    if(!isNumberRangeCorrect(num)){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      throw(INVALID_INDEX);
    }
    counter++;
  }

  if(in_stream.fail()&&!in_stream.eof()){
    cerr << "Non-numeric character in reflector file reflector.rf" << endl;
    throw(NON_NUMERIC_CHARACTER);
  }
  if(counter%2!=0){
      cerr << "Incorrect (odd) number of parameters in reflector file reflector.rf" << endl;
      throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
    }
  if(counter != ALPHABET_LENGTH_){
    cerr << "Insufficient number of mappings in reflector file: reflector.rf" << endl;
    throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
  }
}

void Enigma::checkRotorConfig(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(in_stream >> num){
    if(!isNumberRangeCorrect(num)){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      throw(INVALID_INDEX);
    }
    counter++;
  }

  if(in_stream.fail()&&!in_stream.eof()){
    cerr <<   "Non-numeric character for mapping in rotor file rotor.rot" << endl;
    throw(NON_NUMERIC_CHARACTER);
  }

}

void Enigma::checkRotorPositionConfig(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(in_stream >> num ){
    // Can I abstruct this away?
    if(num > 25 || num < 0){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      throw(INVALID_INDEX);
    }
    rotor_positions_.push_back(num);
    counter++;
  }
  // Not elegant
  if(in_stream.eof()){
    in_stream.close();
    return;
  }
  if(in_stream.fail()){
  // File name should be more flexible
    cerr << "Non-numeric character in rotor positions file rotor.pos" << endl;
    in_stream.close();
    throw(NON_NUMERIC_CHARACTER);
  }

  // int diff = rotor_position_length - num_of_rotors_;
  //
  // if(diff < 0){
  //   cerr << "No starting position for rotor " << num_of_rotors_ + diff<< " in rotor position file: rotor.pos" << endl;
  //   throw(NO_ROTOR_STARTING_POSITION);
  // }
  // if(diff > 0){
  //   // This should not happen, I guess.
  // }
}




// int Enigma::checkInput(const char* path){
//   int num;
//   int counter = 0;
//   fstream in_stream;
//   in_stream.open(path);
//   if(in_stream.fail()){
//     cerr << "Error opening or reading the configulation file " << path << endl;
//     in_stream.close();
//     throw(ERROR_OPENING_CONFIGURATION_FILE);
//   }
//
//   while(in_stream >> num){
//     if(!isNumberRangeCorrect(num)){
//       cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
//       throw(INVALID_INDEX);
//     }
//     counter++;
//   }
//
//   if(in_stream.fail()&&!in_stream.eof()){
//     throwNonNumericCharacterError();
//     throw(NON_NUMERIC_CHARACTER);
//   }
//   return counter;
// }
//
// void Enigma::checkParameters(const int counter){
//     if(counter%2!=0){
//       cerr << "Incorrect (odd) number of parameters in reflector file reflector.rf" << endl;
//       throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
//     }
//     if(counter != ALPHABET_LENGTH_){
//       cerr << "Insufficient number of mappings in reflector file: reflector.rf" << endl;
//       throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
//     }
//     // What happens if more than 26 parameters
// }
//
// void Enigma::throwConfigError(){
//   cerr << INVALID_REFLECTOR_MAPPING << endl;
// }
//
// void Enigma::throwNonNumericCharacterError(){
//   cerr << "Non-numeric character in reflector file reflector.rf"  << endl;
// }
//
// void Enigma::throwInvalidMappingError(){
//   throw(INVALID_REFLECTOR_MAPPING);
// }


// Do I need this??
int Enigma::getArrayLength(const char* path){
  int counter = 0;
  int num;
  fstream in_stream;
  in_stream.open(path);
  while(!in_stream.eof() && in_stream >> num){
    counter++;
  }
  in_stream.close();
  return counter;
}

// This could be optimized!!
void Enigma::mapInputToArray(const char* path, int* array){
  int i=0;
  fstream in_stream;
  in_stream.open(path);
  int num;
  while(!in_stream.eof() && in_stream >> num){
    array[i] = num;
    i++;
  }
  in_stream.close();
}

bool Enigma::isNumberRangeCorrect(int num){
  return (num < ALPHABET_LENGTH_ && num >= 0);
}

// TODO Is this efficient?
void Enigma::checkDuplicateInt(int* array, int range){
  int previous_appeared_position;
  for(int i = range-1; i>= 0; i--){
    previous_appeared_position = isAppearedBefore(array, array[i], i);
    if(previous_appeared_position != -1){
      cerr << "Invalid mapping of input " << i << " to output " << array[i] << " (output " << array[i] << " is already mapped to from input " << previous_appeared_position << ")" << endl;
      // throwInvalidMappingError();
    }
  }
}

int Enigma::isAppearedBefore(int* array, int num, int position){
  for(int x = 0; x < position; x++ ){
    if(array[x] == array[position]){
      return x;
    }
  }
  return -1;
}

// -------------------------------------------------------

void Enigma::checkRotorAndRotorPosition(){
  int rotor_position_length = rotor_positions_.size();
  int diff = rotor_position_length - num_of_rotors_;

  if(diff < 0){
    cerr << "No starting position for rotor " << num_of_rotors_ + diff<< " in rotor position file: rotor.pos" << endl;
    throw(NO_ROTOR_STARTING_POSITION);
  }
  if(diff > 0){
    // This should not happen, I guess.
  }
}

void Enigma::initialiseRotorPosition(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(in_stream >> num ){
    // Can I abstruct this away?
    if(num > 25 || num < 0){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      throw(INVALID_INDEX);
    }
    rotor_positions_.push_back(num);
    counter++;
  }
  // Not elegant
  if(in_stream.eof()){
    in_stream.close();
    return;
  }
  if(in_stream.fail()){
  // File name should be more flexible
    cerr << "Non-numeric character in rotor positions file rotor.pos" << endl;
    in_stream.close();
    throw(NON_NUMERIC_CHARACTER);
  }
}

void Enigma::encryptMessage(char& message){
  int current_index = message - 'A';
  // cout << "current index before plugboard " << current_index << endl;
  current_index = plugboard_->map(current_index);

  if(num_of_rotors_ > 0){
    rotors_[num_of_rotors_-1].rotate();
  }

  if(num_of_rotors_ > 0){
    for(int i = num_of_rotors_ ; i > 0; i--){
      current_index = rotors_[i-1].shiftDown(current_index);
      // cout << "current_index1 " << current_index << endl;
      current_index = rotors_[i-1].map(current_index);
      // cout << "current_index2 " << current_index << endl;
      current_index = rotors_[i-1].shiftUp(current_index);
      // cout << "current_index3 " << current_index << endl;
      // TODO need to fix!!
      if(rotors_[i-1].isCurrentPositionInNotch() && \
         rotors_[i-1].getPreviousPosition() != \
         rotors_[i-1].getCurrentPosition()){
        // cout << "yes, notch at " << rotors_[i-1]->getCurrentPosition() << endl;
        if(i-1 > 0){
          rotors_[i-2].rotate();
        }
      }
    }
  }

  current_index = reflector_->map(current_index);
  // cout << "reversing from here... " << current_index << endl;
  if(num_of_rotors_ > 0){
    for(int i = 0; i < num_of_rotors_; i++){
      current_index = rotors_[i].shiftDown(current_index);
      // cout << "current_index1 " << current_index << endl;
      current_index = rotors_[i].mapBackward(current_index);
      // cout << "current_index2 " << current_index << endl;
      current_index = rotors_[i].shiftUp(current_index);
      // cout << "current_index3 " << current_index << endl;
    }
  }
  current_index = plugboard_->map(current_index);
  message = current_index + 'A';
}
