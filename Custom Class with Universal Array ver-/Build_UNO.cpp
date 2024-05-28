#include <iostream> // Include library for input and output
#include <cstdlib>  // Include library for Random integers
#include <ctime>    // Include library for getting time to seed the generator
#include "Memory_unit.cpp"

void ShuffleCards()
{ // Shuffle the cards for all players
  if (players >= 1)
  { // Shuffle Cards for Player 1
    for (int i = 0; i < startingCards; i++)
    { // Shuffle The number of Cards given as input
      DrawCard('1', i);
      PileCount[5] = startingCards;
    }
  }
  if (players >= 2)
  { // Shuffle Cards for Player 2
    for (int i = 0; i < startingCards; i++)
    { // Shuffle The number of Cards given as input
      DrawCard('2', i);
      PileCount[6] = startingCards;
    }
  }
  if (players >= 3)
  { // Shuffle Cards for Player 3
    for (int i = 0; i < startingCards; i++)
    { // Shuffle The number of Cards given as input
      DrawCard('3', i);
      PileCount[7] = startingCards;
    }
  }
  if (players == 4)
  { // Shuffle Cards for Player 4
    for (int i = 0; i < startingCards; i++)
    { // Shuffle The number of Cards given as input
      DrawCard('4', i);
      PileCount[8] = startingCards;
    }
  }
}

void StartGame()
{                                                            // Initializes the game
  std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the generator
  do
  { // Input Acceptable Data
    std::cout << "Enter Number of Players 1-4                    :  ";
    std::cin >> players;
    std::cout << '\n'
              << "Enter Number of Cards Each Player should have  :  ";
    std::cin >> startingCards;
    std::cout << '\n'
              << '\n';
    if (((108 - (players * startingCards)) < 21) || players > 4)
    {
      std::cout << "The number of cards remaining must be atleast 21, please try again" << '\n'
                << '\n'
                << '\n'; // Error Message
    }
  } while (((108 - (players * startingCards)) < 21) || players > 4); // Retry if error
  PileCount[9] = 1;

  CreateCards();    // Create and initialize all Card objects and Arrays
  ShuffleCards();   // Shuffle all cards and hand them to the players
  DrawCard('9', 0); // Place a Card in the discard pile
}