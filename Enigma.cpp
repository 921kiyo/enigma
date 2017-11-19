#include "Enigma.h"
#include "Rotor.h"
#include "Component.h"
#include "errors.h"
#include "alphabet.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Enigma::Enigma(int argc, char** argv){
  vector<int> plugboard_contacts;
  checkPlugboardConfig(argv[1],plugboard_contacts);
  vector<int> reflector_contacts;
  checkReflectorConfig(argv[2], reflector_contacts);
  vector<vector<int>> rotor_contacts_array;
  vector<int> rotor_contacts;
  for(int i = 3; i < argc-1; i++){
    checkRotorConfig(argv[i], rotor_contacts);
    rotor_contacts_array.push_back(rotor_contacts);
    rotor_contacts.clear();
  }
  if(argc == 3){
    num_of_rotors_ = 0;
  }
  else{
    num_of_rotors_ = argc-4;
  }
  checkRotorPositionConfig(argv[argc-1]);

  // After checking all config files, instantiate each component so that
  // There is no concern for memory leak, even if constructor fails in the middle
  // of construction.

  plugboard_ = new Component(argv[1]);
  reflector_ = new Component(argv[2]);
  for(int i = 0; i < num_of_rotors_; i++){
    // if starting_position is -1, do something!!
    Rotor rotor(argv[3+i], rotor_positions_[i]);
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

bool Enigma::plugboardInputCheck(const char* path, fstream& in_stream, int& index_num){
  in_stream >> ws;
  int end_of_file = in_stream.peek();
  if(end_of_file == EOF){
    return false;
  }
  in_stream >> index_num;
  if(in_stream.fail()){
    cerr << "Non-numeric character in plugboard file " << path << endl;
    in_stream.close();
    throw(NON_NUMERIC_CHARACTER);
  }
  if(!isNumberRangeCorrect(index_num)){
    cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
    in_stream.close();
    throw(INVALID_INDEX);
  }
  return true;
}

void Enigma::checkPlugboardConfig(const char* path, vector<int>& contacts){
  int even_index_num, odd_index_num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(!in_stream.eof()){
    if(!plugboardInputCheck(path, in_stream, even_index_num)){
      break;
    }
    if(!plugboardInputCheck(path, in_stream, odd_index_num)){
      cerr << "Incorrect number of parameters in plugboard file " << path << endl;
      in_stream.close();
      throw(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
    }
    contacts.push_back(even_index_num);
    if(checkAppearedBefore(contacts, even_index_num, counter) != -1){
      cout << "plugboard1 " << endl;
      in_stream.close();
      throw(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
    }
    counter++;

    contacts.push_back(odd_index_num);
    if(checkAppearedBefore(contacts, odd_index_num, counter) != -1){
      in_stream.close();
      cout << "plugboard2 " << endl;
      throw(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
    }
    counter++;
  }
  in_stream.close();
}

void Enigma::checkReflectorConfig(const char* path, vector<int>& contacts){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(!in_stream.eof()){
    in_stream >> ws;
    int end_of_file = in_stream.peek();
    if(end_of_file == EOF){
      if(counter%2!=0){
          cerr << "Incorrect (odd) number of parameters in reflector file " \
          << path << endl;
          in_stream.close();
          throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
      }
      if(counter != ALPHABET_LENGTH){
        cerr << "Insufficient number of mappings in reflector file: " \
        << path << endl;
        in_stream.close();
        throw(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
      }
    }

    in_stream >> num;
    if(in_stream.fail()){
      cerr << "Non-numeric character in reflector file " << path << endl;
      in_stream.close();
      throw(NON_NUMERIC_CHARACTER);
    }
    if(!isNumberRangeCorrect(num)){
      cerr << "The file " << path << \
      " contains a number that is not between 0 and 25" << endl;
      in_stream.close();
      throw(INVALID_INDEX);
    }
    contacts.push_back(num);
    if(checkAppearedBefore(contacts, num, counter) != -1){
      in_stream.close();
      throw(INVALID_REFLECTOR_MAPPING);
    }
    counter++;
  }
  in_stream.close();
}

void Enigma::checkRotorConfig(const char* path, vector<int>& contacts){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }

  while(!in_stream.eof()){
    in_stream >> ws;
    int end_of_file = in_stream.peek();
    if(end_of_file == EOF){
      break;
    }
    in_stream >> num;

    if(in_stream.fail()){
      cerr << "Non-numeric character for mapping in rotor file " << path << endl;
      in_stream.close();
      throw(NON_NUMERIC_CHARACTER);
    }
    if(!isNumberRangeCorrect(num)){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      in_stream.close();
      throw(INVALID_INDEX);
    }
    contacts.push_back(num);

    if(counter < ALPHABET_LENGTH-1 && checkAppearedBefore(contacts, num, counter) != -1){
      in_stream.close();
      throw(INVALID_ROTOR_MAPPING);
    }
    counter++;
  }
  in_stream.close();

  if(counter < ALPHABET_LENGTH){
    cerr << "Not all inputs mapped in rotor file: " << path << endl;
    throw(INVALID_ROTOR_MAPPING);
  }
}

void Enigma::checkRotorPositionConfig(const char* path){
  int num;
  int counter = 0;
  fstream in_stream;
  in_stream.open(path);
  if(in_stream.fail()){
    cerr << "Error opening or reading the configulation file " << path << endl;
    in_stream.close();
    throw(ERROR_OPENING_CONFIGURATION_FILE);
  }
  while(!in_stream.eof()){
    in_stream >> ws;
    int eof = in_stream.peek();
    if(eof == EOF){
      break;
    }
    in_stream >> num;
    if(in_stream.fail()){
      cerr << "Non-numeric character in rotor positions file " << path  << endl;
      in_stream.close();
      throw(NON_NUMERIC_CHARACTER);
    }

    if(!isNumberRangeCorrect(num)){
      cerr << "The file " << path << " contains a number that is not between 0 and 25" << endl;
      in_stream.close();
      throw(INVALID_INDEX);
    }
    counter++;
    rotor_positions_.push_back(num);
  }

  int diff = counter - num_of_rotors_;
  if(diff < 0){
    cerr << "No starting position for rotor " << num_of_rotors_ + diff<< " in rotor position file: " << path << endl;
    in_stream.close();
    throw(NO_ROTOR_STARTING_POSITION);
  }
  // TODO Double check this
  if(diff > 0){
    // This should not happen, I guess.
  }
  in_stream.close();
}

bool Enigma::isNumberRangeCorrect(int num){
  return (num < ALPHABET_LENGTH && num >= 0);
}

int Enigma::checkAppearedBefore(vector<int> contacts, int num, int position){
  for(int i = 0; i < position; i++ ){
    if(contacts[i] == num){
      cerr << "Invalid mapping of input " << position << " to output " << num \
      << " (output " << num << " is already mapped to from input " \
      << i << ")" << endl;
      return i;
    }
  }
  return -1;
}

void Enigma::encryptMessage(char& letter){
  int current_index = letter - 'A';
  // cout << "current index before plugboard " << current_index << endl;
  current_index = plugboard_->map(current_index);

  if(num_of_rotors_ > 0){
    rotors_[num_of_rotors_-1].rotate();
  }

  if(num_of_rotors_ > 0){
    for(int i = num_of_rotors_ ; i > 0; i--){
      // TODO Needs explanation here
      current_index = rotors_[i-1].shiftDown(current_index);
      // cout << "current_index1 " << current_index << endl;
      current_index = rotors_[i-1].mapForward(current_index);
      // cout << "current_index2 " << current_index << endl;
      current_index = rotors_[i-1].shiftUp(current_index);
      // cout << "current_index3 " << current_index << endl;
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
  letter = current_index + 'A';
}
