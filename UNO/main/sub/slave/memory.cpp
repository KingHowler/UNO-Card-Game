#pragma once
#include <iostream>

class Card
{ // Create a class for Card object
public:
    int Colour, Number; // All Cards have a Colour and a Number in integer format

    // Built-in Dictionary for user output
    void printColour()
    { // Translates integer value of Colour into an understandable string
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
    { // Translates integer value of Number into an understandable string
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

// Declare all the Card objects, 109 Cards : 108 playable & 1 null Card
Card noCard;

// Declare All Piles as a single Array of offsets
Card Piles[25 + 25 + 25 + 25 + 8 + 108 + 108 + 108 + 108 + 108]; // [Red + Blue + Green + Yellow + Colorless + Player 1 + Player 2 + Player 3 + Player 4 + Discard Pile]

//  Declare A counter for each section of the Piles[] array as a second synced array
int PileCount[10] = {25, 25, 25, 25, 8, 0, 0, 0, 0, 0}; // Number of Cards in each pile {Red,Blue,Green,Yellow,Colourless,p1,p2,p3,p4,DiscardPile}

int startingPlayers;
int startingCardsEach;
int playsOfCurrentPlayer;
int orderOfTurns;
int currentPlayer;
int indexOfCardToPlay;
int stillPlaying[] = {0, 0, 0, 0, 0};
int position[4];

int Offset(int offsetOf) // Offset of Cards in each pile in the universal Pile {Red,Blue,Green,Yellow,Colourless,p1,p2,p3,p4,DiscardPile}
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

void DrawCard(int pile, int index) // Move random Card from Draw Pile to playerNo's pile at position index
{
    bool process = true; // Paramenter Error Check to avoid crashes
    switch (pile)        // check for pile
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
    if (index > 107 || index < 0) // check for index
    {
        process = false;
    }

    if (process == true) // run code if parameters is correct
    {
        int color;
        int Number;

        // Select Colour
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
        } while (PileCount[color] <= 0 || (pile == 9 && color == 4)); // Make sure to select non-empty pile and pile is not Colourless if player is DiscardPile
        // Select Card, add to player deck, update Cards list
        switch (color)
        {
        case 4: // Colourless
            do
            {
                Number = (std::rand() % 8);
            } while (Piles[Number + Offset(color)].Number == -1); // Find a Card which is not a null Card
            break;
        default: // Red or Blue or Green or Yellow
            do
            {
                Number = (std::rand() % 25);
            } while (Piles[Number + Offset(color)].Number == -1); // Find a Card which is not a null Card
            break;
        }
        Piles[index + Offset(pile)] = Piles[Number + Offset(color)]; // Place Card from Draw Pile Region of Universal Array to Region and index specified
        Piles[Number + Offset(color)] = noCard;                      // Place null Card in draw pile to avoid duplicates of playable cards
        PileCount[color] = PileCount[color] - 1;                     // Decrement the number of Cards in the draw pile appropiatly
        PileCount[pile] = PileCount[pile] + 1;                       // Increment the number of cards in the pile drawn to
    }
}

void ReorderArray(int pile)
{ // Reorder array so that there are no null cards in between
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
