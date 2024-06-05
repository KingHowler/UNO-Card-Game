#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
class Card
{
public:
    int Colour, Number;
    void printColour()
    {
        switch (Colour)
        {
        case 1:
            std::cout << "Red      ";
            break;
        case 2:
            std::cout << "Blue     ";
            break;
        case 3:
            std::cout << "Green    ";
            break;
        case 4:
            std::cout << "Yellow   ";
            break;
        }
    }
    void printNumber()
    {
        switch (Number)
        {
        case 10:
            std::cout << "Skip" << '\n';
            break;
        case 11:
            std::cout << "Reverse" << '\n';
            break;
        case 12:
            std::cout << "Draw Two" << '\n';
            break;
        case 13:
            std::cout << "Wild" << '\n';
            break;
        case 14:
            std::cout << "Draw Four" << '\n';
            break;
        case -1:
            std::cout << '\n';
            ;
            break;
        default:
            std::cout << Number << '\n';
        }
    }
};
Card noCard;
Card Piles[25 + 25 + 25 + 25 + 8 + 108 + 108 + 108 + 108 + 108];
int PileCount[10] = {25, 25, 25, 25, 8, 0, 0, 0, 0, 0};
int startingPlayers;
int startingCardsEach;
int playsOfCurrentPlayer;
int orderOfTurns;
int currentPlayer;
int indexOfCardToPlay;
int stillPlaying[] = {0, 0, 0, 0, 0};
int position[] = {0, 0, 0, 0, 0};
int playersDone[] = {0, 0, 0, 0, 0};
int Offset(int offsetOf)
{
    switch (offsetOf)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 25;
        break;
    case 2:
        return 50;
        break;
    case 3:
        return 75;
        break;
    case 4:
        return 100;
        break;
    case 5:
        return 108;
        break;
    case 6:
        return 216;
        break;
    case 7:
        return 324;
        break;
    case 8:
        return 432;
        break;
    case 9:
        return 540;
        break;
    }
}
void DrawCard(int pile, int index)
{
    bool process = true;
    switch (pile)
    {
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    default:
        process = false;
        break;
    }
    if (index > 107 || index < 0)
    {
        process = false;
    }
    if (process == true)
    {
        int color;
        int Number;
        do
        {
            Number = (std::rand() % 108);
            if (Number > 100)
            {
                color = 4;
            }
            if (100 > Number && Number > 75)
            {
                color = 3;
            }
            if (75 > Number && Number > 50)
            {
                color = 2;
            }
            if (50 > Number && Number > 25)
            {
                color = 1;
            }
            if (25 > Number && Number > 0)
            {
                color = 0;
            }
        } while (PileCount[color] <= 0 || (pile == 9 && color == 4));
        switch (color)
        {
        case 4:
            do
            {
                Number = (std::rand() % 8);
            } while (Piles[Number + Offset(color)].Number == -1);
            break;
        default:
            do
            {
                Number = (std::rand() % 25);
            } while (Piles[Number + Offset(color)].Number == -1);
            break;
        }
        Piles[index + Offset(pile)] = Piles[Number + Offset(color)];
        Piles[Number + Offset(color)] = noCard;
        PileCount[color] = PileCount[color] - 1;
        PileCount[pile] = PileCount[pile] + 1;
    }
}
void ReorderArray(int pile)
{
    bool process = true;
    int PlCMax;
    switch (pile)
    {
    case 0:
        PlCMax = 25;
        break;
    case 1:
        PlCMax = 25;
        break;
    case 2:
        PlCMax = 25;
        break;
    case 3:
        PlCMax = 25;
        break;
    case 4:
        PlCMax = 8;
        break;
    case 5:
        PlCMax = 108;
        break;
    case 6:
        PlCMax = 108;
        break;
    case 7:
        PlCMax = 108;
        break;
    case 8:
        PlCMax = 108;
        break;
    case 9:
        PlCMax = 108;
        break;
    default:
        process = false;
        break;
    }
    if (process == true)
    {
        bool flag;
        int NuC = 0;
        int PlC = 0;
        do
        {
            flag = false;
            if (Piles[NuC + Offset(pile)].Number == -1)
            {
                PlC = NuC;
                do
                {
                    if (Piles[PlC + Offset(pile)].Number != -1)
                    {
                        Piles[NuC + Offset(pile)] = Piles[PlC + Offset(pile)];
                        Piles[PlC + Offset(pile)] = noCard;
                        flag = true;
                    }
                    PlC += 1;
                } while (flag == false && PlC < PlCMax);
            }
            NuC += 1;
        } while (NuC < PlCMax && PlC < PlCMax);
    }
}
void DisplayCards(int pile)
{
    bool process = true;
    switch (pile)
    {
    case 0:
        std::cout << "Red" << '\n';
        break;
    case 1:
        std::cout << "Blue" << '\n';
        break;
    case 2:
        std::cout << "Green" << '\n';
        break;
    case 3:
        std::cout << "Yellow" << '\n';
        break;
    case 4:
        std::cout << "Colorless" << '\n';
        break;
    case 5:
        std::cout << "Player 1" << '\n';
        break;
    case 6:
        std::cout << "Player 2" << '\n';
        break;
    case 7:
        std::cout << "Player 3" << '\n';
        break;
    case 8:
        std::cout << "Player 4" << '\n';
        break;
    case 9:
        std::cout << "Discard Pile" << '\n';
        break;
    default:
        process = false;
        break;
    }
    if (process == true)
    {
        ReorderArray(pile);
        for (int i = 0; i < PileCount[pile]; i++)
        {
            std::cout << i << "    ";
            Piles[i + Offset(pile)].printColour();
            Piles[i + Offset(pile)].printNumber();
        }
        std::cout << '\n'
                  << '\n';
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
void ResetVariables()
{
    PileCount[0] = 25;
    PileCount[1] = 25;
    PileCount[2] = 25;
    PileCount[3] = 25;
    PileCount[4] = 8;
    for (int i = 0; i < 5; i++)
    {
        stillPlaying[i] = 0;
        position[i] = 0;
        playersDone[0] = 0;
        PileCount[i + 5] = 0;
    }
    startingPlayers = 0;
    startingCardsEach = 0;
    playsOfCurrentPlayer = 0;
    orderOfTurns = 0;
    currentPlayer = 0;
    indexOfCardToPlay = 0;
}