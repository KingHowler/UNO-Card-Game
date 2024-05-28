#include <iostream> // Include library for input and output
#include <cstdlib> // Include library for Random integers
#include <ctime>   // Include library for getting time to seed the generatorOffe

class Card { // Create a class for Card object
  public :
    int Colour, Number; // All Cards have a Colour and a Number in integer format

    // Built-in Dictionary for user output
    void printColour() { // Translates integer value of Colour into an understandable string
      switch (Colour) {
        case 1: std::cout << "Red      ";break;
        case 2: std::cout << "Blue     ";break;
        case 3: std::cout << "Green    ";break;
        case 4: std::cout << "Yellow   ";break;
      }
    }

    void printNumber() { // Translates integer value of Number into an understandable string
      switch (Number) {
        case 10: std::cout << "Skip" << '\n';break;
        case 11: std::cout << "Reverse" << '\n';break;
        case 12: std::cout << "Draw Two" << '\n';break;
        case 13: std::cout << "Wild" << '\n';break;
        case 14: std::cout << "Draw Four" << '\n';break;
        case -1: std::cout << '\n';;break;
        default : std::cout << Number << '\n';
      }
    }
};

// Declare all the Card objects, 109 Cards : 108 playable & 1 null Card
Card noCard;

// Declare All Piles as a single Array of offsets
Card Piles[25 + 25 + 25 + 25 + 8 + 108 + 108 + 108 + 108 + 108]; // [Red + Blue + Green + Yellow + Colorless + Player 1 + Player 2 + Player 3 + Player 4 + Discard Pile]

//  Declare A counter for each section of the Piles[] array as a second synced array
int PileCount[10] = {25,25,25,25,8,0,0,0,0,0}; // Number of Cards in each pile {Red,Blue,Green,Yellow,Colourless,p1,p2,p3,p4,DiscardPile}

int players, startingCards;

int Offset(char offsetOf) {
    switch (offsetOf)
    {
    case 'r':
        return 0;
        break;
    
    case 'b':
        return 25;
        break;
    case 'g':
        return 50;
        break;
    case 'y':
        return 75;
        break;
    case 'c':
        return 100;
        break;
    case '1':
        return 108;
        break;
    case '2':
        return 216;
        break;
    case '3':
        return 324;
        break;
    case '4':
        return 432;
        break;
    case '9':
        return 540;
        break;
    }
}

void CreateCards() { // Initialize the properties of the Cards

  for (int i = 0; i < 25; i++) { // Red,Blue,Green,Yellow
    //Set Colours
    Piles[i + Offset('r')].Colour = 1;
    Piles[i + Offset('b')].Colour = 2;
    Piles[i + Offset('g')].Colour = 3;
    Piles[i + Offset('y')].Colour = 4;

    //Set Numbers
    if (i <= 12) {
      Piles[i + Offset('r')].Number = i;
      Piles[i + Offset('b')].Number = i;
      Piles[i + Offset('g')].Number = i;
      Piles[i + Offset('y')].Number = i;
    } else {
      Piles[i + Offset('r')].Number = i - 12;
      Piles[i + Offset('b')].Number = i - 12;
      Piles[i + Offset('g')].Number = i - 12;
      Piles[i + Offset('y')].Number = i - 12;
    }
  }

  for (int i = 0; i < 8; i++) { // Colourless
    Piles[i + Offset('c')].Colour = 0;
    if ((i % 2) == 0) {
      Piles[i + Offset('c')].Number = 13;
    } else {Piles[i + Offset('c')].Number = 14;}
  }
  noCard.Number = -1;
  noCard.Colour = -1;

  for (int i = 0; i < 108; i++) { // p1,p2,p3,p4,DiscardPile
    ;
    Piles[i + Offset('1')] = noCard;
    Piles[i + Offset('2')] = noCard;
    Piles[i + Offset('3')] = noCard;
    Piles[i + Offset('4')] = noCard;
    Piles[i + Offset('9')] = noCard;
  }
}

