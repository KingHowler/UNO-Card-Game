#include <iostream>

class Card {
  public :
    int Colour, Number;
    void printColour() {
      switch (Colour) {
        case 1: std::cout << "Red      ";break;
        case 2: std::cout << "Blue     ";break;
        case 3: std::cout << "Green    ";break;
        case 4: std::cout << "Yellow   ";break;
      }
    }
    void printNumber() {
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

Card r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12,y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,c13,c14,noCard;

Card  Red[25] = {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12};
Card  Blue[25] = {b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12};
Card  Green[25] = {g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12};
Card  Yellow[25] = {y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12};
Card  Colourless[8] = {c13,c14,c13,c14,c13,c14,c13,c14};

Card p1[108];
Card p2[108];
Card p3[108];
Card p4[108];

Card DiscardPile[108];

int cardsRemaining[5] = {25,25,25,25,8};
int players,cards;

void CreateCards() {

  for (int i = 0; i < 25; i++) {
    //Set Colours
    Red[i].Colour = 1;
    Blue[i].Colour = 2;
    Green[i].Colour = 3;
    Yellow[i].Colour = 4;

    //Set Numbers
    if (i <= 12) {
      Red[i].Number = i;
      Blue[i].Number = i;
      Green[i].Number = i;
      Yellow[i].Number = i;
    } else {
      Red[i].Number = i - 12;
      Blue[i].Number = i - 12;
      Green[i].Number = i - 12;
      Yellow[i].Number = i - 12;
    }
  }

  for (int i = 0; i < 8; i++) {
    Colourless[i].Colour = 0;
    if ((i % 2) == 0) {
      Colourless[i].Number = 13;
    } else {Colourless[i].Number = 14;}
  }
  noCard.Number = -1;
  noCard.Colour = -1;

  for (int i = 0; i < 108; i++) {
    ;
    p1[i] = noCard;
    p2[i] = noCard;
    p3[i] = noCard;
    p4[i] = noCard;
    DiscardPile[i] = noCard;
  }
}

void DrawCard(int playerNo, int index) {
  int colour;
  int Number;

  // Select Colour
  do {
    Number = (std::rand() % 108);
    if (Number > 100) {colour = 4;}
    if (100 > Number && Number >  75) {colour = 3;}
    if (75  > Number && Number >  50) {colour = 2;}
    if (50  > Number && Number >  25) {colour = 1;}
    if (25  > Number && Number >   0) {colour = 0;}
  } while(cardsRemaining[colour] <= 0 || (playerNo == 9 && colour == 4));

  // Select Card, add to player deck, update Cards list
  switch (colour) {
    case 4:
    do {
      Number = (std::rand() % 8);
    } while(Colourless[Number].Number == -1);
    switch (playerNo) {
      case 1 : ; p1[index] = Colourless[Number]; break;
      case 2 : ; p2[index] = Colourless[Number]; break;
      case 3 : ; p3[index] = Colourless[Number]; break;
      case 4 : ; p4[index] = Colourless[Number]; break;
      case 9 : ; DiscardPile[index] = Colourless[Number]; break;
    }
    Colourless[Number] = noCard;
    cardsRemaining[colour] = cardsRemaining[colour] - 1;
    break;

    case 3:
    do {
      Number = (std::rand() % 25);
    } while(Yellow[Number].Number == -1);
    switch (playerNo) {
      case 1 : ; p1[index] = Yellow[Number]; break;
      case 2 : ; p2[index] = Yellow[Number]; break;
      case 3 : ; p3[index] = Yellow[Number]; break;
      case 4 : ; p4[index] = Yellow[Number]; break;
      case 9 : ; DiscardPile[index] = Yellow[Number]; break;
    }
    Yellow[Number] = noCard;
    cardsRemaining[colour] = cardsRemaining[colour] - 1;
    break;

    case 2:
    do {
      Number = (std::rand() % 25);
    } while(Green[Number].Number == -1);
    switch (playerNo) {
      case 1 : ; p1[index] = Green[Number]; break;
      case 2 : ; p2[index] = Green[Number]; break;
      case 3 : ; p3[index] = Green[Number]; break;
      case 4 : ; p4[index] = Green[Number]; break;
      case 9 : ; DiscardPile[index] = Green[Number]; break;
    }
    Green[Number] = noCard;
    cardsRemaining[colour] = cardsRemaining[colour] - 1;
    break;

    case 1:
    do {
      Number = (std::rand() % 25);
    } while(Blue[Number].Number == -1);
    switch (playerNo) {
      case 1 : ; p1[index] = Blue[Number]; break;
      case 2 : ; p2[index] = Blue[Number]; break;
      case 3 : ; p3[index] = Blue[Number]; break;
      case 4 : ; p4[index] = Blue[Number]; break;
      case 9 : ; DiscardPile[index] = Blue[Number]; break;
    }
    Blue[Number] = noCard;
    cardsRemaining[colour] = cardsRemaining[colour] - 1;
    break;

    case 0:
    do {
      Number = (std::rand() % 25);
    } while(Red[Number].Number == -1);
    switch (playerNo) {
      case 1 : ; p1[index] = Red[Number]; break;
      case 2 : ; p2[index] = Red[Number]; break;
      case 3 : ; p3[index] = Red[Number]; break;
      case 4 : ; p4[index] = Red[Number]; break;
      case 9 : ; DiscardPile[index] = Red[Number]; break;
    }
    Red[Number] = noCard;
    cardsRemaining[colour] = cardsRemaining[colour] - 1;
    break;
  }
}

void ShuffleCards() {
  if (players >= 1) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters
      DrawCard(1, i);
    }
  }
  if (players >= 2) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters
      DrawCard(2, i);
    }
  }
  if (players >= 3) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters
      DrawCard(3, i);
    }
  }
  if (players == 4) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters
      DrawCard(4, i);
    }
  }
}

