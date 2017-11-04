#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard{
private:
  int contacts[3];
public:
  Plugboard(const char* path);

  void swap_letters();

  void send_to_rotor();

  void send_back_output();

  int check_input(const char* path);

};

#endif
