#pragma once
#include "slave\memory.cpp"

/*int FirstPlayer()
{
    for (int i = 1; i < 5; i++)
    {
        if (stillPlaying[i] == 1)
        {
            return i;
        }
    }
}
int LastPlayer()
{
    for (int i = 4; i > 0; i--)
    {
        if (stillPlaying[i] == 1)
        {
            return i;
        }
    }
}*/
void NextPlayer()
{
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
        NextPlayer();
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

void FDE()
{
    currentPlayer = 1;
    orderOfTurns = 1;
    bool validMove;
    int buffCurrentPlayer;

    std::cout << '\n'
              << '\n';
    DisplayCards(5);
    std::cout << '\n'
              << '\n';
    DisplayCards(6);
    std::cout << '\n'
              << '\n';
    DisplayCards(7);
    std::cout << '\n'
              << '\n';
    DisplayCards(8);
    std::cout << '\n'
              << '\n';
    DisplayCards(9);
    std::cout << '\n'
              << '\n';
    do
    {
        validMove = false;
        do
        {
            std::cout << "Player " << currentPlayer << "'s Turn" << '\n'
                      << "Enter the index of the card you want to play  :  ";
            std::cin >> indexOfCardToPlay;
            validMove = MoveCardToDiscardPile(indexOfCardToPlay);
            if (validMove == false && indexOfCardToPlay != -2 && indexOfCardToPlay != -1)
            {
                std::cout << "You have entered an invalid index please try again" << '\n'
                          << '\n';
            }
        } while (validMove == false && indexOfCardToPlay != -2 && indexOfCardToPlay != -1);
        if (indexOfCardToPlay == -1)
        {
            DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
            std::cout << '\n'
                      << '\n';
            DisplayCards(currentPlayer + 4);
            std::cout << '\n'
                      << '\n';
            if (playsOfCurrentPlayer == 0)
            {
                playsOfCurrentPlayer = -1;
            }
        }
        if (validMove == true)
        {
            playsOfCurrentPlayer += 1;
            switch (Piles[PileCount[9] + Offset(9) - 1].Number)
            {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
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
            case 10:
                SwitchTurn();
                indexOfCardToPlay = -2;
                playsOfCurrentPlayer = 1;
                break;
            case 11:
                orderOfTurns -= 2 * orderOfTurns;
                indexOfCardToPlay = -2;
                break;
            case 12:
                buffCurrentPlayer = currentPlayer;
                SwitchTurn();
                DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
                DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
                currentPlayer = buffCurrentPlayer;
                playsOfCurrentPlayer += 1;
                break;
            case 13:
                break;
            case 14:
                buffCurrentPlayer = currentPlayer;
                SwitchTurn();
                DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
                DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
                DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
                DrawCard(currentPlayer + 4, PileCount[currentPlayer + 4]);
                currentPlayer = buffCurrentPlayer;
                playsOfCurrentPlayer += 1;
                break;
            }
        }
        if (indexOfCardToPlay == -2)
        {
            if (playsOfCurrentPlayer == -1)
            {
                playsOfCurrentPlayer = 1;
            }

            SwitchTurn();
            std::cout << '\n'
                      << '\n';
            DisplayCards(5);
            std::cout << '\n'
                      << '\n';
            DisplayCards(6);
            std::cout << '\n'
                      << '\n';
            DisplayCards(7);
            std::cout << '\n'
                      << '\n';
            DisplayCards(8);
            std::cout << '\n'
                      << '\n';
            DisplayCards(9);
            std::cout << '\n'
                      << '\n';
        }
        RefreshPositions();
    } while (GameEnd() == false);
    OutputResults();
}