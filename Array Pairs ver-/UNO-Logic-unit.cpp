#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UNO_functions.cpp"
#include "UNO_Cards.cpp"

/*
Dictionary

0 = 0
1 = 1
2 = 2
3 = 3
4 = 4
5 = 5
6 = 6
7 = 7
8 = 8
9 = 9
10 = Skip
11 = Reverse
12 = Draw Two
13 = Wild
14 = Draw Four
99 = null
*/

std::string ditctionary[19] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip", "Reverse", "Draw Two", "Wild", "Draw Four", "Red", "Blue", "Green", "Yellow"};

int    red[25]      =       {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12};
int    blue[25]     =       {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12};
int    green[25]    =       {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12};
int    yellow[25]   =       {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12};
int    wild[8]      =       {13, 13, 13, 13, 14, 14, 14, 14};

int p1[108];
int cp1[108];

int p2[108];
int cp2[108];

int p3[108];
int cp3[108];

int p4[108];
int cp4[108];

void initializeCards() { // initialize all cards as null and seed generator
  for (int i = 0; i < 108; i++) {
    p1[i] = 99;
  }
  for (int i = 0; i < 108; i++) {
    p2[i] = 99;
  }
  for (int i = 0; i < 108; i++) {
    p3[i] = 99;
  }
  for (int i = 0; i < 108; i++) {
    p4[i] = 99;
  }
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void shuffleCards() {
  int deck; // red / blue / green / yellow / wild
  int size; // length of deck
  int buff; // buffer to store value to be cecked
  int n; //rand generated number

  // shuffle for p1
  for (int i = 0; i < 10; i++) {
    // select deck
     n = (std::rand() % 108);
     if (n > 100) {deck = 5; size =  8;}
     if (100 > n && n >  75) {deck = 4; size = 25;}
     if (75  > n && n >  50) {deck = 3; size = 25;}
     if (50  > n && n >  25) {deck = 2; size = 25;}
     if (25  > n && n >   0) {deck = 1; size = 25;}

    // select card
    switch (deck) {
      case 5:
      do {
        buff = (std::rand() % 2) + 13;
      } while(linearSearch(wild, 8, buff) == 99);
      wild[linearSearch(wild, 8, buff)] = 99;
      break;

      case 4:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(yellow, 25, buff) == 99);
      yellow[linearSearch(yellow, 25, buff)] = 99;
      break;

      case 3:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(green, 25, buff) == 99);
      green[linearSearch(green, 25, buff)] = 99;
      break;

      case 2:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(blue, 25, buff) == 99);
      blue[linearSearch(blue, 25, buff)] = 99;
      break;

      case 1:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(red, 25, buff) == 99);
      red[linearSearch(red, 25, buff)] = 99;
      break;

    }

    // add card
    p1[i] = buff;
    cp1[i] = deck + 14;
  }

  //shuffle for p2
  for (int i = 0; i < 10; i++) {
    // select deck
     n = (std::rand() % 108);
     if (n > 100) {deck = 5; size =  8;}
     if (100 > n && n >  75) {deck = 4; size = 25;}
     if (75  > n && n >  50) {deck = 3; size = 25;}
     if (50  > n && n >  25) {deck = 2; size = 25;}
     if (25  > n && n >   0) {deck = 1; size = 25;}

    // select card
    switch (deck) {
      case 5:
      do {
        buff = (std::rand() % 2) + 13;
      } while(linearSearch(wild, 8, buff) == 99);
      wild[linearSearch(wild, 8, buff)] = 99;
      break;

      case 4:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(yellow, 25, buff) == 99);
      yellow[linearSearch(yellow, 25, buff)] = 99;
      break;

      case 3:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(green, 25, buff) == 99);
      green[linearSearch(green, 25, buff)] = 99;
      break;

      case 2:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(blue, 25, buff) == 99);
      blue[linearSearch(blue, 25, buff)] = 99;
      break;

      case 1:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(red, 25, buff) == 99);
      red[linearSearch(red, 25, buff)] = 99;
      break;

    }

    // add card
    p2[i] = buff;
    cp2[i] = deck + 14;
  }

  //shuffle for p3
  for (int i = 0; i < 10; i++) {
    // select deck
     n = (std::rand() % 108);
     if (n > 100) {deck = 5; size =  8;}
     if (100 > n && n >  75) {deck = 4; size = 25;}
     if (75  > n && n >  50) {deck = 3; size = 25;}
     if (50  > n && n >  25) {deck = 2; size = 25;}
     if (25  > n && n >   0) {deck = 1; size = 25;}

    // select card
    switch (deck) {
      case 5:
      do {
        buff = (std::rand() % 2) + 13;
      } while(linearSearch(wild, 8, buff) == 99);
      wild[linearSearch(wild, 8, buff)] = 99;
      break;

      case 4:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(yellow, 25, buff) == 99);
      yellow[linearSearch(yellow, 25, buff)] = 99;
      break;

      case 3:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(green, 25, buff) == 99);
      green[linearSearch(green, 25, buff)] = 99;
      break;

      case 2:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(blue, 25, buff) == 99);
      blue[linearSearch(blue, 25, buff)] = 99;
      break;

      case 1:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(red, 25, buff) == 99);
      red[linearSearch(red, 25, buff)] = 99;
      break;

    }

    // add card
    p3[i] = buff;
    cp3[i] = deck + 14;
  }

  // shuffle for p4
  for (int i = 0; i < 10; i++) {
    // select deck
     n = (std::rand() % 108);
     if (n > 100) {deck = 5; size =  8;}
     if (100 > n && n >  75) {deck = 4; size = 25;}
     if (75  > n && n >  50) {deck = 3; size = 25;}
     if (50  > n && n >  25) {deck = 2; size = 25;}
     if (25  > n && n >   0) {deck = 1; size = 25;}

    // select card
    switch (deck) {
      case 5:
      do {
        buff = (std::rand() % 2) + 13;
      } while(linearSearch(wild, 8, buff) == 99);
      wild[linearSearch(wild, 8, buff)] = 99;
      break;

      case 4:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(yellow, 25, buff) == 99);
      yellow[linearSearch(yellow, 25, buff)] = 99;
      break;

      case 3:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(green, 25, buff) == 99);
      green[linearSearch(green, 25, buff)] = 99;
      break;

      case 2:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(blue, 25, buff) == 99);
      blue[linearSearch(blue, 25, buff)] = 99;
      break;

      case 1:
      do {
        buff = (std::rand() % 13);
      } while(linearSearch(red, 25, buff) == 99);
      red[linearSearch(red, 25, buff)] = 99;
      break;

    }

    // add card
    p4[i] = buff;
    cp4[i] = deck + 14;
  }

}

