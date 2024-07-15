#include "UNO.cpp"
UNO game;
int main()
{
    char playAgain = 'y';
    while (playAgain == 'y')
    {
        game.ResetVariables();
        do
        {
            std::cout << "Enter Number of Players 1-4                    :  ";
            std::cin >> game.startingPlayers;
            std::cout << '\n'
                      << "Enter Number of Cards Each Player should have  :  ";
            std::cin >> game.startingCardsEach;
            std::cout << '\n'
                      << '\n';
            if (((108 - (game.startingPlayers * game.startingCardsEach)) < 21) || game.startingPlayers > 4)
            {
                std::cout << "The number of cards remaining must be atleast 21, please try again" << '\n'
                          << '\n'
                          << '\n';
            }
        } while (((108 - (game.startingPlayers * game.startingCardsEach)) < 21) || game.startingPlayers > 4);
        game.StartGame();
        game.currentPlayer = 1;
        game.orderOfTurns = 1;
        bool validMove;
        int buffCurrentPlayer;
        std::cout << '\n'
                  << '\n';
        game.DisplayCards(5);
        std::cout << '\n'
                  << '\n';
        game.DisplayCards(6);
        std::cout << '\n'
                  << '\n';
        game.DisplayCards(7);
        std::cout << '\n'
                  << '\n';
        game.DisplayCards(8);
        std::cout << '\n'
                  << '\n';
        game.DisplayCards(9);
        std::cout << '\n'
                  << '\n';
        do
        {
            validMove = false;
            do
            {
                std::cout << "Player " << game.currentPlayer << "'s Turn" << '\n'
                          << "Enter the index of the card you want to play  :  ";
                std::cin >> game.indexOfCardToPlay;
                validMove = game.MoveCardToDiscardPile(game.indexOfCardToPlay);
                if (validMove == false && game.indexOfCardToPlay != -2 && game.indexOfCardToPlay != -1)
                {
                    std::cout << "You have entered an invalid index please try again" << '\n'
                              << '\n';
                }
            } while (validMove == false && game.indexOfCardToPlay != -2 && game.indexOfCardToPlay != -1);
            if (game.indexOfCardToPlay == -1)
            {
                game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                std::cout << '\n'
                          << '\n';
                game.DisplayCards(game.currentPlayer + 4);
                std::cout << '\n'
                          << '\n';
                if (game.playsOfCurrentPlayer == 0)
                {
                    game.playsOfCurrentPlayer = -1;
                }
            }
            if (validMove == true)
            {
                game.playsOfCurrentPlayer += 1;
                switch (game.Piles[game.PileCount[9] + game.Offset(9) - 1].Number)
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
                    game.SwitchTurn();
                    game.indexOfCardToPlay = -2;
                    game.playsOfCurrentPlayer = 1;
                    break;
                case 11:
                    game.orderOfTurns -= 2 * game.orderOfTurns;
                    game.indexOfCardToPlay = -2;
                    break;
                case 12:
                    buffCurrentPlayer = game.currentPlayer;
                    game.SwitchTurn();
                    game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                    game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                    game.currentPlayer = buffCurrentPlayer;
                    game.playsOfCurrentPlayer += 1;
                    break;
                case 13:
                    break;
                case 14:
                    buffCurrentPlayer = game.currentPlayer;
                    game.SwitchTurn();
                    game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                    game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                    game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                    game.DrawCard(game.currentPlayer + 4, game.PileCount[game.currentPlayer + 4]);
                    game.currentPlayer = buffCurrentPlayer;
                    game.playsOfCurrentPlayer += 1;
                    break;
                }
            }
            if (game.indexOfCardToPlay == -2)
            {
                if (game.playsOfCurrentPlayer == -1)
                {
                    game.playsOfCurrentPlayer = 1;
                }
                game.SwitchTurn();
                std::cout << '\n'
                          << '\n';
                game.DisplayCards(5);
                std::cout << '\n'
                          << '\n';
                game.DisplayCards(6);
                std::cout << '\n'
                          << '\n';
                game.DisplayCards(7);
                std::cout << '\n'
                          << '\n';
                game.DisplayCards(8);
                std::cout << '\n'
                          << '\n';
                game.DisplayCards(9);
                std::cout << '\n'
                          << '\n';
            }
            game.RefreshPositions();
        } while (game.GameEnd() == false);
        game.OutputResults();
        std::cout << "Play Again? [y for yes / anything else for no]";
        std::cin >> playAgain;
        std::cout << '\n';
    }
    return 0;
}
