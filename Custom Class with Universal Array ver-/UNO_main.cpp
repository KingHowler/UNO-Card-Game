#include <iostream>

#include "Display.cpp"

extern int players;
extern int startingCards;

int main() {
  StartGame();
  DisplayCards('1');
  std::cout << '\n' << '\n';
  DisplayCards('2');
  std::cout << '\n' << '\n';
  DisplayCards('3');
  std::cout << '\n' << '\n';
  DisplayCards('4');
  std::cout << '\n' << '\n';
  DisplayCards('r');
  std::cout << '\n' << '\n';
  DisplayCards('b');
  std::cout << '\n' << '\n';
  DisplayCards('g');
  std::cout << '\n' << '\n';
  DisplayCards('y');
  std::cout << '\n' << '\n';
  DisplayCards('c');
  std::cout << '\n' << '\n';
  for (int i = 0; i < 10; i++)
  {
    std::cout << PileCount[i] << "   ";
  }
  std::cout << '\n' << '\n';
  DisplayCards('9');
  

  while (true) {}
  return 0;
}
