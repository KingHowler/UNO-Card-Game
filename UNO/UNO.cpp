// #pragma once
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
class UNO
{
public:
    Card noCard;
    Card Piles[25 + 25 + 25 + 25 + 8 + 108 + 108 + 108 + 108 + 108];
    int PileCount[10] = {25, 25, 25, 25, 8, 0, 0, 0, 0, 0};
    int stillPlaying[5] = {0, 0, 0, 0, 0};
    int position[5] = {0, 0, 0, 0, 0};
    int playersDone[5] = {0, 0, 0, 0, 0};
    int startingPlayers;
    int startingCardsEach;
    int playsOfCurrentPlayer;
    int orderOfTurns;
    int currentPlayer;
    int indexOfCardToPlay;
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
        for (int i = 1; i < startingPlayers + 1; i++)
        {
            stillPlaying[i] = 1;
        }
        CreateCards();
        ShuffleCards();
        DrawCard(9, 0);
    }
    bool MoveCardToDiscardPile(int index)
    {
        bool success = true;
        bool process = true;
        Card LastDiscard;
        Card cardFromPile;
        if (currentPlayer < 5 || currentPlayer > 0)
        {
            currentPlayer += 4;
            if (index < 0 || index > 107)
            {
                success = false;
                process = false;
            }
            if (process == true)
            {
                LastDiscard = Piles[PileCount[9] + Offset(9) - 1];
                cardFromPile = Piles[index + Offset(currentPlayer)];
                if (playsOfCurrentPlayer == 0 || playsOfCurrentPlayer == -1)
                {
                    if (LastDiscard.Number == cardFromPile.Number || LastDiscard.Colour == cardFromPile.Colour || cardFromPile.Colour == 0 || LastDiscard.Colour == 0)
                    {
                        Piles[PileCount[9] + Offset(9)] = Piles[index + Offset(currentPlayer)];
                        Piles[index + Offset(currentPlayer)] = noCard;
                        PileCount[9] = PileCount[9] + 1;
                        PileCount[currentPlayer] = PileCount[currentPlayer] - 1;
                    }
                    else
                    {
                        success = false;
                    }
                }
                else
                {
                    if (LastDiscard.Number == cardFromPile.Number || LastDiscard.Colour == 0 || cardFromPile.Colour == 0)
                    {
                        Piles[PileCount[9] + Offset(9)] = Piles[index + Offset(currentPlayer)];
                        Piles[index + Offset(currentPlayer)] = noCard;
                        PileCount[9] = PileCount[9] + 1;
                        PileCount[currentPlayer] = PileCount[currentPlayer] - 1;
                    }
                    else
                    {
                        success = false;
                    }
                }
            }
            else
            {
                success = false;
                process = false;
            }
            currentPlayer -= 4;
            if (playsOfCurrentPlayer == -1 && success)
            {
                playsOfCurrentPlayer++;
            }
        }
        return success;
    }
    bool SwitchTurn()
    {
        bool success = false;
        if (playsOfCurrentPlayer > 0)
        {
            success = true;
            playsOfCurrentPlayer = 0;
            do
            {
                currentPlayer += orderOfTurns;
                if (currentPlayer == startingPlayers + 1)
                {
                    currentPlayer = 1;
                }
                if (currentPlayer == 0)
                {
                    currentPlayer = startingPlayers;
                }
            } while (playersDone[currentPlayer] == 1);
        }
        return success;
    }
    int PlayersDoneSum()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += playersDone[i];
        }
        return sum;
    }
    void RefreshPositions()
    {
        for (int i = 1; i < 5; i++)
        {
            if (i <= startingPlayers && PileCount[i + 4] == 0 && playersDone[i] == 0)
            {
                playersDone[i] = 1;
                position[PlayersDoneSum()] = i;
            }
        }
    }
    bool GameEnd()
    {
        bool end = false;
        if (PlayersDoneSum() == startingPlayers - 1)
        {
            end = true;
            for (int i = 1; i < startingPlayers + 1; i++)
            {
                if (playersDone[i] == 0)
                {
                    playersDone[i] = 1;
                    position[PlayersDoneSum()] = i;
                }
            }
        }
        return end;
    }
    void OutputResults()
    {
        std::cout << "Game has ended" << '\n'
                  << '\n';
        for (int i = 1; i < startingPlayers + 1; i++)
        {
            std::cout << "Player " << position[i] << " placed " << i << '\n';
        }
    }
};
