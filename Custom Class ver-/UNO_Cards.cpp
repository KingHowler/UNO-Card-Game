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
        default : std::cout << Number << '\n';
      }
    }
};

Card r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12,y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,c13,c14;

Card  Red[25] = {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12};
Card  Blue[25] = {b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12};
Card  Green[25] = {g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12};
Card  Yellow[25] = {y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12};
Card  Colourless[8] = {c13,c14,c13,c14,c13,c14,c13,c14};

Card p1[10] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
Card p2[10] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
Card p3[10] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
Card p4[10] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

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
    if ((i % 2) == 1) {
      Colourless[i].Number = 13;
    } else {Colourless[i].Number = 14;}
  }
}

void ShuffleCards() {
  /* code */
}