int main() {
  initializeCards();
  shuffleCards();
  std::cout << "shuffled for p1" << '\n';
  for (int i = 0; i < 10; i++) {
    std::cout << ditctionary[cp1[i]] << "  " << ditctionary[p1[i]] << '\n';
  }
  std::cout << '\n' << '\n' << "shuffled for p2" << '\n';
  for (int i = 0; i < 10; i++) {
    std::cout << ditctionary[cp2[i]] << "  " << ditctionary[p2[i]] << '\n';
  }
  std::cout << '\n' << '\n' <<  "shuffled for p3" << '\n';
  for (int i = 0; i < 10; i++) {
    std::cout << ditctionary[cp3[i]] << "  " << ditctionary[p3[i]] << '\n';
  }
  std::cout << '\n' << '\n' <<  "shuffled for p4" << '\n';
  for (int i = 0; i < 10; i++) {
    std::cout << ditctionary[cp4[i]] << "  " << ditctionary[p4[i]] << '\n';
  }

  /*std::cout << '\n' << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << red[i] << '\n';
  }
  std::cout << '\n' << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << blue[i] << '\n';
  }
  std::cout << '\n' << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << green[i] << '\n';
  }
  std::cout << '\n' << '\n';
  for (int i = 0; i < 25; i++) {
    std::cout << yellow[i] << '\n';
  }
  std::cout << '\n' << '\n';
  for (int i = 0; i < 8; i++) {
    std::cout << wild[i] << '\n';
  }*/
  while (true) {
    /* code */
  }
  return 0;
}
