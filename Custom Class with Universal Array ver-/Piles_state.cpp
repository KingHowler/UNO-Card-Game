#pragma once

#include <iostream>
#include "Memory_unit.cpp"

void ReorderArray(char pile)
{ // Reorder array so that there are no null cards in between
  bool process = true;
  int PlCMax;
  switch (pile)
  {
  case 'r':
    PlCMax = 25;
    break;
  case 'b':
    PlCMax = 25;
    break;
  case 'g':
    PlCMax = 25;
    break;
  case 'y':
    PlCMax = 25;
    break;
  case 'c':
    PlCMax = 8;
    break;
  case '1':
    PlCMax = 108;
    break;
  case '2':
    PlCMax = 108;
    break;
  case '3':
    PlCMax = 108;
    break;
  case '4':
    PlCMax = 108;
    break;
  case '9':
    PlCMax = 108;
    break;
  default:
    process = false;
    break;
  }
  if (process == true)
  {
    bool flag; // initialize a flag for checking if there was a rearrangement, if there was no rearrangement in a complete loop then array is ordered
    int NuC = 0;
    int PlC = 0;

    do
    { // begin loop for null card search
      flag = false;
      if (Piles[NuC + Offset(pile)].Number == -1)
      { // check for null card
        PlC = NuC;
        do
        { // if null card found, begin check for non-null card after null card
          if (Piles[PlC + Offset(pile)].Number != -1)
          { // if playable card found, exchange with null card and set flag as true
            Piles[NuC + Offset(pile)] = Piles[PlC + Offset(pile)];
            Piles[PlC + Offset(pile)] = noCard;
            flag = true;
          }
          PlC += 1; // increment counter for playable card check
        } while (flag == false && PlC < PlCMax); // exit loop if flag is true or no more exchanges were made to restart check
      }
      NuC += 1; // increment Null Card Check
    } while (NuC < PlCMax && PlC < PlCMax); // order completed when no PC found till PlCMax spaces
  }
}

void DisplayCards(char pile)
{
  bool process = true;
  int pileNo;
  switch (pile)
  {
  case 'r':
    std::cout << "Red" << '\n';
    pileNo = 0;
    break;
  case 'b':
    std::cout << "Blue" << '\n';
    pileNo = 1;
    break;
  case 'g':
    std::cout << "Green" << '\n';
    pileNo = 2;
    break;
  case 'y':
    std::cout << "Yellow" << '\n';
    pileNo = 3;
    break;
  case 'c':
    std::cout << "Colorless" << '\n';
    pileNo = 4;
    break;
  case '1':
    std::cout << "Player 1" << '\n';
    pileNo = 5;
    break;
  case '2':
    std::cout << "Player 2" << '\n';
    pileNo = 6;
    break;
  case '3':
    std::cout << "Player 3" << '\n';
    pileNo = 7;
    break;
  case '4':
    std::cout << "Player 4" << '\n';
    pileNo = 8;
    break;
  case '9':
    std::cout << "Discard Pile" << '\n';
    pileNo = 9;
    break;
  default:
    process = false;
    break;
  }
  if (process == true)
  {
    ReorderArray(pile);
    for (int i = 0; i < PileCount[pileNo]; i++)
    {
      std::cout << i << "    ";
      Piles[i + Offset(pile)].printColour();
      Piles[i + Offset(pile)].printNumber();
    }
  }
}

void DisplayUniversalPile()
{
  for (int i = 0; i < 648; i++)
  {
    std::cout << i << "    ";
    Piles[i].printColour();
    Piles[i].printNumber();
  }
}