#include <iostream>

#include "Piles_state.cpp"
#include "Build_UNO.cpp"
#include "Card_FDE.cpp"

int main()
{
  StartGame();
  DisplayCards('1');
  std::cout << '\n'
            << '\n';
  DisplayCards('2');
  std::cout << '\n'
            << '\n';
  DisplayCards('3');
  std::cout << '\n'
            << '\n';
  DisplayCards('4');
  std::cout << '\n'
            << '\n';
  DisplayCards('c');
  std::cout << '\n'
            << '\n';
  for (int i = 0; i < 10; i++)
  {
    std::cout << PileCount[i] << "   ";
  }
  std::cout << '\n'
            << '\n';
  DisplayCards('9');

  Gameloop();
  while (true)
  {
  }
  return 0;
}
