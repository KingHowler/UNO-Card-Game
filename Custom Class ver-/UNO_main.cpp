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
extern Card p2[];
extern Card p3[];
extern Card p4[];

int main() {
  StartGame();
  DisplayPlayerCards(0);
  std::cout << '\n' << '\n';
  DisplayDrawPile();
  std::cout << '\n' << '\n';
  DisplayDiscardPile();

  while (true) {}
  return 0;
}
