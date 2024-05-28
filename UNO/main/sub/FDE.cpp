#pragma once
#include "slave\memory.cpp"

int FirstPlayer()
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
}

bool MoveCardToDiscardPile(int currentPlayer, int index)
{
    bool success = true;
    bool process = true;
    Card LastDiscard;
    Card cardFromPile;

    if (currentPlayer < 5 || currentPlayer > 0)
    {
        currentPlayer += 4;
    }
    else
    {
        success = false;
        process = false;
    }

    if (process == true)
    {
        LastDiscard = Piles[PileCount[9] + Offset(9) - 1];
        cardFromPile = Piles[index + Offset(currentPlayer)];
        if (playsOfCurrentPlayer = 0)
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
            if (LastDiscard.Number == cardFromPile.Number || LastDiscard.Colour == 0)
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
    return success;
}

bool GameEnd()
{
    int playersStillPlaying = 0;
    int lastPlayerIndex = 0;

    // Count the number of players still playing and find the last active player
    for (int i = 4; i >= 1; i--)
    {
        if (stillPlaying[i] == 1)
        {
            playersStillPlaying++;
            lastPlayerIndex = i;
        }
    }

    // If there is only one player left, the game has ended
    if (playersStillPlaying == 1)
    {
        return true;
    }

    // If more than one player is still playing, the game is not over
    return false;
}

bool SwitchTurn(bool skip)
{
    bool success = false;
    if (playsOfCurrentPlayer > 0)
    {
        success = true;
        playsOfCurrentPlayer = 0;
        if (orderOfTurns == 1)
        {
            do
            {
                currentPlayer++;
                if (currentPlayer == 5)
                {
                    currentPlayer = 1;
                }
            } while (stillPlaying[currentPlayer] != 1);
            if (skip == true)
            {
                do
                {
                    currentPlayer++;
                    if (currentPlayer == 5)
                    {
                        currentPlayer = 1;
                    }
                } while (stillPlaying[currentPlayer] != 1);
            }
        }
        if (orderOfTurns == -1)
        {
            do
            {
                currentPlayer--;
                if (currentPlayer == 0)
                {
                    currentPlayer = 4;
                }
            } while (stillPlaying[currentPlayer] != 1);
            if (skip == true)
            {
                do
                {
                    currentPlayer--;
                    if (currentPlayer == 0)
                    {
                        currentPlayer = 4;
                    }
                } while (stillPlaying[currentPlayer] != 1);
            }
        }
    }
    return success;
}

void FDE()
{
    currentPlayer = FirstPlayer();
    do
    {
        do
        {
            std::cin >> indexOfCardToPlay;
        } while (MoveCardToDiscardPile == false && indexOfCardToPlay != -2 && indexOfCardToPlay != -1);

    } while (GameEnd == false);
}

int main()
{
    bool success = false;
    currentPlayer = 3;
    stillPlaying[1] = 0;
    stillPlaying[2] = 0;
    stillPlaying[3] = 1;
    stillPlaying[4] = 1;
    orderOfTurns = -1;
    playsOfCurrentPlayer = 0;
    success = SwitchTurn(true);

    currentPlayer = 3;
    stillPlaying[1] = 0;
    stillPlaying[2] = 0;
    stillPlaying[3] = 1;
    stillPlaying[4] = 1;
    orderOfTurns = -1;
    playsOfCurrentPlayer = 1;
    success = SwitchTurn(true);

    currentPlayer = 1;
    stillPlaying[1] = 1;
    stillPlaying[2] = 0;
    stillPlaying[3] = 1;
    stillPlaying[4] = 1;
    orderOfTurns = 1;
    playsOfCurrentPlayer = 2;
    success = SwitchTurn(true);

    return 0;
}