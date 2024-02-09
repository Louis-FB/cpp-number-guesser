#include <iostream>
#include <cassert>
#include "random.h"
#include <limits>

int makeGuess(int rounds);
bool game();
bool checkAnswer(int randomNumber, int guess);
bool keepPlaying();

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    while (true)
    {
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
        if (!game())
        {

            std::cout << "Thanks for playing!\n";
            return false;
        }
    }

    return 0;
}

bool game()
{
    int randomNumber{Random::get(1, 100)};
    assert(randomNumber > 0 && randomNumber <= 100 && "Incorrect range\n");
    int chances{7};

    for (int rounds{1}; rounds <= chances; rounds++)
    {
        int num{makeGuess(rounds)};
        if (checkAnswer(randomNumber, num))
        {
            std::cout << "Correct! You win!\n";

            return keepPlaying();
        }
    }

    std::cout << "You lost! You ran out of turns.\n";
    return keepPlaying();
}

bool keepPlaying()
{
    while (true)
    {
        std::cout << "Do you want to play again (y/n) ? ";
        char question{};
        std::cin >> question;
        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
        }
        ignoreLine();
        switch (question)
        {
        case 'y':
            return true;

        case 'n':
            return false;

        default:
            std::cout << "Enter a correct input.\n";
            break;
        }
    }
}

int makeGuess(int rounds)
{
    int num{};
    while (true)
    {
        std::cout << "Guess #" << rounds << ": ";
        std::cin >> num;
        if (!std::cin)
        {
            std::cin.clear();
            //  ignoreLine();
        }

        else if (num < 1)
        {
            std::cout << "Number too low! try again\n";
            continue;
        }
        else if (num > 100)
        {
            std::cout << "Number too high! try again.\n";
            continue;
        }
        else
        {
            break;
        }
    }
    ignoreLine();
    return num;
}

bool checkAnswer(int randomNumber, int guess)
{
    if (guess < randomNumber)
    {
        std::cout << "Your guess is too low.\n";
        return false;
    }
    else if (guess > randomNumber)
    {
        std::cout << "Your guess is too high.\n";
        return false;
    }
    else
    {
        return true;
    }
}