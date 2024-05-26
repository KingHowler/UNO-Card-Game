#include <iostream>
#include <cstdlib>
#include <ctime>

#include "UNO_Cards.cpp"

extern Card Red[];
extern Card Blue[];
extern Card Green[];
extern Card Yellow[];
extern Card Colourless[];

extern Card p1[];

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));


  CreateCards();
  ShuffleCards(1,30);

  for (int i = 0; i < 30; i++) {
    p1[i].printColour();
    p1[i].printNumber();
  }
  std::cout << '\n' << '\n';
  for (int i = 0; i < 25; i++) {
    Red[i].printColour();
    Red[i].printNumber();
  }
  while (true) {}
  return 0;
}
