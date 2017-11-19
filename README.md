

I decided to have one class called Component for both reflector and plugboard,
since their functionality in terms of mapping is essentially the same.

The program does all the input checking before initializing instances of Rotor and Component,

this design consideration is based on the fact that

Two shortcoming in terms of program design is that

Within the constructor of Enigma class, I check all the input errors. Thus if there is an error in configuration files, this construction will fail and throw exception (and is caught in try/catch in main.cpp). Throwing an exception within a constructor is not a good practice,

Also the spec says "the use of inheritance is not required", so I decided not to use it.
Another alternative would be to have global functions for some repetitive operations, such as input file stream etc.

// 4 checking methods could be abstracted into 1. However, since each config
// error message has different error code, I made 4 separate methods for each
