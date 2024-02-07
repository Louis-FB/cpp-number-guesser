#include <iostream>

void welcome();
int chooseNumber();
bool checkAnswer(int num);
int generateNumber();

int main()
{
    bool play{true};
    welcome();

    do
    {
        int number{chooseNumber()};
        std::cout << "You chose " << number << '\n';
    } while (play);

    return 0;
}

void welcome()
{
    std::cout << "Welcome to the number guessing game!\n";
    std::cout << "Guess a number between 0 and 100. You have 6 chances!\n";
}

int chooseNumber()
{
    std::cout << "Enter a number 0-100: ";
    int x{};
    std::cin >> x;

    return x;
}