#pragma once
#include <cstdlib> // Include library for Random integers
#include <ctime>   // Include library for getting time to seed the generator
#include "slave\memory.cpp"

void CreateCards()
{ // Initialize the properties of the Cards

    for (int i = 0; i < 25; i++)
    { // Red,Blue,Green,Yellow
        // Set Colours
        Piles[i + Offset(0)].Colour = 1;
        Piles[i + Offset(1)].Colour = 2;
        Piles[i + Offset(2)].Colour = 3;
        Piles[i + Offset(3)].Colour = 4;

        // Set Numbers
        if (i <= 12)
        {
            Piles[i + Offset(0)].Number = i;
            Piles[i + Offset(1)].Number = i;
            Piles[i + Offset(2)].Number = i;
            Piles[i + Offset(3)].Number = i;
        }
        else
        {
            Piles[i + Offset(0)].Number = i - 12;
            Piles[i + Offset(1)].Number = i - 12;
            Piles[i + Offset(2)].Number = i - 12;
            Piles[i + Offset(3)].Number = i - 12;
        }
    }

    for (int i = 0; i < 8; i++)
    { // Colourless
        Piles[i + Offset(4)].Colour = 0;
        if ((i % 2) == 0)
        {
            Piles[i + Offset(4)].Number = 13;
        }
        else
        {
            Piles[i + Offset(4)].Number = 14;
        }
    }
    noCard.Number = -1;
    noCard.Colour = -1;

    for (int i = 0; i < 108; i++)
    { // p1,p2,p3,p4,DiscardPile
        ;
        Piles[i + Offset(5)] = noCard;
        Piles[i + Offset(6)] = noCard;
        Piles[i + Offset(7)] = noCard;
        Piles[i + Offset(8)] = noCard;
        Piles[i + Offset(9)] = noCard;
    }
}

void ShuffleCards()
{ // Shuffle the cards for all players
    if (startingPlayers >= 1)
    { // Shuffle Cards for Player 1
        for (int i = 0; i < startingCardsEach; i++)
        { // Shuffle The number of Cards given as input
            DrawCard(5, i);
        }
        stillPlaying[1] = 1;
    }
    if (startingPlayers >= 2)
    { // Shuffle Cards for Player 2
        for (int i = 0; i < startingCardsEach; i++)
        { // Shuffle The number of Cards given as input
            DrawCard(6, i);
        }
        stillPlaying[2] = 1;
    }
    if (startingPlayers >= 3)
    { // Shuffle Cards for Player 3
        for (int i = 0; i < startingCardsEach; i++)
        { // Shuffle The number of Cards given as input
            DrawCard(7, i);
        }
        stillPlaying[3] = 1;
    }
    if (startingPlayers == 4)
    { // Shuffle Cards for Player 4
        for (int i = 0; i < startingCardsEach; i++)
        { // Shuffle The number of Cards given as input
            DrawCard(8, i);
        }
        stillPlaying[4] = 1;
    }
}

void StartGame()
{                                                              // Initializes the game
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the generator
    do
    { // Input Acceptable Data
        std::cout << "Enter Number of Players 1-4                    :  ";
        std::cin >> startingPlayers;
        std::cout << '\n'
                  << "Enter Number of Cards Each Player should have  :  ";
        std::cin >> startingCardsEach;
        std::cout << '\n'
                  << '\n';
        if (((108 - (startingPlayers * startingCardsEach)) < 21) || startingPlayers > 4)
        {
            std::cout << "The number of cards remaining must be atleast 21, please try again" << '\n'
                      << '\n'
                      << '\n'; // Error Message
        }
    } while (((108 - (startingPlayers * startingCardsEach)) < 21) || startingPlayers > 4); // Retry if error

    for (int i = 1; i < startingPlayers + 1; i++)
    {
        stillPlaying[i] = 1;
    }

    CreateCards();  // Create and initialize all Card objects and Arrays
    ShuffleCards(); // Shuffle all cards and hand them to the players
    DrawCard(9, 0); // Place a Card in the discard pile
}