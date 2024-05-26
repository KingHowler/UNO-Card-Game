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
  }
}

void ShuffleCards(int players, int cards) {
  int colour;
  int colourSize;
  int card;
  int randomNumber;

  int cardsRemaining[5] = {25,25,25,25,8};


  if (players >= 1) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters

      // Select Colour
      do {
        randomNumber = (std::rand() % 108);
        if (randomNumber > 100) {colour = 4; colourSize =  8;}
        if (100 > randomNumber && randomNumber >  75) {colour = 3; colourSize = 25;}
        if (75  > randomNumber && randomNumber >  50) {colour = 2; colourSize = 25;}
        if (50  > randomNumber && randomNumber >  25) {colour = 1; colourSize = 25;}
        if (25  > randomNumber && randomNumber >   0) {colour = 0; colourSize = 25;}
      } while(cardsRemaining[colour] == 0);


      // Select Card, add to player deck, update Cards list
      switch (colour) {
        case 4:
        do {
          card = (std::rand() % 8);
        } while(Colourless[card].Number == -1);
        p1[i] = Colourless[card];
        Colourless[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 3:
        do {
          card = (std::rand() % 25);
        } while(Yellow[card].Number == -1);
        p1[i] = Yellow[card];
        Yellow[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 2:
        do {
          card = (std::rand() % 25);
        } while(Green[card].Number == -1);
        p1[i] = Green[card];
        Green[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 1:
        do {
          card = (std::rand() % 25);
        } while(Blue[card].Number == -1);
        p1[i] = Blue[card];
        Blue[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 0:
        do {
          card = (std::rand() % 25);
        } while(Red[card].Number == -1);
        p1[i] = Red[card];
        Red[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;
      }
    }
  }
  if (players >= 2) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters

      // Select Colour
      do {
        randomNumber = (std::rand() % 108);
        if (randomNumber > 100) {colour = 4; colourSize =  8;}
        if (100 > randomNumber && randomNumber >  75) {colour = 3; colourSize = 25;}
        if (75  > randomNumber && randomNumber >  50) {colour = 2; colourSize = 25;}
        if (50  > randomNumber && randomNumber >  25) {colour = 1; colourSize = 25;}
        if (25  > randomNumber && randomNumber >   0) {colour = 0; colourSize = 25;}
      } while(cardsRemaining[colour] == 0);


      // Select Card, add to player deck, update Cards list
      switch (colour) {
        case 4:
        do {
          card = (std::rand() % 8);
        } while(Colourless[card].Number == -1);
        p2[i] = Colourless[card];
        Colourless[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 3:
        do {
          card = (std::rand() % 25);
        } while(Yellow[card].Number == -1);
        p2[i] = Yellow[card];
        Yellow[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 2:
        do {
          card = (std::rand() % 25);
        } while(Green[card].Number == -1);
        p2[i] = Green[card];
        Green[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 1:
        do {
          card = (std::rand() % 25);
        } while(Blue[card].Number == -1);
        p2[i] = Blue[card];
        Blue[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 0:
        do {
          card = (std::rand() % 25);
        } while(Red[card].Number == -1);
        p2[i] = Red[card];
        Red[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;
      }
    }
  }
  if (players >= 3) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters

      // Select Colour
      do {
        randomNumber = (std::rand() % 108);
        if (randomNumber > 100) {colour = 4; colourSize =  8;}
        if (100 > randomNumber && randomNumber >  75) {colour = 3; colourSize = 25;}
        if (75  > randomNumber && randomNumber >  50) {colour = 2; colourSize = 25;}
        if (50  > randomNumber && randomNumber >  25) {colour = 1; colourSize = 25;}
        if (25  > randomNumber && randomNumber >   0) {colour = 0; colourSize = 25;}
      } while(cardsRemaining[colour] == 0);


      // Select Card, add to player deck, update Cards list
      switch (colour) {
        case 4:
        do {
          card = (std::rand() % 8);
        } while(Colourless[card].Number == -1);
        p3[i] = Colourless[card];
        Colourless[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 3:
        do {
          card = (std::rand() % 25);
        } while(Yellow[card].Number == -1);
        p3[i] = Yellow[card];
        Yellow[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 2:
        do {
          card = (std::rand() % 25);
        } while(Green[card].Number == -1);
        p3[i] = Green[card];
        Green[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 1:
        do {
          card = (std::rand() % 25);
        } while(Blue[card].Number == -1);
        p3[i] = Blue[card];
        Blue[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 0:
        do {
          card = (std::rand() % 25);
        } while(Red[card].Number == -1);
        p3[i] = Red[card];
        Red[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;
      }
    }
  }
  if (players == 4) { // Shuffle Cards for Player 1
    for (int i = 0; i < cards; i++) { // Shuffle The number of Cards given as parmaeters

      // Select Colour
      do {
        randomNumber = (std::rand() % 108);
        if (randomNumber > 100) {colour = 4; colourSize =  8;}
        if (100 > randomNumber && randomNumber >  75) {colour = 3; colourSize = 25;}
        if (75  > randomNumber && randomNumber >  50) {colour = 2; colourSize = 25;}
        if (50  > randomNumber && randomNumber >  25) {colour = 1; colourSize = 25;}
        if (25  > randomNumber && randomNumber >   0) {colour = 0; colourSize = 25;}
      } while(cardsRemaining[colour] == 0);


      // Select Card, add to player deck, update Cards list
      switch (colour) {
        case 4:
        do {
          card = (std::rand() % 8);
        } while(Colourless[card].Number == -1);
        p4[i] = Colourless[card];
        Colourless[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 3:
        do {
          card = (std::rand() % 25);
        } while(Yellow[card].Number == -1);
        p4[i] = Yellow[card];
        Yellow[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 2:
        do {
          card = (std::rand() % 25);
        } while(Green[card].Number == -1);
        p4[i] = Green[card];
        Green[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 1:
        do {
          card = (std::rand() % 25);
        } while(Blue[card].Number == -1);
        p4[i] = Blue[card];
        Blue[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;

        case 0:
        do {
          card = (std::rand() % 25);
        } while(Red[card].Number == -1);
        p4[i] = Red[card];
        Red[card] = noCard;
        cardsRemaining[colour] = cardsRemaining[colour] - 1;
        break;
      }
    }
  }
}
