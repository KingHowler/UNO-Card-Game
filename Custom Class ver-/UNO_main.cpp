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
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  int players;
  int cards;

  std::cout << "Enter Number of Players 1-4 :  ";
  std::cin >> players;
  std::cout << '\n' << "Enter Number of Cards Each :  " ;
  std::cin >> cards;
  std::cout << '\n' << '\n';



  CreateCards();
  ShuffleCards(players, cards);

  if (players >= 1) {
    std::cout << "Player 1" << '\n';
    for (int i = 0; i < cards; i++) {
      std::cout << i << "    ";
      p1[i].printColour();
      p1[i].printNumber();
    }
  }
  if (players >= 2) {
    std::cout << '\n' << '\n';
    std::cout << "Player 2" << '\n';
    for (int i = 0; i < cards; i++) {
      std::cout << i << "    ";
      p2[i].printColour();
      p2[i].printNumber();
    }
  }
  if (players >= 3) {
    std::cout << '\n' << '\n';
    std::cout << "Player 3" << '\n';
    for (int i = 0; i < cards; i++) {
      std::cout << i << "    ";
      p3[i].printColour();
      p3[i].printNumber();
    }
  }
  if (players == 4) {
    std::cout << '\n' << '\n';
    std::cout << "Player 4" << '\n';
    for (int i = 0; i < cards; i++) {
      std::cout << i << "    ";
      p4[i].printColour();
      p4[i].printNumber();
    }
  }

  std::cout << '\n' << '\n' << "Red" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i  << "    ";
    Red[i].printColour();
    Red[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Blue" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i  << "    ";
    Blue[i].printColour();
    Blue[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Green" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i  << "    ";
    Green[i].printColour();
    Green[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Yellow" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i << "    ";
    Yellow[i].printColour();
    Yellow[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Colourless" << '\n';
  for (int i = 0; i < 8; i++) {
    std::cout << i << "    ";
    Colourless[i].printColour();
    Colourless[i].printNumber();
  }
  while (true) {}
  return 0;
}
