#pragma once
#include "slave\memory.cpp"
void CreateCards()
{
    for (int i = 0; i < 25; i++)
    {
        Piles[i + Offset(0)].Colour = 1;
        Piles[i + Offset(1)].Colour = 2;
        Piles[i + Offset(2)].Colour = 3;
        Piles[i + Offset(3)].Colour = 4;
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
    {
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
    {
        Piles[i + Offset(5)] = noCard;
        Piles[i + Offset(6)] = noCard;
        Piles[i + Offset(7)] = noCard;
        Piles[i + Offset(8)] = noCard;
        Piles[i + Offset(9)] = noCard;
    }
}
void ShuffleCards()
{
    if (startingPlayers >= 1)
    {
        for (int i = 0; i < startingCardsEach; i++)
        {
            DrawCard(5, i);
        }
    }
    if (startingPlayers >= 2)
    {
        for (int i = 0; i < startingCardsEach; i++)
        {
            DrawCard(6, i);
        }
    }
    if (startingPlayers >= 3)
    {
        for (int i = 0; i < startingCardsEach; i++)
        {
            DrawCard(7, i);
        }
    }
    if (startingPlayers == 4)
    {
        for (int i = 0; i < startingCardsEach; i++)
        {
            DrawCard(8, i);
        }
    }
}
void StartGame()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    do
    {
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
                      << '\n';
        }
    } while (((108 - (startingPlayers * startingCardsEach)) < 21) || startingPlayers > 4);
    for (int i = 1; i < startingPlayers + 1; i++)
    {
        stillPlaying[i] = 1;
    }
    CreateCards();
    ShuffleCards();
    DrawCard(9, 0);
}