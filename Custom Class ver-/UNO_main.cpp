#include <iostream>
#include <cstdlib>
#include <ctime>

#include "UNO_Cards.cpp"

extern Card Red[];
extern Card Blue[];
extern Card Green[];
extern Card Yellow[];
extern Card Colourless[];

int main() {

  CreateCards();
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  for (int i = 0; i < 25; i++) {
    Red[i].printColour();
    Red[i].printNumber();
  }
  while (true) {}
  return 0;
}
