#include <iostream>
#include "Memory_unit.cpp"
#include "Piles_state.cpp"

bool GameEnd()
{
    for (int i = 5; i < 9; i++)
    {
        if (PileCount[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void OutputResults() {}

bool MoveCard(int player, int index)
{
    bool success = true;
    bool process = true;
    char p;
    switch (player)
    {
    case 1:
        p = '1';
        break;
    case 2:
        p = '2';
        break;
    case 3:
        p = '3';
        break;
    case 4:
        p = '4';
        break;
    default:
        process = false;
        success = false;
        break;
    }
    if (process == true)
    {
        if (Piles[PileCount[9] + Offset('9') - 1].Number == Piles[index + Offset(p)].Number || Piles[PileCount[9] + Offset('9') - 1].Colour == Piles[index + Offset(p)].Colour)
        {
            Piles[PileCount[9] + Offset('9')] = Piles[index + Offset(p)];
            Piles[index + Offset(p)] = noCard;
            PileCount[9] = PileCount[9] + 1;
            PileCount[player + 4] = PileCount[player + 4] - 1;
        }
        else
        {
            success = false;
        }
    }
    return success;
}

void Gameloop()
{
    bool clockwise = true; // order, inverts on reverse card
    int turn = 1;          // counter for which player is about to play
    char p;
    int index; // the index number
    int plays;
    do
    {
        if (clockwise == true)
        {
            do
            {
                if (index == -2 && plays > 0)
                {
                    turn += 1;
                }
                do
                {
                    std::cout << '\n'
                              << "Player No " << turn << "'s Turn" << '\n'
                              << "Enter the index of the card which you wish to play  ";
                    std::cin >> index;
                } while (MoveCard(turn, index) == false && index != -1 && index != -2);
                if (index != -1 && index != -2)
                {
                    plays += 1;
                }
                if (index == -1)
                {
                    switch (turn)
                    {
                    case 1:
                        p = '1';
                        break;
                    case 2:
                        p = '2';
                        break;
                    case 3:
                        p = '3';
                        break;
                    case 4:
                        p = '4';
                        break;
                    default:
                        break;
                    }
                    DrawCard(p, PileCount[turn + 4]);
                    PileCount[turn + 4] = PileCount[turn + 4] + 1;
                    plays += 1;
                }

                DisplayCards('1');
                std::cout << '\n'
                          << '\n';
                DisplayCards('2');
                std::cout << '\n'
                          << '\n';
                DisplayCards('3');
                std::cout << '\n'
                          << '\n';
                DisplayCards('4');
                std::cout << '\n'
                          << '\n';
                DisplayCards('9');
                std::cout << '\n'
                          << '\n';
                if (turn == players)
                {
                    turn = 0;
                }
            } while (Piles[PileCount[9] - 1].Number != 11 || GameEnd() == false);
            clockwise = !clockwise;
        }
        else
        {
            do
            {
                turn -= 1;
                MoveCard(turn, index);
                if (turn == 1)
                {
                    turn = players + 1;
                }
            } while (Piles[PileCount[9] - 1].Number != 11 || GameEnd() == false);
            clockwise = !clockwise;
        }
    } while (GameEnd() == false);

    OutputResults();
    while (true)
    {
    }
}