void StartGame() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  do {
    std::cout <<         "Enter Number of Players 1-4                    :  ";
    std::cin >> players;
    std::cout << '\n' << "Enter Number of Cards Each Player should have  :  ";
    std::cin >> cards;
    std::cout << '\n' << '\n';
  } while(((108 - (players*cards)) < 21) || players > 4);

  CreateCards();
  ShuffleCards();
  DrawCard(9,0);
}

void DisplayPlayerCards(int playerNo) {
  switch (playerNo) {
    case 0:
      if (players >= 1) {
        std::cout << "Player 1" << '\n';
        for (int i = 0; i < cards; i++) {
          std::cout << i + 1 << "    ";
          p1[i].printColour();
          p1[i].printNumber();
        }
      }
      if (players >= 2) {
        std::cout << '\n' << '\n';
        std::cout << "Player 2" << '\n';
        for (int i = 0; i < cards; i++) {
          std::cout << i + 1 << "    ";
          p2[i].printColour();
          p2[i].printNumber();
        }
      }
      if (players >= 3) {
        std::cout << '\n' << '\n';
        std::cout << "Player 3" << '\n';
        for (int i = 0; i < cards; i++) {
          std::cout << i + 1 << "    ";
          p3[i].printColour();
          p3[i].printNumber();
        }
      }
      if (players == 4) {
        std::cout << '\n' << '\n';
        std::cout << "Player 4" << '\n';
        for (int i = 0; i < cards; i++) {
          std::cout << i + 1 << "    ";
          p4[i].printColour();
          p4[i].printNumber();
        }
      }
    break;
    case 1:
      std::cout << "Player 1" << '\n';
      for (int i = 0; i < cards; i++) {
        std::cout << i + 1 << "    ";
        p1[i].printColour();
        p1[i].printNumber();
      }
    break;
    case 2:
      std::cout << "Player 2" << '\n';
      for (int i = 0; i < cards; i++) {
        std::cout << i + 1 << "    ";
        p2[i].printColour();
        p2[i].printNumber();
      }
    break;
    case 3:
      std::cout << "Player 3" << '\n';
      for (int i = 0; i < cards; i++) {
        std::cout << i + 1 << "    ";
        p3[i].printColour();
        p3[i].printNumber();
      }
    break;
    case 4:
      std::cout << "Player 4" << '\n';
      for (int i = 0; i < cards; i++) {
        std::cout << i + 1 << "    ";
        p4[i].printColour();
        p4[i].printNumber();
      }
    break;
  }
}

void DisplayDrawPile() {
  std::cout << "Red" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i + 1 << "    ";
    Red[i].printColour();
    Red[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Blue" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i + 1 << "    ";
    Blue[i].printColour();
    Blue[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Green" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i + 1 << "    ";
    Green[i].printColour();
    Green[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Yellow" << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << i + 1 << "    ";
    Yellow[i].printColour();
    Yellow[i].printNumber();
  }
  std::cout << '\n' << '\n' << "Colourless" << '\n';
  for (int i = 0; i < 8; i++) {
    std::cout << i + 1 << "    ";
    Colourless[i].printColour();
    Colourless[i].printNumber();
  }
}

void DisplayDiscardPile() {
  std::cout << "Discard Pile" << '\n';
  for (int i = 0; i < 108; i++) {
    std::cout << i + 1 << "    ";
    DiscardPile[i].printColour();
    DiscardPile[i].printNumber();
  }
}
