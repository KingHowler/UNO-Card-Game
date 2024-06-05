#include "main/UNO.cpp"
int main()
{
    char playAgain = 'y';
    while (playAgain = 'y')
    {
        ResetVariables();
        UNO();
        std::cout << "Play Again? [y for yes / anything else for no]";
        std::cin >> playAgain;
        std::cout << '\n';
    }
    return 0;
}