void DrawCard(char pile, int index) { // Move random Card from Draw Pile to playerNo's pile at position index
  // temporary placeholders for drawing
  bool process = true;
  switch (pile)
  {
    case '1': break;
    case '2': break;
    case '3': break;
    case '4': break;
    case '9': break;
    default: process = false;break;
  }
  if (index > 107 || index < 0){process = false;}
  
  if (process == true)
  {
    
    char pileFrom;
    int color;
    int Number;

    // Select Colour
    do {
        Number = (std::rand() % 108);
        if (Number > 100) {color = 4; pileFrom = 'c';}
        if (100 > Number && Number >  75) {color = 3; pileFrom = 'y';}
        if (75  > Number && Number >  50) {color = 2; pileFrom = 'g';}
        if (50  > Number && Number >  25) {color = 1; pileFrom = 'b';}
        if (25  > Number && Number >   0) {color = 0; pileFrom = 'r';}
    } while(PileCount[color] <= 0 || (pile == '9' && color == 4)); // Make sure to select non-empty pile and pile is not Colourless if player is DiscardPile
    // Select Card, add to player deck, update Cards list
    switch (color) {
        case 4: // Colourless
            do {
                Number = (std::rand() % 8);
            } while(Piles[Number + Offset(pileFrom)].Number == -1); // Find a Card which is not a null Card
        break;
        default: // Red or Blue or Green or Yellow
            do {
                Number = (std::rand() % 25);
            } while(Piles[Number + Offset(pileFrom)].Number == -1); // Find a Card which is not a null Card
        break;
    }
    Piles[index + Offset(pile)] = Piles[Number + Offset(pileFrom)];
    Piles[Number + Offset(pileFrom)] = noCard; // Place null Card in draw pile to avoid duplicates of playable cards
    PileCount[color] = PileCount[color] - 1; // Decrement the number of Cards in the draw pile appropiatly
  }
}

void ShuffleCards() { // Shuffle the cards for all players
  if (players >= 1) { // Shuffle Cards for Player 1
    for (int i = 0; i < startingCards; i++) { // Shuffle The number of Cards given as input
      DrawCard('1', i);
      PileCount[5] = startingCards;
    }
  }
  if (players >= 2) { // Shuffle Cards for Player 2
    for (int i = 0; i < startingCards; i++) { // Shuffle The number of Cards given as input
      DrawCard('2', i);
      PileCount[6] = startingCards;
    }
  }
  if (players >= 3) { // Shuffle Cards for Player 3
    for (int i = 0; i < startingCards; i++) { // Shuffle The number of Cards given as input
      DrawCard('3', i);
      PileCount[7] = startingCards;
    }
  }
  if (players == 4) { // Shuffle Cards for Player 4
    for (int i = 0; i < startingCards; i++) { // Shuffle The number of Cards given as input
      DrawCard('4', i);
      PileCount[8] = startingCards;
    }
  }
}

void StartGame() { // Initializes the game
  std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the generator
  do { // Input Acceptable Data
    std::cout <<         "Enter Number of Players 1-4                    :  ";
    std::cin >> players;
    std::cout << '\n' << "Enter Number of Cards Each Player should have  :  ";
    std::cin >> startingCards;
    std::cout << '\n' << '\n';
    if (((108 - (players*startingCards)) < 21) || players > 4) {
      std::cout << "The number of cards remaining must be atleast 21, please try again" << '\n' << '\n' << '\n'; // Error Message
    }
  } while(((108 - (players*startingCards)) < 21) || players > 4); // Retry if error
  for (int i = 5; i < 9; i++) {
    ;PileCount[i] = startingCards;
  }
  PileCount[9] = 1;

  CreateCards(); // Create and initialize all Card objects and Arrays
  ShuffleCards(); // Shuffle all cards and hand them to the players
  DrawCard('9',0); // Place a Card in the discard pile
}